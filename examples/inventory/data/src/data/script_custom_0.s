.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255



___bank_script_custom_0 = 255
.globl ___bank_script_custom_0

_script_custom_0::
        ; Text Dialogue
        VM_PUSH_VALUE_IND       ^/(.ARG2)/
        VM_LOAD_TEXT            1
        .dw .ARG0
        .asciz "%d\n"
        VM_POP                  1
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, .UI_DRAW_FRAME
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Variable Decrement By 1
        VM_RPN
            .R_REF_IND  ^/(.ARG2)/
            .R_INT8     1
            .R_OPERATOR .SUB
            .R_STOP
        VM_SET_INDIRECT         ^/(.ARG2 - 1)/, .ARG0
        VM_POP                  1

        VM_RET_FAR
