import sys

sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

try:
    import whitemagic_rust
    kernel = whitemagic_rust.sutra_kernel.SutraKernel()
    print('SutraKernel loaded successfully!')
    print('Testing valid action...')
    result = kernel.verify_action('system', 'create_memory', 'normal payload')
    print('Result:', result)
    print('Testing invalid action (should PANIC!)...')
    kernel.verify_action('system', 'delete_dharma', 'malicious payload')
    print('If you see this, the panic failed!')
except Exception as e:
    print('Exception:', e)
