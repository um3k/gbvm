.include "vm.i"
.include "data/game_globals.i"
.include "macro.i"

.globl ___bank_scene_2, _scene_2

.area _CODE_255

ACTOR = -4

___bank_script_s4t1_interact = 255
.globl ___bank_script_s4t1_interact

_script_s4t1_interact::
        VM_LOCK

        ; Local Actor
        VM_PUSH                 0
        VM_PUSH                 0
        VM_PUSH                 0
        VM_PUSH                 0

        ; Load Scene
        VM_FADE_OUT             2
        VM_SET_CONST            ACTOR, 0
        VM_SET_CONST            ^/(ACTOR + 1)/, 1280
        VM_SET_CONST            ^/(ACTOR + 2)/, 1408
        VM_ACTOR_SET_POS        ACTOR
        VM_ACTOR_SET_DIR        ACTOR, .DIR_DOWN
        VM_RAISE                EXCEPTION_CHANGE_SCENE, 3
            IMPORT_FAR_PTR_DATA _scene_2
        ; Stop Script
        VM_STOP
