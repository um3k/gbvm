.include "vm.i"
.include "data/game_globals.i"

___bank_script_s2_input1    = 255
.globl ___bank_script_s2_input1

_script_s2_input1::
        VM_RESERVE              6

        VM_RTC_START            .RTC_START
        VM_RTC_LATCH
        VM_RTC_GET              .ARG3, .RTC_SECONDS 
        VM_RTC_GET              .ARG2, .RTC_MINUTES 
        VM_RTC_GET              .ARG1, .RTC_HOURS 
        VM_RTC_GET              .ARG0, .RTC_DAYS 
        
        VM_LOAD_TEXT            4
            .dw .ARG0, .ARG1, .ARG2, .ARG3
            .asciz "DAY:%d TIME: %d:%d:%d"
        VM_OVERLAY_MOVE_TO      0, 9, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_SHOW         0, 9, .UI_COLOR_BLACK
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_ANY)/

        VM_SET_CONST            .ARG5, 0
        VM_ACTOR_GET_POS        .ARG5

        VM_SET_CONST            .ARG2, 1
        VM_ACTOR_GET_POS        .ARG2

        VM_RPN
            ; chebyshev distance
            .R_REF      .ARG4
            .R_REF      .ARG1
            .R_OPERATOR .SUB
            .R_OPERATOR .ABS
            .R_REF      .ARG3
            .R_REF      .ARG0
            .R_OPERATOR .SUB
            .R_OPERATOR .ABS
            .R_OPERATOR .MAX
            ; manhattan distance
            .R_REF      .ARG4
            .R_REF      .ARG1
            .R_OPERATOR .SUB
            .R_OPERATOR .ABS
            .R_REF      .ARG3
            .R_REF      .ARG0
            .R_OPERATOR .SUB
            .R_OPERATOR .ABS
            .R_OPERATOR .ADD

            .R_STOP

        VM_LOAD_TEXT            6
            .dw .ARG6, .ARG5, .ARG3, .ARG2, .ARG1, .ARG0
            .asciz "\001\001\002\00302\n13\001\003\004\001\377\002\001x1=%d\ny1=%d x2=%d y2=%d\n\004\376\001Chebyshev:\002\002%d\n\002\001Manhattan:\002\002%d\n\002\001This is \002\002BOLD\002\001\nOk"
        VM_DISPLAY_TEXT         0, 0, 0
        VM_OVERLAY_SHOW         0, 9, .UI_COLOR_WHITE
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_ANY)/

        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW)/

        VM_POP                  ^/6 + 2/    ; 6 for local vars + 2 results of RPN calc

        VM_STOP
