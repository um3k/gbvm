.include "vm.i"
.include "data/game_globals.i"

___bank_script_s2_input1    = 255
.globl ___bank_script_s2_input1

_script_s2_input1::
        VM_PUSH_CONST           100
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_RTC_START            .RTC_START
        VM_RTC_LATCH
        VM_RTC_GET              .ARG3, .RTC_SECONDS 
        VM_RTC_GET              .ARG2, .RTC_MINUTES 
        VM_RTC_GET              .ARG1, .RTC_HOURS 
        VM_RTC_GET              .ARG0, .RTC_DAYS 
        
        VM_LOAD_TEXT            4
            .dw .ARG0, .ARG1, .ARG2, .ARG3
            .asciz "DAY:%d!\nTIME: %d:%d:%d"
        VM_OVERLAY_MOVE_TO      0, 13, .OVERLAY_TEXT_IN_SPEED
        VM_DISPLAY_TEXT         0, 0, 0

        VM_OVERLAY_SHOW         0, 18, .UI_COLOR_BLACK
        VM_OVERLAY_MOVE_TO      0, 9, .OVERLAY_TEXT_IN_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_BTN_ANY)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_TEXT_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW)/

        VM_POP                  4

        VM_STOP
