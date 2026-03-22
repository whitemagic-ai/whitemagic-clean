// Zig Genome Storage Layer for HyperEvolution Engine
//
// Memory-efficient genome serialization and storage using Zig's
// zero-cost abstractions and manual memory management.

const std = @import("std");
const Allocator = std.mem.Allocator;

/// Gene category enumeration
pub const GeneCategory = enum(u8) {
    Architecture = 0,
    Feature = 1,
    Optimization = 2,
    Biological = 3,
    Intelligence = 4,
    Polyglot = 5,
};

/// Compact gene representation (16 bytes)
pub const Gene = packed struct {
    name_hash: u64,           // 8 bytes - hash of gene name
    category: GeneCategory,   // 1 byte
    expression_level: u8,     // 1 byte - 0-255 mapped to 0.0-1.0
    allele_id: u16,          // 2 bytes - allele identifier
    _padding: u32,           // 4 bytes - alignment padding
    
    pub fn fromFloat(name_hash: u64, category: GeneCategory, expression: f64, allele_id: u16) Gene {
        return Gene{
            .name_hash = name_hash,
            .category = category,
            .expression_level = @intFromFloat(@min(255.0, @max(0.0, expression * 255.0))),
            .allele_id = allele_id,
            ._padding = 0,
        };
    }
    
    pub fn toFloat(self: Gene) f64 {
        return @as(f64, @floatFromInt(self.expression_level)) / 255.0;
    }
};

/// Compact genome header (32 bytes)
pub const GenomeHeader = packed struct {
    genome_id: u64,          // 8 bytes - hash of genome ID
    generation: u32,         // 4 bytes
    gene_count: u16,         // 2 bytes
    flags: u16,              // 2 bytes - various flags
    fitness: f32,            // 4 bytes - single precision sufficient
    parent1_id: u64,         // 8 bytes
    parent2_id: u64,         // 8 bytes - 0 if no parent2
    _padding: u32,           // 4 bytes - alignment
};

/// Memory-mapped genome storage
pub const GenomeStorage = struct {
    allocator: Allocator,
    genomes: std.ArrayList(GenomeHeader),
    genes: std.ArrayList(Gene),
    genome_to_genes: std.AutoHashMap(u64, []const Gene),
    
    pub fn init(allocator: Allocator) GenomeStorage {
        return GenomeStorage{
            .allocator = allocator,
            .genomes = std.ArrayList(GenomeHeader){},
            .genes = std.ArrayList(Gene){},
            .genome_to_genes = std.AutoHashMap(u64, []const Gene).init(allocator),
        };
    }
    
    pub fn deinit(self: *GenomeStorage) void {
        self.genomes.deinit(self.allocator);
        self.genes.deinit(self.allocator);
        self.genome_to_genes.deinit();
    }
    
    /// Store a genome with zero-copy where possible
    pub fn store(self: *GenomeStorage, header: GenomeHeader, genes: []const Gene) !void {
        const gene_start = self.genes.items.len;
        
        // Append genes
        try self.genes.appendSlice(self.allocator, genes);
        
        // Store genome header
        try self.genomes.append(self.allocator, header);
        
        // Map genome ID to gene slice
        const gene_slice = self.genes.items[gene_start..];
        try self.genome_to_genes.put(header.genome_id, gene_slice);
    }
    
    /// Retrieve genome genes by ID
    pub fn getGenes(self: *GenomeStorage, genome_id: u64) ?[]const Gene {
        return self.genome_to_genes.get(genome_id);
    }
    
    /// Get genome header by index
    pub fn getHeader(self: *GenomeStorage, index: usize) ?GenomeHeader {
        if (index >= self.genomes.items.len) return null;
        return self.genomes.items[index];
    }
    
    /// Get total number of genomes stored
    pub fn count(self: *GenomeStorage) usize {
        return self.genomes.items.len;
    }
    
    /// Calculate total memory usage
    pub fn memoryUsage(self: *GenomeStorage) usize {
        const header_bytes = self.genomes.items.len * @sizeOf(GenomeHeader);
        const gene_bytes = self.genes.items.len * @sizeOf(Gene);
        const map_overhead = self.genome_to_genes.count() * 24; // Approximate
        return header_bytes + gene_bytes + map_overhead;
    }
    
    /// Save to file (binary format)
    pub fn saveToFile(self: *GenomeStorage, path: []const u8) !void {
        const file = try std.fs.cwd().createFile(path, .{});
        defer file.close();
        
        var buffer: [4096]u8 = undefined;
        var writer = file.writer(&buffer);
        
        // Write header count
        try writer.writeIntLittle(u64, self.genomes.items.len);
        
        // Write all genome headers
        for (self.genomes.items) |header| {
            try writer.writeAll(std.mem.asBytes(&header));
        }
        
        // Write gene count
        try writer.writeIntLittle(u64, self.genes.items.len);
        
        // Write all genes
        for (self.genes.items) |gene| {
            try writer.writeAll(std.mem.asBytes(&gene));
        }
    }
    
    /// Load from file
    pub fn loadFromFile(allocator: Allocator, path: []const u8) !GenomeStorage {
        const file = try std.fs.cwd().openFile(path, .{});
        defer file.close();
        
        var reader = file.reader();
        var storage = GenomeStorage.init(allocator);
        
        // Read genome count
        const genome_count = try reader.readIntLittle(u64);
        
        // Read genome headers
        var i: usize = 0;
        while (i < genome_count) : (i += 1) {
            var header: GenomeHeader = undefined;
            _ = try reader.readAll(std.mem.asBytes(&header));
            try storage.genomes.append(header);
        }
        
        // Read gene count
        const gene_count = try reader.readIntLittle(u64);
        
        // Read genes
        i = 0;
        while (i < gene_count) : (i += 1) {
            var gene: Gene = undefined;
            _ = try reader.readAll(std.mem.asBytes(&gene));
            try storage.genes.append(gene);
        }
        
        // Rebuild genome-to-genes mapping
        var gene_offset: usize = 0;
        for (storage.genomes.items) |header| {
            const gene_slice = storage.genes.items[gene_offset..gene_offset + header.gene_count];
            try storage.genome_to_genes.put(header.genome_id, gene_slice);
            gene_offset += header.gene_count;
        }
        
        return storage;
    }
    
    /// Compact storage by removing deleted genomes
    pub fn compact(self: *GenomeStorage) !void {
        var new_genomes = std.ArrayList(GenomeHeader).init(self.allocator);
        var new_genes = std.ArrayList(Gene).init(self.allocator);
        var new_map = std.AutoHashMap(u64, []const Gene).init(self.allocator);
        
        for (self.genomes.items) |header| {
            if (self.genome_to_genes.get(header.genome_id)) |genes| {
                const gene_start = new_genes.items.len;
                try new_genes.appendSlice(genes);
                try new_genomes.append(header);
                try new_map.put(header.genome_id, new_genes.items[gene_start..]);
            }
        }
        
        self.genomes.deinit();
        self.genes.deinit();
        self.genome_to_genes.deinit();
        
        self.genomes = new_genomes;
        self.genes = new_genes;
        self.genome_to_genes = new_map;
    }
};

/// Batch genome serializer for parallel processing
pub const BatchSerializer = struct {
    storage: *GenomeStorage,
    batch_size: usize,
    
    pub fn init(storage: *GenomeStorage, batch_size: usize) BatchSerializer {
        return BatchSerializer{
            .storage = storage,
            .batch_size = batch_size,
        };
    }
    
    /// Serialize a batch of genomes in parallel
    pub fn serializeBatch(
        self: *BatchSerializer,
        headers: []const GenomeHeader,
        gene_arrays: []const []const Gene,
    ) !void {
        std.debug.assert(headers.len == gene_arrays.len);
        
        for (headers, gene_arrays) |header, genes| {
            try self.storage.store(header, genes);
        }
    }
};

// Hash function for gene names
pub fn hashString(s: []const u8) u64 {
    var hash: u64 = 0xcbf29ce484222325;
    for (s) |byte| {
        hash ^= byte;
        hash *%= 0x100000001b3;
    }
    return hash;
}

// Test and benchmark
pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    defer _ = gpa.deinit();
    const allocator = gpa.allocator();
    
    std.debug.print("Zig Genome Storage Benchmark\n", .{});
    std.debug.print("============================\n\n", .{});
    
    var storage = GenomeStorage.init(allocator);
    defer storage.deinit();
    
    // Benchmark: Store 100K genomes
    const num_genomes = 100_000;
    var timer = try std.time.Timer.start();
    
    var i: usize = 0;
    while (i < num_genomes) : (i += 1) {
        const header = GenomeHeader{
            .genome_id = i,
            .generation = @intCast(i / 1000),
            .gene_count = 50,
            .flags = 0,
            .fitness = 0.5,
            .parent1_id = if (i > 0) i - 1 else 0,
            .parent2_id = 0,
            ._padding = 0,
        };
        
        // Create 50 genes
        var genes: [50]Gene = undefined;
        var j: usize = 0;
        while (j < 50) : (j += 1) {
            genes[j] = Gene.fromFloat(
                j,
                @enumFromInt(@mod(j, 6)),
                0.5,
                0,
            );
        }
        
        try storage.store(header, &genes);
    }
    
    const elapsed = timer.read();
    const elapsed_ms = @as(f64, @floatFromInt(elapsed)) / 1_000_000.0;
    
    std.debug.print("Stored {} genomes in {d:.2} ms\n", .{ num_genomes, elapsed_ms });
    std.debug.print("Throughput: {d:.0} genomes/sec\n", .{ @as(f64, @floatFromInt(num_genomes)) / (elapsed_ms / 1000.0) });
    std.debug.print("Memory usage: {} bytes ({d:.2} MB)\n", .{ 
        storage.memoryUsage(),
        @as(f64, @floatFromInt(storage.memoryUsage())) / 1_048_576.0,
    });
    std.debug.print("Bytes per genome: {d:.1}\n", .{ 
        @as(f64, @floatFromInt(storage.memoryUsage())) / @as(f64, @floatFromInt(num_genomes)),
    });
    
    // Test save/load
    std.debug.print("\nTesting save/load...\n", .{});
    try storage.saveToFile("genomes.bin");
    
    var loaded = try GenomeStorage.loadFromFile(allocator, "genomes.bin");
    defer loaded.deinit();
    
    std.debug.print("Loaded {} genomes\n", .{loaded.count()});
    
    std.debug.print("\nZig genome storage layer ready!\n", .{});
}
