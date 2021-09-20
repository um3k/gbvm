.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255


___bank_script_s1a1_update = 255
.globl ___bank_script_s1a1_update

_script_s1a1_update::
1$:
        ; Variable Set To False
        VM_SET_CONST            VAR_TILE, 0

        VM_REPLACE_TILE_XY      2, 13, ___bank_tileset_0, _tileset_0, VAR_TILE

        ; Wait N Frames
        VM_PUSH_CONST           30
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Variable Set To True
        VM_SET_CONST            VAR_TILE, 1

        VM_REPLACE_TILE_XY      2, 13, ___bank_tileset_0, _tileset_0, VAR_TILE

        ; Wait N Frames
        VM_PUSH_CONST           30
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Variable Set To False
        VM_SET_CONST            VAR_TILE, 0

        VM_REPLACE_TILE_XY      2, 13, ___bank_tileset_0, _tileset_0, VAR_TILE

        ; Wait N Frames
        VM_PUSH_CONST           30
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TILE, 2

        VM_REPLACE_TILE_XY      2, 13, ___bank_tileset_0, _tileset_0, VAR_TILE

        ; Wait N Frames
        VM_PUSH_CONST           30
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        VM_JUMP                 1$
        ; Stop Script
        VM_STOP
