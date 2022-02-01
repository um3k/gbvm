.module script_s1a1_update

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255

.LOCAL_TMP0_WAIT_ARGS = -1
.LOCAL_TMP1_WAIT_ARGS = -1
.LOCAL_TMP2_WAIT_ARGS = -1
.LOCAL_TMP3_WAIT_ARGS = -1
.LOCAL_TMP4_WAIT_ARGS = -5

___bank_script_s1a1_update = 255
.globl ___bank_script_s1a1_update

_script_s1a1_update::
        VM_RESERVE              5

1$:
        ; Variable Set To False
        VM_SET_CONST            VAR_TILE, 0

        VM_REPLACE_TILE_XY      2, 13, ___bank_tileset_0, _tileset_0, VAR_TILE

        ; Wait N Frames
        VM_SET_CONST            .LOCAL_TMP0_WAIT_ARGS, 30
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP0_WAIT_ARGS

        ; Variable Set To True
        VM_SET_CONST            VAR_TILE, 1

        VM_REPLACE_TILE_XY      2, 13, ___bank_tileset_0, _tileset_0, VAR_TILE

        ; Wait N Frames
        VM_SET_CONST            .LOCAL_TMP1_WAIT_ARGS, 30
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP1_WAIT_ARGS

        ; Variable Set To False
        VM_SET_CONST            VAR_TILE, 0

        VM_REPLACE_TILE_XY      2, 13, ___bank_tileset_0, _tileset_0, VAR_TILE

        ; Wait N Frames
        VM_SET_CONST            .LOCAL_TMP2_WAIT_ARGS, 30
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP2_WAIT_ARGS

        ; Variable Set To Value
        VM_SET_CONST            VAR_TILE, 2

        VM_REPLACE_TILE_XY      2, 13, ___bank_tileset_0, _tileset_0, VAR_TILE

        ; Wait N Frames
        VM_SET_CONST            .LOCAL_TMP3_WAIT_ARGS, 30
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP3_WAIT_ARGS

        ; Wait N Frames
        VM_SET_CONST            .LOCAL_TMP4_WAIT_ARGS, 1
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP4_WAIT_ARGS

        VM_JUMP                 1$
        ; Stop Script
        VM_STOP
