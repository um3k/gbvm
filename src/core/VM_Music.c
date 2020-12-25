#pragma bank 2

#include <stdarg.h>

#include "VM_Music.h"
#include "MusicManager.h"

void vm_music_play(SCRIPT_CTX * THIS, UBYTE track, UBYTE loop) __banked {
    THIS;
    MusicPlay(track, loop);
}

void vm_music_stop() __banked {
    MusicStop();
}

void vm_music_mute(SCRIPT_CTX * THIS, UBYTE channels) __banked {
    THIS;
    MusicMute(channels);
    channel_mask = channels;
}

void vm_sound_mastervol(SCRIPT_CTX * THIS, UBYTE volume) __banked {
    THIS;
    NR50_REG = volume;
}

void vm_sound_play(SCRIPT_CTX * THIS, UBYTE frames, UBYTE channel, ...) __banked {
    THIS;
    va_list va;
    va_start(va, channel);              // actually, always 5 parameters are passed as varargs
    SoundPlay(frames, channel, va);
}