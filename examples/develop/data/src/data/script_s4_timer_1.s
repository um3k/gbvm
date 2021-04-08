.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

___bank_script_s4_timer1 = 255
.globl ___bank_script_s4_timer1
.globl ___bank_tileset_6, _tileset_6

_script_s4_timer1::
        VM_IF_CONST     .EQ     VAR_S4_FLOWER_STATE, 3, 1$, 0
        VM_IF_CONST     .EQ     VAR_S4_FLOWER_STATE, 4, 2$, 0

        VM_SET_CONST            VAR_S4_FLOWER_STATE, 3
        VM_JUMP_REL             3$

1$:
        VM_SET_CONST            VAR_S4_FLOWER_STATE, 4
        VM_JUMP_REL             3$

2$:
        VM_SET_CONST            VAR_S4_FLOWER_STATE, 5
3$:
        VM_PUSH_CONST           1
        VM_REPLACE_TILE         0xA7, ___bank_tileset_6, _tileset_6, VAR_S4_FLOWER_STATE, .ARG0
        VM_POP                  1
        VM_STOP
