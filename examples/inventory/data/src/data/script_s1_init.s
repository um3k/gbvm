.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255



___bank_script_s1_init = 255
.globl ___bank_script_s1_init

_script_s1_init::
        VM_LOCK

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Input Script Attach
        VM_CONTEXT_PREPARE      4, ___bank_script_input_2, _script_input_2
        VM_INPUT_ATTACH         16, 4

        ; Variable Set To Value
        VM_SET_CONST            VAR_VARIABLE_100, 255

        ; Variable Set To Value
        VM_SET_CONST            VAR_VARIABLE_99, 50

        ; Call Script: 
        VM_PUSH_CONST           VAR_VARIABLE_100 ; Variable .ARG2
        VM_CALL_FAR             ___bank_script_custom_0, _script_custom_0
        VM_POP                  1

        ; Stop Script
        VM_STOP
