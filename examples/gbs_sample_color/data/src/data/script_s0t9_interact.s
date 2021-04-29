.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_s0t9_interact = 255
.globl ___bank_script_s0t9_interact

_script_s0t9_interact::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; If Variable True
        VM_IF_CONST .GT         VAR_QUEST11, 0, 1$, 0
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 8
        VM_ACTOR_ACTIVATE       ACTOR

        ; If Actor At Position
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    6016
            .R_OPERATOR .EQ
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    3200
            .R_OPERATOR .EQ
            .R_OPERATOR .AND
            .R_STOP
        VM_IF_CONST .EQ         .ARG0, 0, 3$, 1
        VM_JUMP                 4$
3$:
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 8
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Set Direction
        VM_ACTOR_SET_DIR        ACTOR, .DIR_UP

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 8
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 8
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Move To
        VM_SET_CONST            ^/(ACTOR + 1)/, 5376
        VM_SET_CONST            ^/(ACTOR + 2)/, 3840
        VM_SET_CONST            ^/(ACTOR + 3)/, 0
        VM_ACTOR_MOVE_TO        ACTOR

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 8
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Move To
        VM_SET_CONST            ^/(ACTOR + 1)/, 6016
        VM_SET_CONST            ^/(ACTOR + 2)/, 3200
        VM_SET_CONST            ^/(ACTOR + 3)/, ^/(.ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        ACTOR

4$:

        VM_JUMP                 2$
1$:
2$:

        ; Stop Script
        VM_STOP
