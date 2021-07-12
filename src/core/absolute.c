#include "gbs_types.h"

OAM_item_t __at(0xDF00) shadow_OAM2[40];        // 160 bytes
palette_entry_t __at(0xDFA0) BkgPalette[8];     // 64 bytes
UBYTE __at(0xDFE0) vwf_tile_data[16 * 2];       // 32 bytes
                                                // --------
                                                // 256 bytes total
