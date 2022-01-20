.module script_s8t0_interact

.include "vm.i"
.include "data/game_globals.i"
.include "macro.i"

.globl _fade_frames_per_step, ___bank_scene_5, _scene_5

.area _CODE_255

ACTOR = -4

___bank_script_s8t0_interact = 255
.globl ___bank_script_s8t0_interact
.CURRENT_SCRIPT_BANK == ___bank_script_s8t0_interact

_script_s8t0_interact::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Load Scene
        VM_SET_CONST_INT8       _fade_frames_per_step, 3
        VM_FADE_OUT             1
        VM_SET_CONST            ACTOR, 0
        VM_SET_CONST            ^/(ACTOR + 1)/, 19968
        VM_SET_CONST            ^/(ACTOR + 2)/, 1664
        VM_ACTOR_SET_POS        ACTOR
        VM_ACTOR_SET_DIR        ACTOR, .DIR_LEFT
        VM_RAISE                EXCEPTION_CHANGE_SCENE, 3
            IMPORT_FAR_PTR_DATA _scene_5

        ; Stop Script
        VM_STOP
