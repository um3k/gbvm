.include "vm.i"
        
.globl b_wait_frames, _wait_frames
.globl ___bank_spritesheet_1, _spritesheet_1

.area _CODE_4

___bank_SCRIPT_1 = 4
.globl ___bank_SCRIPT_1

_SCRIPT_1::
        ; black window
        VM_OVERLAY_SHOW         0, 20, .UI_COLOR_BLACK
        VM_OVERLAY_MOVE_TO      0, 0, 1
        VM_OVERLAY_WAIT         .UI_NONMODAL, .UI_WAIT_WINDOW
        VM_OVERLAY_MOVE_TO      0, 20, 1
        VM_OVERLAY_WAIT         .UI_NONMODAL, .UI_WAIT_WINDOW

        ; init some variables on stack
        VM_RPN
            .R_INT8 2
            .R_INT8 4           ; speed in variable
            .R_INT8 'f'
            .R_INT8 'o'
            .R_INT8 'x'
            .R_INT8 'd'
            .R_INT8 'o'
            .R_INT8 'g'
            .R_INT8 10
            .R_STOP

        ; render text with all features
        VM_LOAD_TEXT            11
            .dw .ARG7, .ARG8, .ARG6, .ARG5, .ARG4, .ARG7, .ARG3, .ARG2, .ARG1, .ARG8, .ARG0
            .asciz "The %tquick%t red\n%c%c%c \025jumps\022 over\nthe lazy brown\n%t%c%c%c%t %dx"
            ;           ^^ temp in var        ^^^^ temp hardcoded (octal)                    ^^ var itself
            ;                          ^^ char in var                           ^^ CR

        ; dispose variables on stack
        VM_POP                  9

        ; move window to 12 tiles by Y
        VM_OVERLAY_MOVE_TO      0, 12, 1

        ; start displaying text
        VM_DISPLAY_TEXT         ___bank_spritesheet_1, _spritesheet_1       ; avatar 1

        ; wait for window to slide
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/

        ; slide out
        VM_OVERLAY_MOVE_TO      0, 18, 1
        VM_OVERLAY_WAIT         .UI_MODAL, .UI_WAIT_WINDOW

        ; show menu
        VM_OVERLAY_SETPOS       20, 9
        VM_LOAD_TEXT            0
            .asciz "\020option1\noption2\noption3\noption4\noption5\noption6\ncancel"
        VM_OVERLAY_MOVE_TO      10, 9, 1
        VM_DISPLAY_TEXT         0, 0       ; no avatars
        VM_OVERLAY_WAIT         .UI_NONMODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        VM_PUSH                 ^/(30*60)/      ; !!! always use escaping and brackets
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        VM_OVERLAY_MOVE_TO      20, 9, 1
        VM_OVERLAY_WAIT         .UI_NONMODAL, .UI_WAIT_WINDOW

        VM_STOP
