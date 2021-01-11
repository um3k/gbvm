        .include        "global.s"

        .globl  .int

        .area   _HEADER_TIMER (ABS)

        .globl  _music_update

        .org    0x50            ; TIM
        ei
        jp      _music_update
