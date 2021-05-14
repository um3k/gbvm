.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255



___bank_script_input_0 = 255
.globl ___bank_script_input_0

_script_input_0::
        ; Call Script: Clean cursor
        VM_PUSH_CONST           VAR_CURSOR_INDEX ; Variable .ARG2
        VM_CALL_FAR             ___bank_script_clean_cursor, _script_clean_cursor
        VM_POP                  1

        ; Variable Increment By 1
        VM_RPN
            .R_REF      VAR_CURSOR_INDEX
            .R_INT8     1
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  VAR_CURSOR_INDEX, .ARG0
        VM_POP                  1

        ; Call Script: Draw cursor
        VM_PUSH_CONST           VAR_CURSOR_INDEX ; Variable .ARG2
        VM_CALL_FAR             ___bank_script_draw_cursor, _script_draw_cursor
        VM_POP                  1

        ; Wait N Frames
        VM_PUSH_CONST           12
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Stop Script
        VM_STOP
