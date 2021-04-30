.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_s10_init = 255
.globl ___bank_script_s10_init

_script_s10_init::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Call Script: Turnip Init
        VM_PUSH_CONST           2 ; Actor .ARG3
        VM_PUSH_CONST           VAR_S10A10_DEFEATED ; Variable .ARG2
        VM_CALL_FAR             ___bank_script_custom_8, _script_custom_8
        VM_POP                  2

        ; Call Script: Turnip Init
        VM_PUSH_CONST           4 ; Actor .ARG3
        VM_PUSH_CONST           VAR_S10A10_DEFEATED_1 ; Variable .ARG2
        VM_CALL_FAR             ___bank_script_custom_8, _script_custom_8
        VM_POP                  2

        ; Call Script: Turnip Init
        VM_PUSH_CONST           5 ; Actor .ARG3
        VM_PUSH_CONST           VAR_S10A10_DEFEATED_2 ; Variable .ARG2
        VM_CALL_FAR             ___bank_script_custom_8, _script_custom_8
        VM_POP                  2

        ; Call Script: Init Menu
        VM_CALL_FAR             ___bank_script_custom_0, _script_custom_0

        ; Music Play
        VM_MUSIC_PLAY           ___bank_music_track_4__Data, _music_track_4__Data, .MUSIC_LOOP

        ; Variable Set To Value
        VM_SET_CONST            VAR_TURNIP_COUNTER, 3

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2
        VM_ACTOR_ACTIVATE       ACTOR

        ; If Actor At Position
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    0
            .R_OPERATOR .EQ
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    0
            .R_OPERATOR .EQ
            .R_OPERATOR .AND
            .R_STOP
        VM_IF_CONST .EQ         .ARG0, 0, 1$, 1
        ; Variable Decrement By 1
        VM_RPN
            .R_REF      VAR_TURNIP_COUNTER
            .R_INT8     1
            .R_OPERATOR .SUB
            .R_STOP
        VM_SET                  VAR_TURNIP_COUNTER, .ARG0
        VM_POP                  1

        VM_JUMP                 2$
1$:
2$:

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 4
        VM_ACTOR_ACTIVATE       ACTOR

        ; If Actor At Position
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    0
            .R_OPERATOR .EQ
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    0
            .R_OPERATOR .EQ
            .R_OPERATOR .AND
            .R_STOP
        VM_IF_CONST .EQ         .ARG0, 0, 3$, 1
        ; Variable Decrement By 1
        VM_RPN
            .R_REF      VAR_TURNIP_COUNTER
            .R_INT8     1
            .R_OPERATOR .SUB
            .R_STOP
        VM_SET                  VAR_TURNIP_COUNTER, .ARG0
        VM_POP                  1

        VM_JUMP                 4$
3$:
4$:

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 5
        VM_ACTOR_ACTIVATE       ACTOR

        ; If Actor At Position
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    0
            .R_OPERATOR .EQ
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    0
            .R_OPERATOR .EQ
            .R_OPERATOR .AND
            .R_STOP
        VM_IF_CONST .EQ         .ARG0, 0, 5$, 1
        ; Variable Decrement By 1
        VM_RPN
            .R_REF      VAR_TURNIP_COUNTER
            .R_INT8     1
            .R_OPERATOR .SUB
            .R_STOP
        VM_SET                  VAR_TURNIP_COUNTER, .ARG0
        VM_POP                  1

        VM_JUMP                 6$
5$:
6$:

        ; Stop Script
        VM_STOP
