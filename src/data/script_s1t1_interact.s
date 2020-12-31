.include "vm.i"
.include "macro.i"
.include "data/game_globals.i"

.area _CODE_255



___bank_script_s1t1_interact = 255
.globl ___bank_script_s1t1_interact

_script_s1t1_interact::

        VM_LOCK

        VM_FADE_OUT             1

        VM_RAISE                EXCEPTION_CHANGE_SCENE, 3    ; sizeof(far_ptr_t) == 3
            IMPORT_FAR_PTR_DATA _scene_2 

        VM_STOP
