.include "vm.i"
.include "macro.i"
.include "data/game_globals.i"

.area _CODE_255



___bank_script_s2t1_interact = 255
.globl ___bank_script_s2t1_interact

_script_s2t1_interact::

        VM_LOCK

        VM_FADE_OUT             1

        VM_SOUND_PLAY           2, 1, 0x4c,0x81,0x43,0x73,0x86

        VM_PUSH_CONST           0
        VM_PUSH_CONST           1152
        VM_PUSH_CONST           2048
        VM_ACTOR_SET_POS        .ARG2
        VM_POP                  3

        VM_RAISE                EXCEPTION_CHANGE_SCENE, 3    ; sizeof(far_ptr_t) == 3
            IMPORT_FAR_PTR_DATA _scene_0 
