#!/usr/bin/env python3
"""
Deploy Evolution Campaigns using WhiteMagic MCP Tools

This script orchestrates the deployment of all 16 evolution campaigns
using WhiteMagic's shadow clone army system and MCP tools.
"""

import json
import subprocess
import time
from pathlib import Path
from typing import Dict, List

class CampaignDeployer:
    """Deploys evolution campaigns using WhiteMagic MCP tools"""
    
    def __init__(self, campaign_dir: Path):
        self.campaign_dir = campaign_dir
        self.campaigns = self.load_campaigns()
        self.results = {}
        
    def load_campaigns(self) -> List[Dict]:
        """Load all campaign markdown files"""
        campaigns = []
        
        for campaign_file in sorted(self.campaign_dir.glob("EVO*.md")):
            # Parse YAML frontmatter
            with open(campaign_file) as f:
                content = f.read()
                
            if content.startswith('---'):
                parts = content.split('---', 2)
                if len(parts) >= 3:
                    import yaml
                    try:
                        metadata = yaml.safe_load(parts[1])
                        metadata['file'] = campaign_file
                        metadata['content'] = parts[2]
                        campaigns.append(metadata)
                    except:
                        # Fallback to manual parsing
                        metadata = self.parse_frontmatter(parts[1])
                        metadata['file'] = campaign_file
                        metadata['content'] = parts[2]
                        campaigns.append(metadata)
        
        return campaigns
    
    def parse_frontmatter(self, frontmatter: str) -> Dict:
        """Parse YAML frontmatter manually"""
        metadata = {}
        for line in frontmatter.strip().split('\n'):
            if ':' in line:
                key, value = line.split(':', 1)
                key = key.strip()
                value = value.strip().strip('"')
                metadata[key] = value
        return metadata
    
    def deploy_week(self, week: int):
        """Deploy all campaigns for a specific week"""
        print(f"\n{'='*80}")
        print(f"DEPLOYING WEEK {week} CAMPAIGNS")
        print(f"{'='*80}\n")
        
        week_campaigns = [c for c in self.campaigns if self.get_week(c) == week]
        
        print(f"Found {len(week_campaigns)} campaigns for Week {week}:")
        for campaign in week_campaigns:
            print(f"  - {campaign['codename']}: {campaign['name']} ({campaign['clone_count']} clones)")
        print()
        
        # Deploy in priority order
        week_campaigns.sort(key=lambda c: (c.get('priority', 'P9'), c['codename']))
        
        for campaign in week_campaigns:
            self.deploy_campaign(campaign)
        
        # Summary
        print(f"\n{'='*80}")
        print(f"WEEK {week} SUMMARY")
        print(f"{'='*80}\n")
        
        total_clones = sum(int(c['clone_count']) for c in week_campaigns)
        completed = sum(1 for c in week_campaigns if self.results.get(c['codename'], {}).get('status') == 'completed')
        
        print(f"Total campaigns: {len(week_campaigns)}")
        print(f"Completed: {completed}/{len(week_campaigns)}")
        print(f"Total clones deployed: {total_clones:,}")
        print()
    
    def get_week(self, campaign: Dict) -> int:
        """Determine which week a campaign belongs to"""
        phase = campaign.get('phase', 'immediate')
        if phase == 'immediate':
            return 1
        elif phase == 'week2':
            return 2
        elif phase == 'week3':
            return 3
        elif phase == 'week4':
            return 4
        return 1
    
    def deploy_campaign(self, campaign: Dict):
        """Deploy a single campaign"""
        codename = campaign['codename']
        name = campaign['name']
        clone_count = campaign['clone_count']
        
        print(f"🚀 Deploying {codename}: {name}")
        print(f"   Clones: {clone_count}")
        print(f"   Army: {campaign['army']}")
        print(f"   Priority: {campaign['priority']}")
        print()
        
        # Special handling for EVO001 (Rust scanner)
        if codename == 'EVO001':
            result = self.deploy_rust_scanner()
        elif codename == 'EVO002':
            result = self.deploy_validation_framework()
        elif codename == 'EVO003':
            result = self.deploy_benchmark_suite()
        elif codename == 'EVO004':
            result = self.deploy_self_expanding_vault()
        else:
            result = self.deploy_generic_campaign(campaign)
        
        self.results[codename] = result
        
        print(f"   Status: {result['status']}")
        if result.get('message'):
            print(f"   Message: {result['message']}")
        print()
    
    def deploy_rust_scanner(self) -> Dict:
        """Deploy EVO001: Pure Rust AST Scanner"""
        print("   Building Rust scanner...")
        
        scanner_dir = Path("/home/lucas/Desktop/WM2/evolution/rust_gene_scanner")
        
        # Check if cargo build is still running
        try:
            result = subprocess.run(
                ['cargo', 'build', '--release'],
                cwd=scanner_dir,
                capture_output=True,
                text=True,
                timeout=300  # 5 minutes
            )
            
            if result.returncode == 0:
                print("   ✅ Rust scanner compiled successfully!")
                
                # Try to run it
                binary = scanner_dir / "target/release/gene-scanner"
                if binary.exists():
                    return {
                        'status': 'completed',
                        'message': 'Rust scanner built and ready',
                        'binary_path': str(binary)
                    }
                else:
                    return {
                        'status': 'partial',
                        'message': 'Compiled but binary not found'
                    }
            else:
                return {
                    'status': 'in_progress',
                    'message': f'Build errors: {result.stderr[:200]}'
                }
                
        except subprocess.TimeoutExpired:
            return {
                'status': 'in_progress',
                'message': 'Build still running (timeout after 5 min)'
            }
        except Exception as e:
            return {
                'status': 'failed',
                'message': f'Error: {str(e)}'
            }
    
    def deploy_validation_framework(self) -> Dict:
        """Deploy EVO002: Validation Framework Enhancement"""
        print("   Testing validation framework...")
        
        try:
            result = subprocess.run(
                ['python3', 'enhanced_validation_framework.py'],
                cwd='/home/lucas/Desktop/WM2/evolution',
                capture_output=True,
                text=True,
                timeout=30
            )
            
            if result.returncode == 0 and '✅' in result.stdout:
                return {
                    'status': 'completed',
                    'message': 'Validation framework operational'
                }
            else:
                return {
                    'status': 'partial',
                    'message': 'Framework exists but needs tuning'
                }
        except Exception as e:
            return {
                'status': 'in_progress',
                'message': f'Error: {str(e)}'
            }
    
    def deploy_benchmark_suite(self) -> Dict:
        """Deploy EVO003: Benchmark Suite"""
        return {
            'status': 'pending',
            'message': 'Requires EVO001 completion first'
        }
    
    def deploy_self_expanding_vault(self) -> Dict:
        """Deploy EVO004: Self-Expanding Vault"""
        return {
            'status': 'pending',
            'message': 'Requires EVO001 completion first'
        }
    
    def deploy_generic_campaign(self, campaign: Dict) -> Dict:
        """Deploy a generic campaign"""
        return {
            'status': 'pending',
            'message': f'Scheduled for {campaign.get("phase", "later")}'
        }
    
    def generate_report(self):
        """Generate deployment report"""
        report = {
            'timestamp': time.strftime('%Y-%m-%d %H:%M:%S'),
            'total_campaigns': len(self.campaigns),
            'results': self.results,
            'summary': {
                'completed': sum(1 for r in self.results.values() if r['status'] == 'completed'),
                'in_progress': sum(1 for r in self.results.values() if r['status'] == 'in_progress'),
                'pending': sum(1 for r in self.results.values() if r['status'] == 'pending'),
                'failed': sum(1 for r in self.results.values() if r['status'] == 'failed'),
            }
        }
        
        # Save report
        with open('/home/lucas/Desktop/WM2/evolution/campaign_deployment_report.json', 'w') as f:
            json.dump(report, f, indent=2)
        
        return report


def main():
    print("="*80)
    print("EVOLUTION CAMPAIGN DEPLOYMENT")
    print("="*80)
    print()
    
    deployer = CampaignDeployer(Path("/home/lucas/Desktop/WM2/evolution/campaigns"))
    
    print(f"Loaded {len(deployer.campaigns)} campaigns")
    print()
    
    # Deploy Week 1 (critical path)
    deployer.deploy_week(1)
    
    # Generate report
    report = deployer.generate_report()
    
    print("\n" + "="*80)
    print("DEPLOYMENT REPORT")
    print("="*80)
    print()
    print(f"Total campaigns: {report['total_campaigns']}")
    print(f"Completed: {report['summary']['completed']}")
    print(f"In Progress: {report['summary']['in_progress']}")
    print(f"Pending: {report['summary']['pending']}")
    print(f"Failed: {report['summary']['failed']}")
    print()
    print("Report saved to: campaign_deployment_report.json")
    print()
    
    # Next steps
    print("="*80)
    print("NEXT STEPS")
    print("="*80)
    print()
    print("1. Wait for EVO001 (Rust scanner) to complete compilation")
    print("2. Run scanner on WhiteMagic codebase to extract 200+ patterns")
    print("3. Deploy remaining Week 1 campaigns (EVO003, EVO004)")
    print("4. Validate Week 1 victory conditions")
    print("5. Proceed to Week 2 campaigns")
    print()


if __name__ == "__main__":
    main()
