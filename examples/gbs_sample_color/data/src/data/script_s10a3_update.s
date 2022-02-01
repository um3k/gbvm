.module script_s10a3_update

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

.LOCAL_TMP0_WAIT_ARGS = -1

___bank_script_s10a3_update = 255
.globl ___bank_script_s10a3_update

_script_s10a3_update::
        VM_RESERVE              1

1$:
        ; Call Script: Turnip Movement
        VM_PUSH_CONST           4 ; Actor SCRIPT_ARG_0_ACTOR
        VM_CALL_FAR             ___bank_script_turnip_movement, _script_turnip_movement

        ; Wait N Frames
        VM_SET_CONST            .LOCAL_TMP0_WAIT_ARGS, 1
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP0_WAIT_ARGS

        VM_JUMP                 1$
        ; Stop Script
        VM_STOP
