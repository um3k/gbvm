.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255


___bank_script_s7_init = 255
.globl ___bank_script_s7_init

_script_s7_init::
        VM_LOCK

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Timer Start
        VM_TIMER_PREPARE        1, ___bank_script_timer_1, _script_timer_1
        VM_TIMER_SET            1, 1

        ; Input Script Attach
        VM_CONTEXT_PREPARE      1, ___bank_script_input_2, _script_input_2
        VM_INPUT_ATTACH         128, 1

        ; Input Script Attach
        VM_CONTEXT_PREPARE      3, ___bank_script_input_3, _script_input_3
        VM_INPUT_ATTACH         32, 3

        ; Stop Script
        VM_STOP
