
@{{BLOCK(Cart)

@=======================================================================
@
@	Cart, 32x32@8, 
@	+ palette 256 entries, not compressed
@	+ 16 tiles Metatiled by 4x4 not compressed
@	Total size: 512 + 1024 = 1536
@
@	Time-stamp: 2022-03-12, 16:30:17
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.17
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global CartTiles		@ 1024 unsigned chars
	.hidden CartTiles
CartTiles:
	.word 0x03030000,0x03030303,0x05030000,0x05050505,0x05030000,0x04040404,0x05030000,0x04040304
	.word 0x05030000,0x04040304,0x05030000,0x04040404,0x05030000,0x04040404,0x05030000,0x04040404
	.word 0x03030303,0x00000303,0x05050505,0x00000302,0x05040404,0x00000302,0x05040403,0x00000302
	.word 0x05040403,0x00000302,0x05040404,0x00000302,0x05040404,0x00000302,0x05040403,0x00000302
	.word 0x03030000,0x03030303,0x05030000,0x05050505,0x05030000,0x04040404,0x05030000,0x04040304
	.word 0x05030000,0x04040304,0x05030000,0x04040404,0x05030000,0x04040404,0x05030000,0x04040404
	.word 0x03030303,0x00000303,0x05050505,0x00000302,0x05040404,0x00000302,0x05040403,0x00000302
	.word 0x05040403,0x00000302,0x05040404,0x00000302,0x05040404,0x00000302,0x05040403,0x00000302

	.word 0x05030000,0x03030404,0x05030000,0x04040404,0x05030000,0x05050505,0x03030000,0x03030303
	.word 0x00000000,0x00000003,0x00000000,0x00030300,0x00000000,0x03010103,0x00000000,0x03010103
	.word 0x05040404,0x00000302,0x05040404,0x00000302,0x05050505,0x00000302,0x03030303,0x00000303
	.word 0x00030000,0x00000000,0x00000303,0x00000000,0x00030101,0x00000000,0x00030101,0x00000000
	.word 0x05030000,0x03030404,0x05030000,0x04040404,0x05030000,0x05050505,0x03030000,0x03030303
	.word 0x03000000,0x00000000,0x03030000,0x00000000,0x01010300,0x00000003,0x01010300,0x00000003
	.word 0x05040404,0x00000302,0x05040404,0x00000302,0x05050505,0x00000302,0x03030303,0x00000303
	.word 0x03000000,0x00000000,0x03000000,0x00000003,0x01030000,0x00000301,0x01030000,0x00000301

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global CartPal		@ 512 unsigned chars
	.hidden CartPal
CartPal:
	.hword 0x0000,0x5EF7,0x1084,0x0421,0x6F7B,0x14A5,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(Cart)
