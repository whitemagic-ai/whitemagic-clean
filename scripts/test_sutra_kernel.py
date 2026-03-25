import sys
sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

try:
    from whitemagic_rust.sutra_kernel import SutraKernel
    kernel = SutraKernel()
    print('SutraKernel loaded successfully from whitemagic_rust')
    print('Testing valid action...')
    result = kernel.verify_action('system', 'create_memory', 'normal payload')
    print('Result:', result)
    print('Testing invalid action...')
    # This should panic!
    kernel.verify_action('system', 'delete_dharma', 'malicious payload')
except Exception as e:
    print('Exception:', e)
