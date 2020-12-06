.include "vm.inc"
        
.globl b_wait_frames, _wait_frames

.area _CODE_3

___bank_SCRIPT_1 = 3
.globl ___bank_SCRIPT_1

_SCRIPT_1::
1$:
        VM_DEBUG        0
        .asciz "Hello World"
        VM_DEBUG        0
        .asciz "Hello 1"
        VM_IDLE
        VM_JUMP     1$        
        VM_STOP
