.module script_input_0

.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255


___bank_script_input_0 = 255
.globl ___bank_script_input_0
.CURRENT_SCRIPT_BANK == ___bank_script_input_0

_script_input_0::
        ; If Variable True
        VM_IF_CONST .GT         VAR_RTC_STOP, 0, 1$, 0
        ; Stop Clock
        VM_RTC_START            .RTC_STOP

        ; Variable Set To True
        VM_SET_CONST            VAR_RTC_STOP, 1

        VM_JUMP                 2$
1$:
        ; Start Clock
        VM_RTC_START            .RTC_START

        ; Variable Set To False
        VM_SET_CONST            VAR_RTC_STOP, 0

2$:

        ; Stop Script
        VM_STOP
