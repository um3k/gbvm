.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255



___bank_script_s0_init = 255
.globl ___bank_script_s0_init

_script_s0_init::
        VM_LOCK

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Input Script Attach
        VM_CONTEXT_PREPARE      8, ___bank_script_input_0, _script_input_0
        VM_INPUT_ATTACH         1, 8

        ; Input Script Attach
        VM_CONTEXT_PREPARE      7, ___bank_script_input_1, _script_input_1
        VM_INPUT_ATTACH         2, 7

        ; Variable Set To False
        VM_SET_CONST            VAR_CURSOR_INDEX, 0

        ; Call Script: Draw cursor
        VM_PUSH_CONST           VAR_CURSOR_INDEX ; Variable .ARG2
        VM_CALL_FAR             ___bank_script_draw_cursor, _script_draw_cursor
        VM_POP                  1

        ; Variable Set To Value
        VM_SET_CONST            VAR_VARIABLE_6, 20

        ; Set Tile
        VM_REPLACE_TILE_XY      12, 12, ___bank_tileset_extra_0, _tileset_extra_0, VAR_VARIABLE_6

        ; Stop Script
        VM_STOP
