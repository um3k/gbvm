#include <string.h>

#include "MusicManager.h"
#include "sample_player.h"
#include "BankData.h"
#include "vm.h"

#include "data/data_ptrs.h"

#define MAX_MUSIC 255
#define MASK_ALL_CHANNELS 0x0f

UBYTE current_index = MAX_MUSIC;
UBYTE tone_frames   = 0;
UBYTE channel_mask  = MASK_ALL_CHANNELS;
UBYTE sound_channel = 0;
#ifdef HUGE_TRACKER
    UBYTE current_track_bank = 0;
    UBYTE music_stopped      = TRUE;
    UBYTE huge_initialized   = FALSE;
#endif

// queue length must be power of 2 
#define MAX_ROUTINE_QUEUE_LEN 4 
// music events queue 
UBYTE routine_queue[MAX_ROUTINE_QUEUE_LEN];
UBYTE routine_queue_head = 0, routine_queue_tail = 0;
// music events struct
script_event_t music_events[4];

void music_init(UBYTE preserve) __banked {
    if (preserve) {
        for (UBYTE i = 0; i < 4; i++) 
            music_events[i].handle = 0;
    } else {
        memset(music_events, 0, sizeof(music_events));
    }
    __critical {
        routine_queue_head = routine_queue_tail = 0;
    }
}

#ifdef HUGE_TRACKER
void hUGETrackerRoutine(unsigned char ch, unsigned char param, unsigned char tick) __nonbanked {
    ch;
    if (tick) return; // return if not zero tick
    routine_queue_head++, routine_queue_head &= (MAX_ROUTINE_QUEUE_LEN - 1);
    if (routine_queue_head == routine_queue_tail) routine_queue_tail++, routine_queue_tail &= (MAX_ROUTINE_QUEUE_LEN - 1);  
    routine_queue[routine_queue_head] = param;    
}
#endif

void music_events_update() __nonbanked {
    while (routine_queue_head != routine_queue_tail) {
        UBYTE data;
        __critical {
            routine_queue_tail++, routine_queue_tail &= (MAX_ROUTINE_QUEUE_LEN - 1);
            data = routine_queue[routine_queue_tail];
        }
        script_event_t * event = &music_events[data & 0x03];
        if (!event->script_addr) return;
        if ((event->handle == 0) || ((event->handle & 0x8000) != 0))
            script_execute(event->script_bank, event->script_addr, &event->handle, 1, (UWORD)(data >> 4));
    }
}

void music_play(UBYTE index, UBYTE loop) __nonbanked {
    if (index == MAX_MUSIC) {
        music_stop();
    } else if (index != current_index) {
        channel_mask = MASK_ALL_CHANNELS;
#ifdef GBT_PLAYER
        UBYTE _save = _current_bank;
        __critical {
            gbt_play(music_tracks[index].ptr, music_tracks[index].bank, 7);
            gbt_loop(loop);
            SWITCH_ROM_MBC1(_save);
            music_mute(channel_mask);
        }
#endif
#ifdef HUGE_TRACKER
        loop;
        UBYTE _save = _current_bank;
        current_track_bank = music_tracks[index].bank;
        __critical {
            music_stop();
            SWITCH_ROM_MBC1(current_track_bank);
            hUGE_init(music_tracks[index].ptr);
            SWITCH_ROM_MBC1(_save);
            huge_initialized = TRUE;
            music_mute(channel_mask);
            music_stopped = FALSE;        
        }
#endif
        current_index = index;
    } else {
#ifdef SAME_TUNE_RESTARTS
        // restart current song from beginning
        music_stop();
        music_play(index, loop);
#endif
    }
}

void music_stop() __banked {
#ifdef GBT_PLAYER
    UBYTE _save = _current_bank;
    gbt_stop();
    SWITCH_ROM_MBC1(_save);
#endif
#ifdef HUGE_TRACKER
    music_stopped = TRUE;
    music_mute(0);
#endif
    current_index = MAX_MUSIC;
}

void music_mute(UBYTE channels) __nonbanked {
#ifdef GBT_PLAYER
    UBYTE _save = _current_bank;
    gbt_enable_channels(channels);
    SWITCH_ROM_MBC1(_save);
#endif
#ifdef HUGE_TRACKER
    if (huge_initialized) 
        for (UBYTE i = HT_CH1, ch = ~channels; i <= HT_CH4; i++, ch >>= 1) 
            hUGE_mute_channel(i, ch & 1);
#endif
}

UINT8 ISR_counter = 0;
void music_update() __nonbanked __naked {
__asm
        call _sample_play_isr
        ld hl, #_ISR_counter
        ld a, (hl)
        inc a
        and #0x03
        ld (hl), a
        ret nz
        
        ld hl, #_tone_frames
        ld a, (hl)
        or a
        jr z, 1$
        dec a
        ld (hl), a
        jr nz, 1$
        ld a, (_sound_channel)
        push af
        inc sp
        call _sound_stop
        ld a, (_channel_mask)
        push af
        inc sp
        call _music_mute
        pop hl
1$:
#ifdef GBT_PLAYER
        ldh a, (__current_bank)
        push af
        call _gbt_update
        pop af
        ld (0x2000), a
#endif
#ifdef HUGE_TRACKER
        ld a, (_music_stopped)
        or a
        ret nz
        ld a, (_current_track_bank)
        ld e, a
        or a
        ret z
        ldh a, (__current_bank)
        push af
        ld a, e
        ldh (__current_bank), a
        ld (0x2000), a
        call _hUGE_dosound
        pop af
        ldh (__current_bank), a
        ld (0x2000), a
#endif
        ret
__endasm;
}

const UINT8 FX_REG_SIZES[]  = {5, 4, 5, 4};
const UINT8 FX_ADDR_LO[]    = {0x10, 0x16, 0x1a, 0x20};
const UINT8 channel_masks[] = {0x0e, 0x0d, 0x0b, 0x07};

void wave_play(UBYTE frames, UBYTE bank, UBYTE * sample, UWORD size) __banked {
    if (tone_frames) return;                        // exit if sound is already playing.
    if (frames == 0) return;                        // exit if length in frames is zero
    music_mute(channel_mask & channel_masks[2]);
    set_sample(bank, sample, size);
    tone_frames = frames;
}

void sound_play(UBYTE frames, UBYTE channel, UBYTE * data) __banked {
    if (tone_frames) return;                        // exit if sound is already playing.
    if (frames == 0) return;                        // exit if length in frames is zero
    if ((channel == 0) || (channel > 4)) return;    // exit if channel is out of bounds
    UBYTE ch = channel - 1;
    music_mute(channel_mask & channel_masks[ch]);
    UBYTE * reg = (UBYTE *)0xFF00 + FX_ADDR_LO[ch];
    for (UBYTE i = FX_REG_SIZES[ch], *p = data; i != 0; i--) *reg++ = *p++;
    sound_channel = channel;
    tone_frames = frames;
}

void sound_stop(UBYTE channel) __banked {
    switch (channel) {
        case 1: NR12_REG = 0x00; break; 
        case 2: NR22_REG = 0x00; break; 
        case 3: NR32_REG = 0x00; break;         // set volume 0 
        case 4: NR42_REG = 0x00; break;         // would that work?
    }
}
