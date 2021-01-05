#pragma bank 2

#include <stdarg.h>

#include "VM_Music.h"
#include "MusicManager.h"

void vm_music_play(SCRIPT_CTX * THIS, UBYTE track, UBYTE loop) __banked {
    THIS;
    music_play(track, loop);
}

void vm_music_stop() __banked {
    music_stop();
}

void vm_music_mute(SCRIPT_CTX * THIS, UBYTE channels) __banked {
    THIS;
    music_mute(channels);
    channel_mask = channels;
}

void vm_music_routine(SCRIPT_CTX * THIS, UBYTE routine, UBYTE bank, UBYTE * pc) __banked {
    THIS;
    script_event_t * event = &music_events[routine & 0x03];
    event->script_bank = bank; 
    event->script_addr = pc;
}

void vm_sound_mastervol(SCRIPT_CTX * THIS, UBYTE volume) __banked {
    THIS;
    NR50_REG = volume;
}

void vm_sound_play(SCRIPT_CTX * THIS, UBYTE frames, UBYTE channel, ...) __banked {
    THIS;
    va_list va;
    va_start(va, channel);              // actually, always 5 parameters are passed as varargs
    sound_play(frames, channel, va);
}
