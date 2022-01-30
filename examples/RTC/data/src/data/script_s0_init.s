.module script_s0_init

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames, _fade_frames_per_step

.area _CODE_255

.LOCAL_TMP0_WAIT_ARGS = -1

___bank_script_s0_init = 255
.globl ___bank_script_s0_init

_script_s0_init::
        VM_LOCK

        VM_RESERVE              1

        VM_OVERLAY_MOVE_TO      0, 14, .OVERLAY_TEXT_IN_SPEED
        VM_OVERLAY_CLEAR        0, 0, 20, 2, .UI_COLOR_BLACK, 0
        VM_OVERLAY_SHOW         0, 14, .UI_COLOR_WHITE, 0
        
        VM_SET_CONST_INT8       _text_draw_speed, 0

        ; Variable Set To Value
        VM_SET_CONST            VAR_VARIABLE_7, 12

        ; Clock: Set Clock Time 
        VM_PUSH_VALUE           VAR_S0_LOCAL_2 ; Seconds
        VM_PUSH_CONST           100 ; Minutes
        VM_PUSH_VALUE           VAR_VARIABLE_7 ; Hours
        VM_PUSH_CONST           5 ; Days
        
        VM_RTC_LATCH
        VM_RTC_SET              .ARG3, .RTC_SECONDS 
        VM_RTC_SET              .ARG2, .RTC_MINUTES 
        VM_RTC_SET              .ARG1, .RTC_HOURS 
        VM_RTC_SET              .ARG0, .RTC_DAYS 
        
        VM_POP                  4

        ; Timer Start
        VM_TIMER_PREPARE        1, ___bank_script_timer_0, _script_timer_0
        VM_TIMER_SET            1, 2

        ; Input Script Attach
        VM_CONTEXT_PREPARE      3, ___bank_script_input_0, _script_input_0
        VM_INPUT_ATTACH         48, ^/(3 | .OVERRIDE_DEFAULT)/

        ; Wait N Frames
        VM_SET_CONST            .LOCAL_TMP0_WAIT_ARGS, 1
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP0_WAIT_ARGS

        ; Fade In
        VM_SET_CONST_INT8       _fade_frames_per_step, 1
        VM_FADE_IN              1

        ; Stop Script
        VM_STOP
