.module script_s7a10_update

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

.LOCAL_TMP0_WAIT_ARGS = -1

___bank_script_s7a10_update = 255
.globl ___bank_script_s7a10_update

_script_s7a10_update::
        VM_RESERVE              1

1$:
        ; Call Script: Enemy Ship Movement Diagonal Bottom To Top
        VM_PUSH_CONST           11 ; Actor SCRIPT_ARG_0_ACTOR
        VM_CALL_FAR             ___bank_script_enemy_ship_movement_diagonal_bottom_to_top, _script_enemy_ship_movement_diagonal_bottom_to_top

        ; Wait N Frames
        VM_SET_CONST            .LOCAL_TMP0_WAIT_ARGS, 1
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP0_WAIT_ARGS

        VM_JUMP                 1$
        ; Stop Script
        VM_STOP
