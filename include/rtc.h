#ifndef _RTC_H_INCLUDE
#define _RTC_H_INCLUDE

#include <gb/gb.h>

volatile UBYTE __at(0x4000) RTC_SELECT_REG;
volatile UBYTE __at(0x6000) RTC_LATCH_REG;
volatile UBYTE __at(0xA000) RTC_VALUE_REG;

#define RTC_TIMER_STOP 0b01000000

typedef enum {
    RTC_VALUE_SEC = 0x08,
    RTC_VALUE_MIN,
    RTC_VALUE_HOUR,
    RTC_VALUE_DAY 
} rtc_dateparts_e;

#define RTC_VALUE_FLAGS 0x0c

inline void RTC_LATCH() { RTC_LATCH_REG = 0; RTC_LATCH_REG = 1; }

inline UWORD RTC_GET(rtc_dateparts_e part) {
    UWORD v;
    RTC_SELECT_REG = part;
    v = RTC_VALUE_REG;
    if (part == RTC_VALUE_DAY) {
        RTC_SELECT_REG = RTC_VALUE_FLAGS;
        if (RTC_VALUE_REG & 0x01) v |= 0x0100u;
    }
    return v;
}

inline void RTC_SET(rtc_dateparts_e part, UWORD v) {
    RTC_SELECT_REG = part;
    RTC_VALUE_REG = v;
    if (part == RTC_VALUE_DAY) {
        RTC_SELECT_REG = RTC_VALUE_FLAGS;
        RTC_VALUE_REG = (RTC_VALUE_REG & 0x0e) | (UBYTE)((v >> 8) & 0x01);     
    }
}

inline void RTC_START(UBYTE start) {
    RTC_SELECT_REG = RTC_VALUE_FLAGS;
    if (start) RTC_VALUE_REG &= ~RTC_TIMER_STOP; else RTC_VALUE_REG |= RTC_TIMER_STOP;
}

#endif