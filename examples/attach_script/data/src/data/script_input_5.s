.module script_input_5

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255


___bank_script_input_5 = 255
.globl ___bank_script_input_5

_script_input_5::
        VM_IDLE

        ; If Input
        VM_PUSH_CONST           0
        VM_GET_INT8             .ARG0, ^/(_joypads + 1)/
        VM_RPN
            .R_REF      .ARG0
            .R_INT8     12
            .R_OPERATOR .B_AND
            .R_STOP
        VM_IF_CONST .NE         .ARG0, 0, 1$, 2
        VM_JUMP                 2$
1$:
        ; If Input
        VM_PUSH_CONST           0
        VM_GET_INT8             .ARG0, ^/(_joypads + 1)/
        VM_RPN
            .R_REF      .ARG0
            .R_INT8     48
            .R_OPERATOR .B_AND
            .R_STOP
        VM_IF_CONST .NE         .ARG0, 0, 3$, 2
        VM_JUMP                 4$
3$:
        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "test"
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

4$:

2$:

        ; Stop Script
        VM_STOP
