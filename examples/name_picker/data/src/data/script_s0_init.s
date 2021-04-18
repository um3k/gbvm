.include "vm.i"
.include "data/game_globals.i"

.globl _text_ff_joypad, _text_draw_speed, _text_out_speed, _text_in_speed

.area _CODE_255



___bank_script_s0_init = 255
.globl ___bank_script_s0_init

_script_s0_init::
        VM_LOCK

        ; Fade In
        VM_FADE_IN              1

        ; Text Set Animation Speed
        VM_SET_CONST_INT8       _text_ff_joypad, 1
        VM_SET_CONST_INT8       _text_draw_speed, 0
        VM_SET_CONST_INT8       _text_out_speed, 0
        VM_SET_CONST_INT8       _text_in_speed, 0

        VM_CONTEXT_PREPARE      1, ___bank_script_input_0, _script_input_0
        VM_INPUT_ATTACH         32, 1

        ; Variable Set To True
        VM_SET_CONST            VAR_STRING_0_, 1

        ; Variable Set To True
        VM_SET_CONST            VAR_STRING_1_, 1

        ; Variable Set To True
        VM_SET_CONST            VAR_STRING_2_, 1

        ; Variable Set To True
        VM_SET_CONST            VAR_STRING_3_, 1

        ; Variable Set To True
        VM_SET_CONST            VAR_STRING_4_, 1

        ; Call Script: Update Input Fields
        VM_CALL_FAR             ___bank_script_custom_1, _script_custom_1

        ; Stop Script
        VM_STOP
