.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_s10t1_interact = 255
.globl ___bank_script_s10t1_interact

_script_s10t1_interact::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; If Variable True
        VM_IF_CONST .GT         VAR_S10T1_LOCAL_0, 0, 1$, 0
        ; Variable Set To True
        VM_SET_CONST            VAR_S10T1_LOCAL_0, 1

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 3

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_LEFT

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 3

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "\001\002PLEASE\001\005 \001\002HELP!!\001\004\nMy garden..."
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, .UI_DRAW_FRAME
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        VM_JUMP                 2$
1$:
2$:

        ; Stop Script
        VM_STOP
