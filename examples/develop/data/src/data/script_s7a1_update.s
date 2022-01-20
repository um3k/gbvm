.module script_s7a1_update

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

ACTOR = -4

___bank_script_s7a1_update = 255
.globl ___bank_script_s7a1_update
.CURRENT_SCRIPT_BANK == ___bank_script_s7a1_update

_script_s7a1_update::
        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

1$:
        ; Variable L0 = VAR_S7A1_LAUNCHANGLE+8
        VM_RPN
            .R_REF      VAR_S7A1_LAUNCHANGLE
            .R_INT16    8
            .R_OPERATOR .ADD
            .R_STOP
        VM_SET                  VAR_S7A1_LAUNCHANGLE, .ARG0
        VM_POP                  1

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 2

        ; Launch Projectile In Angle
        VM_ACTOR_GET_POS        ACTOR
        VM_RPN
            .R_REF      ^/(ACTOR + 1)/
            .R_INT16    0
            .R_OPERATOR .ADD
            .R_REF      ^/(ACTOR + 2)/
            .R_INT16    -128
            .R_OPERATOR .ADD
            .R_REF      VAR_S7A1_LAUNCHANGLE
            .R_STOP
        VM_PROJECTILE_LAUNCH    1, .ARG2
        VM_POP                  3
        ; Wait N Frames
        VM_PUSH_CONST           60
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        VM_JUMP                 1$
        ; Stop Script
        VM_STOP
