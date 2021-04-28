.include "vm.i"
.include "data/game_globals.i"

.globl b_wait_frames, _wait_frames

.area _CODE_255



___bank_script_s0_init = 255
.globl ___bank_script_s0_init

_script_s0_init::
        VM_LOCK

        ; Wait 1 Frame
        VM_PUSH_CONST           1
        VM_INVOKE               b_wait_frames, _wait_frames, 1, .ARG0

        ; Fade In
        VM_FADE_IN              1

        ; Stop Script
        VM_STOP
