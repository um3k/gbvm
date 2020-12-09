.include "vm.inc"
        
.globl b_wait_frames, _wait_frames

.area _CODE_4

___bank_SCRIPT_2 = 4
.globl ___bank_SCRIPT_2

_SCRIPT_2::
        VM_DEBUG        0
        .asciz "Second Script"
        VM_DEBUG        0
        .asciz "Second 1"      
1$:
        VM_DEBUG        0
        .asciz "Second 2"
        VM_IDLE
        VM_JUMP     1$
        VM_STOP
