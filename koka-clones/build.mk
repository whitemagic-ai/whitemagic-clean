# KOKA VC-8: Build System
# Makefile for Koka compilation and FFI

KOKA := koka
KOKA_FLAGS := --target=c --optimize
BUILD_DIR := dist
SRC_DIR := .

.PHONY: all clean install

all: $(BUILD_DIR)/whitemagic_koka.a

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/whitemagic_koka.a: $(BUILD_DIR)
	@echo "Compiling Koka modules..."
	$(KOKA) $(KOKA_FLAGS) --output=$(BUILD_DIR)/c grimoire/effect_handlers.kk
	$(KOKA) $(KOKA_FLAGS) --output=$(BUILD_DIR)/c unified_api.kk
	$(KOKA) $(KOKA_FLAGS) --output=$(BUILD_DIR)/c dharma_rules.kk
	$(KOKA) $(KOKA_FLAGS) --output=$(BUILD_DIR)/c session_startup.kk
	$(KOKA) $(KOKA_FLAGS) --output=$(BUILD_DIR)/c mcp_lean.kk
	$(KOKA) $(KOKA FLAGS) --output=$(BUILD_DIR)/c gnosis_tools.kk
	$(KOKA) $(KOKA_FLAGS) --output=$(BUILD_DIR)/c dispatch_table.kk
	$(KOKA) $(KOKA_FLAGS) --output=$(BUILD_DIR)/c ffi/python_bridge.kk
	@echo "Building static library..."
	cd $(BUILD_DIR)/c && gcc -c *.c -I. -O3
	cd $(BUILD_DIR)/c && ar rcs ../whitemagic_koka.a *.o
	@echo "✅ Build complete: $(BUILD_DIR)/whitemagic_koka.a"

clean:
	rm -rf $(BUILD_DIR)

install: $(BUILD_DIR)/whitemagic_koka.a
	@echo "Installing Koka library..."
	install -d $(DESTDIR)/usr/local/lib
	install -m 644 $(BUILD_DIR)/whitemagic_koka.a $(DESTDIR)/usr/local/lib/
	install -d $(DESTDIR)/usr/local/include/whitemagic
	install -m 644 $(BUILD_DIR)/c/*.h $(DESTDIR)/usr/local/include/whitemagic/

test: all
	@echo "Running Koka tests..."
	$(KOKA) --run ffi/python_bridge.kk

.DEFAULT_GOAL := all
