.include "vm.i"
        
.globl b_wait_frames, _wait_frames
.globl ___bank_spritesheet_1, _spritesheet_1

.area _CODE_4

___bank_SCRIPT_1 = 4
.globl ___bank_SCRIPT_1

_SCRIPT_1::
        VM_MUSIC_PLAY           1, 1
        
        VM_JUMP                 1$

        ; Text Dialogue
        VM_LOAD_TEXT            0
        .asciz "Textboxes without\nslide in/out\npart 1"
        VM_OVERLAY_MOVE_TO      0, 13, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_LOAD_TEXT            0
        .asciz "Textboxes without\nslide in/out\npart 2"
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_LOAD_TEXT            0
        .asciz "One Line\n\n"
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_LOAD_TEXT            0
        .asciz "Two\nLines\n"
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Text Multiple Choice
        VM_LOAD_TEXT            0
        .asciz "\020First choice\nSecond choice"
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, .UI_ENABLE_MENU_ONECOL
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_CHOICE               0, 0
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        ; Text Dialogue
        VM_LOAD_TEXT            1
        .dw 0
        .asciz "You chose %d\n"
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        ; Text Menu
        VM_LOAD_TEXT            0
        .asciz "\020Item 1\nItem 2\nItem 3\nItem 4\nItem 5\nItem 6"
        VM_OVERLAY_MOVE_TO      0, 12, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, .UI_ENABLE_MENU_TWOCOL
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_CHOICE               1, ^/(.UI_MENU_CANCEL_B)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_RANDOMIZE
        
        VM_RAND                 2, 0, 10 
        VM_RAND                 3, 0, 10 
        VM_RAND                 4, 0, 10 
        VM_RAND                 5, 0, 10 
        VM_RAND                 6, 0, 10 
        VM_RAND                 7, 0, 10 
        VM_RAND                 8, 0, 10 
        VM_RAND                 9, 0, 10 
        VM_RAND                 10, 0, 10 
        VM_RAND                 11, 0, 10 
        ; Text Dialogue
        VM_LOAD_TEXT            11
        .dw 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
        .asciz "You chose %d\nrand:\n%d %d %d %d %d\n%d %d %d %d %d\n"

        VM_OVERLAY_MOVE_TO      0, 11, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        ; Text Menu
        VM_LOAD_TEXT            0
        .asciz "\020Item 1\nItem 2\nItem 3\nItem 4\nItem 5\nItem 6"
        VM_OVERLAY_MOVE_TO      10, 18, 0
        VM_OVERLAY_MOVE_TO      10, 10, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, .UI_ENABLE_MENU_ONECOL
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_CHOICE               2, ^/(.UI_MENU_CANCEL_B)/
        VM_OVERLAY_MOVE_TO      10, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/
        VM_OVERLAY_MOVE_TO      0, 18, 0
        ; Text Dialogue
        VM_LOAD_TEXT            1
        .dw 2
        .asciz "You chose %d\n"
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        ; Set text box open/close speed globally
        VM_SET_CONST_INT8      _text_in_speed, 1
        VM_SET_CONST_INT8      _text_out_speed, 2

        ; render multiple choice 
        VM_LOAD_TEXT            0
            .asciz "\0201) Option One\n2) Option Two"

        ; Layout One Column ============== 

        ; slide in
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED

        ; start displaying menu
        VM_DISPLAY_TEXT         0, 0, .UI_ENABLE_MENU_ONECOL                       ; no avatars, menu
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        VM_CHOICE               0, ^/(.UI_MENU_LAST_0 | .UI_MENU_CANCEL_B)/

        ; slide out
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, .UI_WAIT_WINDOW


        ; Layout Two Column ============== 

        VM_LOAD_TEXT            0
            .asciz "\020One\nTwo\nThree\nFour\nFive\nSix"

        ; slide in
        VM_OVERLAY_MOVE_TO      0, 12, .OVERLAY_TEXT_IN_SPEED

        ; start displaying text
        VM_DISPLAY_TEXT         0, 0, .UI_ENABLE_MENU_TWOCOL                       ; no avatars, menu
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        VM_CHOICE               0, ^/(.UI_MENU_LAST_0 | .UI_MENU_CANCEL_B)/

        ; slide out
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, .UI_WAIT_WINDOW

        ; Layout One Column Pin Right ============== 

        ; move window to 12 tiles by Y
        VM_OVERLAY_MOVE_TO      10, 18, 0
        VM_OVERLAY_MOVE_TO      10, 10, .OVERLAY_TEXT_IN_SPEED

        ; start displaying text
        VM_DISPLAY_TEXT         0, 0, .UI_ENABLE_MENU_ONECOL                       ; no avatars, menu
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        VM_CHOICE               0, ^/(.UI_MENU_LAST_0 | .UI_MENU_CANCEL_B)/

        ; slide out
        VM_OVERLAY_MOVE_TO      10, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, .UI_WAIT_WINDOW

        ; reset overlay position
        VM_OVERLAY_MOVE_TO      0, 18, 0

        ; render text 
        VM_LOAD_TEXT            0
            .asciz "Hello World\nHello World"

        ; move window to 12 tiles by Y
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED

        ; start displaying text
        VM_DISPLAY_TEXT         0, 0, 0    ; no avatar

        ; wait for window to slide
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/

        ; slide out
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, .UI_WAIT_WINDOW

        ; Set slow text globally
        VM_SET_CONST_INT8      _text_draw_speed, 31

        ; render text 
        VM_LOAD_TEXT            0
            .asciz "GLOBAL SLOW!!!\n\022Faster!!!"

        ; move window to 12 tiles by Y
        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED

        ; start displaying text
        VM_DISPLAY_TEXT         0, 0, 0    ; no avatar

        ; wait for window to slide
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/

        ; slide out
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, .UI_WAIT_WINDOW

        ; Restore text speed globally
        VM_SET_CONST_INT8      _text_draw_speed, 1

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
        VM_OVERLAY_MOVE_TO      0, 12, .OVERLAY_TEXT_IN_SPEED

        ; start displaying text
        VM_DISPLAY_TEXT         ___bank_spritesheet_1, _spritesheet_1, 0    ; avatar 1

        ; wait for window to slide
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/

        ; slide out
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, .UI_WAIT_WINDOW

1$:
        ; show menu
        VM_OVERLAY_SETPOS       20, 9
        VM_LOAD_TEXT            0
            .asciz "\020option1\noption2\noption3\noption4\noption5\noption6\ncancel"
        VM_OVERLAY_MOVE_TO      10, 9, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, .UI_ENABLE_MENU_ONECOL                ; no avatars, menu

        VM_PUSH                 0
        VM_CHOICE               .ARG0, ^/(.UI_MENU_LAST_0 | .UI_MENU_CANCEL_B)/

        VM_POP                  1
;        VM_OVERLAY_WAIT         .UI_NONMODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

        VM_PUSH                 ^/(30*60)/      ; !!! always use escaping and brackets
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        VM_OVERLAY_MOVE_TO      20, 9, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_NONMODAL, .UI_WAIT_WINDOW

        VM_OVERLAY_HIDE
        VM_STOP
