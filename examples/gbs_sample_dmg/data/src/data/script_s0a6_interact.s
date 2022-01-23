.module script_s0a6_interact

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_s0a6_interact = 255
.globl ___bank_script_s0a6_interact
.CURRENT_SCRIPT_BANK == ___bank_script_s0a6_interact

_script_s0a6_interact::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "Check out this\nsweet duck!"
        VM_OVERLAY_CLEAR        0, 0, 20, 4, .UI_COLOR_WHITE, ^/(.UI_AUTO_SCROLL | .UI_DRAW_FRAME)/
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Variable Set To True
        VM_SET_CONST            VAR_SEEN_DUCK, 1

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 7

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_DOWN

        ; Stop Script
        VM_STOP
