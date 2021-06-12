.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

___bank_script_s3a0_interact = 255
.globl ___bank_script_s3a0_interact

_script_s3a0_interact::
        VM_LOCK

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "How did you\nget here!?!?"
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Variable Increment By 1
        VM_RPN
            .R_REF      VAR_SPOKE_TO_SPACE_DOG
            .R_INT8     1
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  VAR_SPOKE_TO_SPACE_DOG, .ARG0
        VM_POP                  1

        ; If Variable .EQ Value
        VM_IF_CONST .EQ         VAR_SPOKE_TO_SPACE_DOG, 1, 1$, 0
        ; Text Dialogue
        VM_LOAD_TEXT            1
        .dw VAR_SPOKE_TO_SPACE_DOG
        .asciz "You have spoken to\nme %d times."
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        VM_JUMP                 2$
1$:
        ; Text Dialogue
        VM_LOAD_TEXT            1
        .dw VAR_SPOKE_TO_SPACE_DOG
        .asciz "You have spoken to\nme %d time."
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

2$:

        ; Variable Set To True
        VM_SET_CONST            VAR_QUEST6, 1

        ; Stop Script
        VM_STOP
