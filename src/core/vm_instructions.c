#include "vm.h"

#include "VM_Actor.h"
#include "VM_UI.h"

// here we define all VM instructions: their handlers and parameter lengths in bytes
// this array must be nonbanked as well as STEP_VM()
const SCRIPT_CMD script_cmds[] = {
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

    {vm_actor_move_to,          2}, // 0x1E
    {vm_load_text,              1}, // 0x1F
    {vm_display_text,           1}, // 0x20
    {vm_overlay_setpos,         2}, // 0x21
    {vm_overlay_hide,           0}, // 0x22
    {vm_overlay_wait,           0}, // 0x23
    {vm_overlay_move_to,        3}, // 0x24
    {vm_overlay_show,           3}, // 0x25
    {vm_overlay_clear,          1}, // 0x26
};
