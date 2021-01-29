.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

___bank_script_s4_timer1 = 255
.globl ___bank_script_s4_timer1
.globl ___bank_tileset_6, _tileset_6

_script_s4_timer1::
        VM_IF_CONST     .EQ     VAR_S4_FLOWER_STATE, 0, 1$, 0
        VM_IF_CONST     .EQ     VAR_S4_FLOWER_STATE, 1, 2$, 0

        VM_REPLACE_TILE         0xA7, ___bank_tileset_6, _tileset_6, 3, 1
        VM_SET_CONST            VAR_S4_FLOWER_STATE, 0
        VM_STOP

1$:
        VM_REPLACE_TILE         0xA7, ___bank_tileset_6, _tileset_6, 4, 1
        VM_SET_CONST            VAR_S4_FLOWER_STATE, 1
        VM_STOP

2$:
        VM_REPLACE_TILE         0xA7, ___bank_tileset_6, _tileset_6, 5, 1
        VM_SET_CONST            VAR_S4_FLOWER_STATE, 2
        VM_STOP
