.module script_s4a0_update

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255


___bank_script_s4a0_update = 255
.globl ___bank_script_s4a0_update

_script_s4a0_update::
2$:
        ; Wait N Frames
        VM_PUSH_CONST           6
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Set player field to variable
        VM_GET_INT16 VAR_VEL_Y, _pl_vel_y

        ; Set player field to variable
        VM_GET_INT16 VAR_VEL_X, _pl_vel_x

        ; Set player field to variable
        VM_GET_UINT8 VAR_GROUNDED, _grounded

        ; Set player field to variable
        VM_GET_UINT8 VAR_ON_LADDER, _on_ladder

        VM_LOAD_TEXT            4
            .dw VAR_VEL_X, VAR_GROUNDED, VAR_VEL_Y, VAR_ON_LADDER
            .asciz "\002\001VX:%D6 GROUND:%D1\nVY:%D6 LADDER:%D1"
        ;VM_DISPLAY_TEXT

        VM_DISPLAY_TEXT

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        VM_JUMP                 2$
        ; Stop Script
        VM_STOP
