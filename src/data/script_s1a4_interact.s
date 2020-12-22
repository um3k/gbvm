.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

ACTOR = -4

___bank_script_s1a4_interact = 255
.globl ___bank_script_s1a4_interact

_script_s1a4_interact::
        VM_PUSH                 0
        VM_PUSH                 0
        VM_PUSH                 0
        VM_PUSH                 0
        ; Actor Set Active
        VM_SET_CONST            ACTOR, 5
        VM_ACTOR_ACTIVATE       ACTOR
        ; Actor Push
        ; NOT IMPLEMENTED
        ; Stop Script
        VM_STOP
