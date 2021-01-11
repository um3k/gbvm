        .include        "global.s"

        .globl  _parallax_LCD_isr

        .area   _HEADER_PARALLAX (ABS)

	.org	0x48		; LCD

	jp	_parallax_LCD_isr
