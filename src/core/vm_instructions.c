#include "vm.h"

#include "VM_Actor.h"
#include "VM_UI.h"
#include "VM_gameboy.h"

// here we define all VM instructions: their handlers and parameter lengths in bytes
// this array must be nonbanked as well as STEP_VM()
const SCRIPT_CMD script_cmds[] = {
    // system instructions section
    {vm_push,                   2}, // 0x01
    {vm_pop,                    1}, // 0x02
    {vm_call_rel,               1}, // 0x03
    {vm_call,                   2}, // 0x04
    {vm_ret,                    1}, // 0x05
    {vm_loop_rel,               4}, // 0x06
    {vm_loop,                   5}, // 0x07
    {vm_jump_rel,               1}, // 0x08
    {vm_jump,                   2}, // 0x09
    {vm_call_far,               3}, // 0x0A
    {vm_ret_far,                1}, // 0x0B
    {vm_systime,                2}, // 0x0C
    {vm_invoke,                 6}, // 0x0D
    {vm_beginthread,            6}, // 0x0E
    {vm_if,                     8}, // 0x0F
    {vm_debug,                  1}, // 0x10
    {vm_pushvalue,              2}, // 0x11
    {vm_reserve,                1}, // 0x12
    {vm_set,                    4}, // 0x13
    {vm_set_const,              4}, // 0x14
    {vm_rpn,                    0}, // 0x15
    {vm_join,                   2}, // 0x16
    {vm_terminate,              2}, // 0x17
    {vm_idle,                   0}, // 0x18
    {vm_get_tlocal,             4}, // 0x19
    {vm_if_const,               8}, // 0x1A
    {vm_get_uint8,              4}, // 0x1B
    {vm_get_int8,               4}, // 0x1C
    {vm_get_int16,              4}, // 0x1D
    {vm_set_uint8,              4}, // 0x1E
    {vm_set_int8,               4}, // 0x1F
    {vm_set_int16,              4}, // 0x20
    {vm_set_const_int8,         3}, // 0x21
    {vm_set_const_int16,        4}, // 0x22
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},

    // actor instructions section
    {vm_actor_move_to,          2}, // 0x30
    {vm_actor_activate,         2}, // 0x31
    {vm_actor_set_dir,          4}, // 0x32
    {vm_actor_deactivate,       2}, // 0x33
    {vm_actor_set_anim,         4}, // 0x34
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},

    // user interface instructions section
    {vm_load_text,              1}, // 0x40
    {vm_display_text,           4}, // 0x41
    {vm_overlay_setpos,         2}, // 0x42
    {vm_overlay_hide,           0}, // 0x43
    {vm_overlay_wait,           2}, // 0x44
    {vm_overlay_move_to,        3}, // 0x45
    {vm_overlay_show,           3}, // 0x46
    {vm_overlay_clear,          1}, // 0x47
    {vm_choice,                 3}, // 0x48
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},

    // gameboy features instructions section
    {vm_show_sprites,           0}, // 0x50
    {vm_hide_sprites,           0}, // 0x51

};
