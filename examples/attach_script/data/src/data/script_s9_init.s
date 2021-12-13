.module script_s9_init

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255


___bank_script_s9_init = 255
.globl ___bank_script_s9_init

_script_s9_init::
        VM_LOCK

        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_OVERLAY_CLEAR        0, 0, 20, 2, .UI_COLOR_BLACK, 0
        VM_OVERLAY_SHOW         0, 14, .UI_COLOR_WHITE, 0
        
        VM_SET_CONST_INT8       _text_draw_speed, 0

        ; Variable Set To False
        VM_SET_CONST            VAR_VARIABLE_2, 0

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Timer Start
        VM_TIMER_PREPARE        1, ___bank_script_timer_1, _script_timer_1
        VM_TIMER_SET            1, 1

        ; Stop Script
        VM_STOP
