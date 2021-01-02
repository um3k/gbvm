#include "MusicManager.h"
#include "BankData.h"

#ifdef GBT_PLAYER
    #undef HUGE_TRACKER 
    #include "gbt_player.h"
#endif
#ifdef HUGE_TRACKER
    #undef GBT_PLAYER
    #include "hUGEDriver.h"
#endif

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
#endif

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
            SWITCH_ROM_MBC1(current_track_bank);
            hUGE_init(music_tracks[index].ptr);
            SWITCH_ROM_MBC1(_save);
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
    if (music_stopped) return;
    for (UBYTE i = HT_CH1, ch = channels; i <= HT_CH4; i++, ch >>= 1) 
        hUGE_mute_channel(i, !(ch & 1));
#endif
}

void music_update() __nonbanked {
    if (tone_frames) {
        if (--tone_frames == 0) {
            sound_stop(sound_channel);
            music_mute(channel_mask);
            sound_channel = 0;
        }
    }
#ifdef GBT_PLAYER 
    UBYTE _save = _current_bank;
    gbt_update();
    SWITCH_ROM_MBC1(_save);
#endif
#ifdef HUGE_TRACKER
    if (music_stopped) return;
    if (current_track_bank == 0) return;
    UBYTE _save = _current_bank;
    SWITCH_ROM_MBC1(current_track_bank);
    hUGE_dosound();
    SWITCH_ROM_MBC1(_save);
#endif
}

const UINT8 FX_REG_SIZES[]  = {5, 4, 5, 4};
const UINT8 FX_ADDR_LO[]    = {0x10, 0x16, 0x1a, 0x20};
const UINT8 channel_masks[] = {0x0e, 0x0d, 0x0b, 0x07};

void sound_play(UBYTE frames, UBYTE channel, UBYTE * data) __banked {
    if (frames == 0) return;                        // exit if length in frames is zero
    if (tone_frames) return;                        // exit if sound is already playing.
    if ((channel == 0) || (channel > 4)) return;    // exit if channel is out of bounds
    sound_channel = channel - 1;
    music_mute(channel_mask & channel_masks[sound_channel]);
    UBYTE * reg = (UBYTE *)0xFF00 + FX_ADDR_LO[sound_channel];
    for (UBYTE i = FX_REG_SIZES[sound_channel], *p = data; i != 0; i--) *reg++ = *p++;
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
