.module script_s4_init

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255


___bank_script_s4_init = 255
.globl ___bank_script_s4_init

_script_s4_init::
        VM_LOCK

        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_OVERLAY_CLEAR        0, 0, 20, 2, .UI_COLOR_BLACK, 0
        VM_OVERLAY_SHOW         0, 14, .UI_COLOR_WHITE, 0
        
        VM_SET_CONST_INT8       _text_draw_speed, 0

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Stop Script
        VM_STOP
