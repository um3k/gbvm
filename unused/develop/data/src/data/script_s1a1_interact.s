.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_s1a1_interact = 255
.globl ___bank_script_s1a1_interact

_script_s1a1_interact::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2
        VM_ACTOR_ACTIVATE       ACTOR

        ; If Actor At Position
        ; NOT IMPLEMENTED - JUMPING TO FALSE PATH
        VM_JUMP                 1$
        VM_JUMP                 2$
1$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Push
        VM_SET_CONST            ACTOR, 0
        VM_PUSH_CONST           3
        VM_ACTOR_GET_DIR        ^/(ACTOR - 1)/, .ARG0
        VM_SET_CONST            ^/(ACTOR - 1)/, 2
        VM_ACTOR_GET_POS        ^/(ACTOR - 1)/
        VM_IF_CONST .EQ         .ARG0, .DIR_UP, 3$, 0
        VM_IF_CONST .EQ         .ARG0, .DIR_LEFT, 4$, 0
        VM_IF_CONST .EQ         .ARG0, .DIR_RIGHT, 5$, 0
        VM_RPN
            .R_REF      ^/(ACTOR + 2 - 1)/
            .R_INT16    12800
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  ^/(ACTOR + 2 - 2)/, .ARG0
        VM_POP                  1
        VM_JUMP                 6$
3$:
        VM_RPN
            .R_REF      ^/(ACTOR + 2 - 1)/
            .R_INT16    12800
            .R_OPERATOR .SUB
            .R_INT16    0
            .R_OPERATOR .MAX
            .R_STOP
        VM_SET                  ^/(ACTOR + 2 - 2)/, .ARG0
        VM_POP                  1
        VM_JUMP                 6$
4$:
        VM_RPN
            .R_REF      ^/(ACTOR + 1 - 1)/
            .R_INT16    12800
            .R_OPERATOR .SUB
            .R_INT16    0
            .R_OPERATOR .MAX
            .R_STOP
        VM_SET                  ^/(ACTOR + 1 - 2)/, .ARG0
        VM_POP                  1
        VM_JUMP                 6$
5$:
        VM_RPN
            .R_REF      ^/(ACTOR + 1 - 1)/
            .R_INT16    12800
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  ^/(ACTOR + 1 - 2)/, .ARG0
        VM_POP                  1
6$:
        VM_POP                  1
        VM_SET_CONST            ^/(ACTOR + 3)/, .ACTOR_ATTR_CHECK_COLL
        VM_ACTOR_MOVE_TO        ACTOR

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2
        VM_ACTOR_ACTIVATE       ACTOR

        ; If Actor At Position
        ; NOT IMPLEMENTED - JUMPING TO FALSE PATH
        VM_JUMP                 7$
        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "Success!"
        VM_OVERLAY_CLEAR        0, 0, 20, 3, .UI_COLOR_WHITE, .UI_DRAW_FRAME
        VM_OVERLAY_MOVE_TO      0, 15, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Variable Set To True
        VM_SET_CONST            VAR_QUEST2, 1

        VM_JUMP                 8$
7$:
8$:

2$:

        ; Variable Set To True
        VM_SET_CONST            VAR_PUSHED_ICE_BLOCK, 1

        ; Stop Script
        VM_STOP
