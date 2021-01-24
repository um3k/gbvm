.include "vm.i"
.include "macro.i"
.include "data/game_globals.i"

.area _CODE_255

.globl ___bank_scene_3, _scene_3

___bank_script_s7_init = 255
.globl ___bank_script_s7_init

_script_s7_init::
        VM_LOCK

        VM_FADE_IN              .UI_MODAL
        VM_OVERLAY_WAIT         .UI_MODAL, .UI_WAIT_BTN_ANY
        VM_FADE_OUT             .UI_MODAL

        VM_RAISE                EXCEPTION_CHANGE_SCENE, 3    ; sizeof(far_ptr_t) == 3
            IMPORT_FAR_PTR_DATA _scene_3
