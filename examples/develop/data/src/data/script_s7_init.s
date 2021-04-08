.include "vm.i"
.include "macro.i"
.include "data/game_globals.i"

.area _CODE_255

.globl ___bank_scene_3, _scene_3

___bank_script_s7_init = 255
.globl ___bank_script_s7_init
.globl ___bank_script_s7_timer1, _script_s7_timer1

_script_s7_init::
        VM_TIMER_PREPARE        1, ___bank_script_s7_timer1, _script_s7_timer1
        VM_TIMER_SET            1, 2

        VM_MUSIC_PLAY           ___bank_music_track_102__Data, _music_track_102__Data, .MUSIC_LOOP

        VM_FADE_IN              .UI_MODAL
        VM_INPUT_WAIT           0xff
        VM_FADE_OUT             .UI_MODAL

        VM_RAISE                EXCEPTION_CHANGE_SCENE, 3    ; sizeof(far_ptr_t) == 3
            IMPORT_FAR_PTR_DATA _scene_3
