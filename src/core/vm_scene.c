#pragma bank 2

#include "vm.h"
#include "vm_exceptions.h"
#include "bankdata.h"
#include "data_manager.h"

void vm_scene_push() __banked {
    scene_stack_ptr->scene = current_scene;
    // save other fields here
/*
    // old code:
    scene_stack[scene_stack_ptr].scene_index = current_state;
    scene_stack[scene_stack_ptr].player_dir.x = actors[0].dir.x;
    scene_stack[scene_stack_ptr].player_dir.y = actors[0].dir.y;
    scene_stack[scene_stack_ptr].player_pos.x = 0;  // @wtf-but-needed
    scene_stack[scene_stack_ptr].player_pos.x = actors[0].pos.x >> 3;
    scene_stack[scene_stack_ptr].player_pos.y = 0;  // @wtf-but-needed
    scene_stack[scene_stack_ptr].player_pos.y = actors[0].pos.y >> 3;
*/

    scene_stack_ptr++; 
}

void vm_scene_pop() __banked {
    vm_exception_code = EXCEPTION_CHANGE_SCENE;
    vm_exception_params_length = sizeof(far_ptr_t);
    scene_stack_ptr--;
    vm_exception_params_bank = 1; // any bank
    vm_exception_params_offset = &scene_stack_ptr->scene;
/*
    // old code:
    map_next_pos.x = 0;  // @wtf-but-needed
    map_next_pos.x = scene_stack[scene_stack_ptr].player_pos.x * 8;
    map_next_pos.y = 0;  // @wtf-but-needed
    map_next_pos.y = scene_stack[scene_stack_ptr].player_pos.y * 8;
    map_next_dir.x = scene_stack[scene_stack_ptr].player_dir.x;
    map_next_dir.y = scene_stack[scene_stack_ptr].player_dir.y;

    // this is the result of exception
    // SetScene(scene_next_index);

    // this must be controlled manually with VM_FADE_OUT
    FadeSetSpeed(script_cmd_args[0]);
    active_script_ctx.script_update_fn = ScriptUpdate_AwaitFade;
*/
}
