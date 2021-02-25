.include "vm.i"
.include "macro.i"
.include "data/game_globals.i"

.area _CODE_255

___bank_script_s7_timer1 = 255
.globl ___bank_script_s7_timer1
.globl ___bank_tileset_7_1, _tileset_7_1

_script_s7_timer1::

        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_RTC_LATCH
        VM_RTC_GET              .ARG2, .RTC_SECONDS
        VM_RTC_GET              .ARG1, .RTC_MINUTES 
        VM_RTC_GET              .ARG0, .RTC_HOURS 
        VM_RPN
            .R_REF      .ARG0
            .R_INT8     10
            .R_OPERATOR .DIV
            .R_REF      .ARG0
            .R_INT8     10
            .R_OPERATOR .MOD
            .R_REF      .ARG1
            .R_INT8     10
            .R_OPERATOR .DIV
            .R_REF      .ARG1
            .R_INT8     10
            .R_OPERATOR .MOD
            .R_REF      .ARG2
            .R_INT8     10
            .R_OPERATOR .DIV
            .R_REF      .ARG2
            .R_INT8     10
            .R_OPERATOR .MOD
            .R_STOP

        VM_REPLACE_TILE_XY      12, 17, ___bank_tileset_7_1, _tileset_7_1, .ARG5
        VM_REPLACE_TILE_XY      13, 17, ___bank_tileset_7_1, _tileset_7_1, .ARG4
        VM_REPLACE_TILE_XY      15, 17, ___bank_tileset_7_1, _tileset_7_1, .ARG3
        VM_REPLACE_TILE_XY      16, 17, ___bank_tileset_7_1, _tileset_7_1, .ARG2
        VM_REPLACE_TILE_XY      18, 17, ___bank_tileset_7_1, _tileset_7_1, .ARG1
        VM_REPLACE_TILE_XY      19, 17, ___bank_tileset_7_1, _tileset_7_1, .ARG0

        VM_POP                  6       ; free results of rpn

        VM_POP                  3

        VM_PUSH_CONST           10
        VM_REPLACE_TILE_XY      14, 17, ___bank_tileset_7_1, _tileset_7_1, .ARG0
        VM_REPLACE_TILE_XY      17, 17, ___bank_tileset_7_1, _tileset_7_1, .ARG0
        VM_POP                  1

        VM_STOP
