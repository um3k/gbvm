#pragma bank 1

#include "LoadSave.h"

#include "vm.h"
#include "events.h"

UBYTE data_is_saved() __banked {
    SWITCH_RAM_MBC5(0);
    return FALSE;
}

void data_save() __banked {
    SWITCH_RAM_MBC5(0);
}

UBYTE data_load() __banked {
    if (!data_is_saved()) return;
    SWITCH_RAM_MBC5(0);

    return TRUE;
}