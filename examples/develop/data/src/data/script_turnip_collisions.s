.module script_turnip_collisions

.include "vm.i"
.include "data/game_globals.i"

.globl _pl_vel_y, b_wait_frames, _wait_frames, b_camera_shake_frames, _camera_shake_frames

.area _CODE_255

.SCRIPT_ARG_0_VARIABLE = -10
.SCRIPT_ARG_1_VARIABLE = -11
.SCRIPT_ARG_2_ACTOR = -12
.LOCAL_ACTOR = -4
.LOCAL_TMP4_CAMERA_SHAKE_ARGS = -4
.LOCAL_TMP1_OTHER_ACTOR = -7
.LOCAL_TMP2_VALUE_TMP = -7
.LOCAL_TMP3_WAIT_ARGS = -7

___bank_script_turnip_collisions = 255
.globl ___bank_script_turnip_collisions

_script_turnip_collisions::
        VM_RESERVE              7

        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 0

        ; If Actor up Relative To Actor
        VM_ACTOR_GET_POS        .LOCAL_ACTOR
        VM_SET                  .LOCAL_TMP1_OTHER_ACTOR, .SCRIPT_ARG_2_ACTOR
        VM_ACTOR_GET_POS        .LOCAL_TMP1_OTHER_ACTOR
        VM_RPN
            .R_REF      ^/(.LOCAL_ACTOR + 2)/
            .R_REF      ^/(.LOCAL_TMP1_OTHER_ACTOR + 2)/
            .R_OPERATOR .LT
            .R_STOP
        VM_IF_CONST .EQ         .ARG0, 0, 1$, 1

        ; Variable Set To True
        VM_SET_CONST            .LOCAL_TMP2_VALUE_TMP, 1
        VM_SET_INDIRECT         .SCRIPT_ARG_0_VARIABLE, .LOCAL_TMP2_VALUE_TMP

        ; Variable Decrement By 1
        VM_RPN
            .R_REF_IND  .SCRIPT_ARG_1_VARIABLE
            .R_INT8     1
            .R_OPERATOR .SUB
            .R_STOP
        VM_SET_INDIRECT         ^/(.SCRIPT_ARG_1_VARIABLE - 1)/, .ARG0
        VM_POP                  1

        ; Actor Set Active
        VM_SET                  .LOCAL_ACTOR, .SCRIPT_ARG_2_ACTOR

        ; Actor Set Collisions
        VM_ACTOR_SET_COLL_ENABLED .LOCAL_ACTOR, 0

        ; Actor Set Active
        VM_SET                  .LOCAL_ACTOR, .SCRIPT_ARG_2_ACTOR

        ; Actor Stop Update Script
        VM_ACTOR_TERMINATE_UPDATE .LOCAL_ACTOR

        ; Actor Set Active
        VM_SET                  .LOCAL_ACTOR, .SCRIPT_ARG_2_ACTOR

        ; Actor Set Spritesheet
        VM_ACTOR_SET_SPRITESHEET .LOCAL_ACTOR, ___bank_spritesheet_0, _spritesheet_0

        ; Player Bounce
        VM_SET_CONST_INT16      _pl_vel_y, -8192

        ; Wait N Frames
        VM_SET_CONST            .LOCAL_TMP3_WAIT_ARGS, 30
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP3_WAIT_ARGS

        ; Actor Hide
        VM_SET                  .LOCAL_ACTOR, .SCRIPT_ARG_2_ACTOR
        VM_ACTOR_SET_HIDDEN     .LOCAL_ACTOR, 1
        VM_ACTOR_DEACTIVATE     .LOCAL_ACTOR

        VM_JUMP                 2$
1$:
        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 0

        ; Actor Set Position
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 1)/, 6656
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 2)/, 1664
        VM_ACTOR_SET_POS        .LOCAL_ACTOR

        ; Camera Shake
        VM_SET_CONST            .LOCAL_TMP4_CAMERA_SHAKE_ARGS, 30
        VM_SET_CONST            ^/(.LOCAL_TMP4_CAMERA_SHAKE_ARGS + 1)/, .CAMERA_SHAKE_X
        VM_INVOKE               b_camera_shake_frames, _camera_shake_frames, 0, .LOCAL_TMP4_CAMERA_SHAKE_ARGS

2$:

        VM_RESERVE              -7
        VM_RET_FAR_N            3
