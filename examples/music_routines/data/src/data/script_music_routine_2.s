.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

___bank_script_music_routine_2 = 255
.globl ___bank_script_music_routine_2

_script_music_routine_2::
        VM_RPN
          .R_REF      0
          .R_INT8     1
          .R_OPERATOR .ADD
          .R_STOP
        VM_SET                  0, .ARG0
        VM_POP                  1

        ; Text Dialogue
        VM_OVERLAY_SCROLL       1, 1, 15, 4, .UI_COLOR_WHITE

        VM_LOAD_TEXT            2
        .dw 0, .ARG0
        .asciz "\001\001\003\002\005%d r2(%d)"
        VM_DISPLAY_TEXT

        ; Stop Script
        VM_STOP
