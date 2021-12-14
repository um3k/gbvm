.module script_input_0

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255


___bank_script_input_0 = 255
.globl ___bank_script_input_0

.globl _pl_vel_y
.globl _grounded

_script_input_0::

        VM_PUSH_CONST           0
        VM_GET_UINT8            .ARG0, _grounded

        VM_IF_CONST             .EQ, .ARG0, 0, 1$, 1  

;        pl_vel_y = -plat_jump_vel;
        VM_SET_CONST_INT16      _pl_vel_y, -16384
        
;        grounded = FALSE;
        VM_SET_CONST_UINT8      _grounded, 0

1$:
        ; Stop Script
        VM_STOP
