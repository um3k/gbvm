.module script_s8_init

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255


___bank_script_s8_init = 255
.globl ___bank_script_s8_init

_script_s8_init::
        VM_LOCK

        ; Variable 9 = 10
        VM_RPN
            .R_INT16    10
            .R_STOP
        VM_SET                  VAR_LIVES, .ARG0
        VM_POP                  1

        ; Variable 10 = 3000
        VM_RPN
            .R_INT16    3000
            .R_STOP
        VM_SET                  VAR_SCORE, .ARG0
        VM_POP                  1

        ; Variable 11 = 999
        VM_RPN
            .R_INT16    999
            .R_STOP
        VM_SET                  VAR_TIME, .ARG0
        VM_POP                  1

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Advanced Text Dialogue
        VM_LOAD_TEXT            3
        .dw VAR_LIVES, VAR_SCORE, VAR_TIME
        .asciz "\003\001\001\002\002Lives\002\001x\002\002%d        Time\n    %d         %d"
        VM_OVERLAY_CLEAR        0, 0, 20, 2, .UI_COLOR_WHITE, .UI_AUTO_SCROLL
        VM_OVERLAY_MOVE_TO      0, 16, .OVERLAY_IN_SPEED
        VM_OVERLAY_SET_SCROLL   0, 0, 20, 2, .UI_COLOR_WHITE

        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_NONMODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Variables .SUB Value
        VM_RPN
            .R_REF      VAR_S8_LOCAL_0
            .R_INT8     1
            .R_OPERATOR .SUB
            .R_STOP
        VM_SET                  VAR_S8_LOCAL_0, .ARG0
        VM_POP                  1

        ; Stop Script
        VM_STOP
