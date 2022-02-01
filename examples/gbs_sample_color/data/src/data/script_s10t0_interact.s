.module script_s10t0_interact

.include "vm.i"
.include "data/game_globals.i"

.globl b_camera_shake_frames, _camera_shake_frames

.area _CODE_255

.LOCAL_ACTOR = -4
.LOCAL_TMP1_CAMERA_SHAKE_ARGS = -4

___bank_script_s10t0_interact = 255
.globl ___bank_script_s10t0_interact

_script_s10t0_interact::
        VM_LOCK

        VM_RESERVE              4

        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 0

        ; Actor Set Position
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 1)/, 6656
        VM_SET_CONST            ^/(.LOCAL_ACTOR + 2)/, 1664
        VM_ACTOR_SET_POS        .LOCAL_ACTOR

        ; Camera Shake
        VM_SET_CONST            .LOCAL_TMP1_CAMERA_SHAKE_ARGS, 6
        VM_SET_CONST            ^/(.LOCAL_TMP1_CAMERA_SHAKE_ARGS + 1)/, .CAMERA_SHAKE_X
        VM_INVOKE               b_camera_shake_frames, _camera_shake_frames, 0, .LOCAL_TMP1_CAMERA_SHAKE_ARGS

        ; Stop Script
        VM_STOP
