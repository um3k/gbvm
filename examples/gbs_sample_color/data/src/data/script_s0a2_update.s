.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_s0a2_update = 255
.globl ___bank_script_s0a2_update

_script_s0a2_update::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

1$:
        ; Wait N Frames
        VM_PUSH_CONST           60
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Variable Set To Random
        VM_RANDOMIZE
        VM_RAND                 VAR_TEMP_0, 0, 6

        ; Switch Variable
        ; case 1:
        VM_IF_CONST .NE         VAR_TEMP_0, 1, 2$, 0
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 3
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Move Relative
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    0
            .R_OPERATOR .ADD
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    256
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  ^/(ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_SET_CONST            ^/(ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL)/
        VM_ACTOR_MOVE_TO        ACTOR

        VM_JUMP                 6$
2$:
        ; case 2:
        VM_IF_CONST .NE         VAR_TEMP_0, 2, 3$, 0
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 3
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Move Relative
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    0
            .R_OPERATOR .ADD
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    -256
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  ^/(ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_SET_CONST            ^/(ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL)/
        VM_ACTOR_MOVE_TO        ACTOR

        VM_JUMP                 6$
3$:
        ; case 3:
        VM_IF_CONST .NE         VAR_TEMP_0, 3, 4$, 0
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 3
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Move Relative
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    -256
            .R_OPERATOR .ADD
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    0
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  ^/(ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_SET_CONST            ^/(ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL)/
        VM_ACTOR_MOVE_TO        ACTOR

        VM_JUMP                 6$
4$:
        ; case 4:
        VM_IF_CONST .NE         VAR_TEMP_0, 4, 5$, 0
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 3
        VM_ACTOR_ACTIVATE       ACTOR

        ; Actor Move Relative
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    256
            .R_OPERATOR .ADD
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    0
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  ^/(ACTOR + 1 - 2)/, .ARG1
        VM_SET                  ^/(ACTOR + 2 - 2)/, .ARG0
        VM_POP                  2
        VM_SET_CONST            ^/(ACTOR + 3)/, ^/(.ACTOR_ATTR_CHECK_COLL)/
        VM_ACTOR_MOVE_TO        ACTOR

        VM_JUMP                 6$
5$:
        ; default:
        ; Wait N Frames
        VM_PUSH_CONST           30
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

6$:

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        VM_JUMP                 1$
        ; Stop Script
        VM_STOP
