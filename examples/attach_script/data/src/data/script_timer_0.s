.module script_timer_0

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255


___bank_script_timer_0 = 255
.globl ___bank_script_timer_0

_script_timer_0::
        ; Clock: Store Clock Time In Variables
        
        VM_RTC_LATCH
        VM_RTC_GET        VAR_SECONDS, .RTC_SECONDS 
        VM_RTC_GET        VAR_MINUTES, .RTC_MINUTES 
        VM_RTC_GET        VAR_HOURS, .RTC_HOURS 
        VM_RTC_GET        VAR_DAYS, .RTC_DAYS

        ; Advanced Text Dialogue
        VM_LOAD_TEXT            4
        .dw VAR_DAYS, VAR_HOURS, VAR_MINUTES, VAR_SECONDS
        .asciz "\003\001\001Day: %d  --  %d:%d:%d"
        VM_OVERLAY_MOVE_TO      0, 17, .OVERLAY_IN_SPEED
        VM_OVERLAY_SET_SCROLL   0, 0, 20, 3, .UI_COLOR_WHITE

        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, .UI_WAIT_WINDOW

        ; Stop Script
        VM_STOP
