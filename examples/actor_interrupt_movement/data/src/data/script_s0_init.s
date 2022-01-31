.module script_s0_init

.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames, _fade_frames_per_step

.area _CODE_255


___bank_script_s0_init = 255
.globl ___bank_script_s0_init
.CURRENT_SCRIPT_BANK == ___bank_script_s0_init

_script_s0_init::
        VM_LOCK

        ; Variable Set To False
        VM_SET_CONST            VAR_S0A0_KILLED, 0

        ; Variable Set To False
        VM_SET_CONST            VAR_S0A0_KILLED_1, 0

        ; Variable Set To False
        VM_SET_CONST            VAR_S0A0_KILLED_2, 0

        ; Input Script Attach
        VM_CONTEXT_PREPARE      3, ___bank_script_input_0, _script_input_0
        VM_INPUT_ATTACH         32, ^/(3 | .OVERRIDE_DEFAULT)/

        ; Input Script Attach
        VM_CONTEXT_PREPARE      1, ___bank_script_input_1, _script_input_1
        VM_INPUT_ATTACH         128, ^/(1 | .OVERRIDE_DEFAULT)/

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_SET_CONST_INT8       _fade_frames_per_step, 1
        VM_FADE_IN              1

        ; Stop Script
        VM_STOP
