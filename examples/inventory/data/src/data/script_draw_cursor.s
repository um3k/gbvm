.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255



___bank_script_draw_cursor = 255
.globl ___bank_script_draw_cursor

_script_draw_cursor::
        ; Switch Variable
        ; case 0:
        VM_PUSH_VALUE_IND       ^/(.ARG2)/
        VM_IF_CONST .NE         .ARG0, 0, 1$, 1
        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 0

        ; Set Tile
        VM_REPLACE_TILE_XY      0, 2, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 1

        ; Set Tile
        VM_REPLACE_TILE_XY      3, 2, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 2

        ; Set Tile
        VM_REPLACE_TILE_XY      0, 3, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 3

        ; Set Tile
        VM_REPLACE_TILE_XY      3, 3, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        VM_JUMP                 11$
1$:
        ; case 1:
        VM_PUSH_VALUE_IND       ^/(.ARG2)/
        VM_IF_CONST .NE         .ARG0, 1, 2$, 1
        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 0

        ; Set Tile
        VM_REPLACE_TILE_XY      4, 2, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 1

        ; Set Tile
        VM_REPLACE_TILE_XY      7, 2, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 2

        ; Set Tile
        VM_REPLACE_TILE_XY      4, 3, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 3

        ; Set Tile
        VM_REPLACE_TILE_XY      7, 3, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        VM_JUMP                 11$
2$:
        ; case 2:
        VM_PUSH_VALUE_IND       ^/(.ARG2)/
        VM_IF_CONST .NE         .ARG0, 2, 3$, 1
        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 0

        ; Set Tile
        VM_REPLACE_TILE_XY      0, 4, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 1

        ; Set Tile
        VM_REPLACE_TILE_XY      3, 4, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 2

        ; Set Tile
        VM_REPLACE_TILE_XY      0, 5, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 3

        ; Set Tile
        VM_REPLACE_TILE_XY      3, 5, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        VM_JUMP                 11$
3$:
        ; case 3:
        VM_PUSH_VALUE_IND       ^/(.ARG2)/
        VM_IF_CONST .NE         .ARG0, 3, 4$, 1
        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 0

        ; Set Tile
        VM_REPLACE_TILE_XY      4, 4, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 1

        ; Set Tile
        VM_REPLACE_TILE_XY      7, 4, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 2

        ; Set Tile
        VM_REPLACE_TILE_XY      4, 5, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 3

        ; Set Tile
        VM_REPLACE_TILE_XY      7, 5, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        VM_JUMP                 11$
4$:
        ; case 4:
        VM_PUSH_VALUE_IND       ^/(.ARG2)/
        VM_IF_CONST .NE         .ARG0, 4, 5$, 1
        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 0

        ; Set Tile
        VM_REPLACE_TILE_XY      0, 6, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 1

        ; Set Tile
        VM_REPLACE_TILE_XY      3, 6, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 2

        ; Set Tile
        VM_REPLACE_TILE_XY      0, 7, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 3

        ; Set Tile
        VM_REPLACE_TILE_XY      3, 7, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        VM_JUMP                 11$
5$:
        ; case 5:
        VM_PUSH_VALUE_IND       ^/(.ARG2)/
        VM_IF_CONST .NE         .ARG0, 5, 6$, 1
        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 0

        ; Set Tile
        VM_REPLACE_TILE_XY      4, 6, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 1

        ; Set Tile
        VM_REPLACE_TILE_XY      7, 6, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 2

        ; Set Tile
        VM_REPLACE_TILE_XY      4, 7, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 3

        ; Set Tile
        VM_REPLACE_TILE_XY      7, 7, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        VM_JUMP                 11$
6$:
        ; case 6:
        VM_PUSH_VALUE_IND       ^/(.ARG2)/
        VM_IF_CONST .NE         .ARG0, 6, 7$, 1
        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 0

        ; Set Tile
        VM_REPLACE_TILE_XY      0, 8, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 1

        ; Set Tile
        VM_REPLACE_TILE_XY      3, 8, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 2

        ; Set Tile
        VM_REPLACE_TILE_XY      0, 9, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 3

        ; Set Tile
        VM_REPLACE_TILE_XY      3, 9, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        VM_JUMP                 11$
7$:
        ; case 7:
        VM_PUSH_VALUE_IND       ^/(.ARG2)/
        VM_IF_CONST .NE         .ARG0, 7, 8$, 1
        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 0

        ; Set Tile
        VM_REPLACE_TILE_XY      4, 8, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 1

        ; Set Tile
        VM_REPLACE_TILE_XY      7, 8, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 2

        ; Set Tile
        VM_REPLACE_TILE_XY      4, 9, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 3

        ; Set Tile
        VM_REPLACE_TILE_XY      7, 9, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        VM_JUMP                 11$
8$:
        ; case 8:
        VM_PUSH_VALUE_IND       ^/(.ARG2)/
        VM_IF_CONST .NE         .ARG0, 8, 9$, 1
        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 0

        ; Set Tile
        VM_REPLACE_TILE_XY      0, 10, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 1

        ; Set Tile
        VM_REPLACE_TILE_XY      3, 10, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 2

        ; Set Tile
        VM_REPLACE_TILE_XY      0, 11, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 3

        ; Set Tile
        VM_REPLACE_TILE_XY      3, 11, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        VM_JUMP                 11$
9$:
        ; case 9:
        VM_PUSH_VALUE_IND       ^/(.ARG2)/
        VM_IF_CONST .NE         .ARG0, 9, 10$, 1
        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 0

        ; Set Tile
        VM_REPLACE_TILE_XY      4, 10, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 1

        ; Set Tile
        VM_REPLACE_TILE_XY      7, 10, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 2

        ; Set Tile
        VM_REPLACE_TILE_XY      4, 11, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        ; Variable Set To Value
        VM_SET_CONST            VAR_TEMP_0, 3

        ; Set Tile
        VM_REPLACE_TILE_XY      7, 11, ___bank_tileset_extra_0, _tileset_extra_0, VAR_TEMP_0

        VM_JUMP                 11$
10$:
        ; default:
11$:

        VM_RET_FAR
