.module script_s7a9_update

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

.LOCAL_TMP0_WAIT_ARGS = -1

___bank_script_s7a9_update = 255
.globl ___bank_script_s7a9_update

_script_s7a9_update::
        VM_RESERVE              1

1$:
        ; Call Script: Enemy Ship Movement Diagonal Top To Bottom
        VM_PUSH_CONST           10 ; Actor SCRIPT_ARG_0_ACTOR
        VM_CALL_FAR             ___bank_script_enemy_ship_movement_diagonal_top_to_bottom, _script_enemy_ship_movement_diagonal_top_to_bottom

        ; Wait N Frames
        VM_SET_CONST            .LOCAL_TMP0_WAIT_ARGS, 1
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP0_WAIT_ARGS

        VM_JUMP                 1$
        ; Stop Script
        VM_STOP
