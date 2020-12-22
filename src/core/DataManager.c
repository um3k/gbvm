#include "DataManager.h"

void load_tiles(const tileset_t* tiles, UBYTE bank) {
  UBYTE _save = _current_bank;  
  SWITCH_ROM_MBC1(bank);
  set_bkg_data(0, tiles->n_tiles, tiles->tiles);
  SWITCH_ROM_MBC1(_save);      
}
