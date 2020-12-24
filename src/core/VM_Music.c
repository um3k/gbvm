#pragma bank 2

#include "VM_Music.h"
#include "MusicManager.h"

void vm_music_play(SCRIPT_CTX * THIS, UBYTE track, UBYTE loop) __banked {
    THIS;
    MusicPlay(track, loop);
}

void vm_music_stop() __banked {
    MusicStop();
}
