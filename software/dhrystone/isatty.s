	.file	"isatty.c"
	.option nopic
	.attribute arch, "rv32i2p0_m2p0_a2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.text._isatty,"ax",@progbits
	.align	1
	.align	2
	.globl	_isatty
	.type	_isatty, @function
_isatty:
.LFB0:
	.file 1 "/home/ws/nucleisys-n-sdk/bsp/core/stubs/isatty.c"
	.loc 1 6 1
	.cfi_startproc
.LVL0:
	.loc 1 7 3
	.loc 1 7 26 is_stmt 0
	addi	a0,a0,-1
.LVL1:
	.loc 1 11 1
	sltiu	a0,a0,2
.LVL2:
	ret
	.cfi_endproc
.LFE0:
	.size	_isatty, .-_isatty
	.text
.Letext0:
	.file 2 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/sys/unistd.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.4byte	0xf0
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.byte	0x1
	.4byte	.LASF17
	.byte	0xc
	.4byte	.LASF18
	.4byte	.LASF19
	.4byte	.Ldebug_ranges0+0
	.4byte	0
	.4byte	.Ldebug_line0
	.byte	0x2
	.byte	0x1
	.byte	0x6
	.4byte	.LASF0
	.byte	0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF1
	.byte	0x2
	.byte	0x2
	.byte	0x5
	.4byte	.LASF2
	.byte	0x2
	.byte	0x2
	.byte	0x7
	.4byte	.LASF3
	.byte	0x2
	.byte	0x4
	.byte	0x5
	.4byte	.LASF4
	.byte	0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF5
	.byte	0x2
	.byte	0x8
	.byte	0x5
	.4byte	.LASF6
	.byte	0x2
	.byte	0x8
	.byte	0x7
	.4byte	.LASF7
	.byte	0x3
	.byte	0x4
	.byte	0x5
	.string	"int"
	.byte	0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF8
	.byte	0x2
	.byte	0x10
	.byte	0x4
	.4byte	.LASF9
	.byte	0x4
	.byte	0x4
	.4byte	0x78
	.byte	0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF10
	.byte	0x5
	.4byte	.LASF11
	.byte	0x2
	.byte	0x10
	.byte	0xf
	.4byte	0x8b
	.byte	0x4
	.byte	0x4
	.4byte	0x72
	.byte	0x5
	.4byte	.LASF12
	.byte	0x2
	.byte	0xfc
	.byte	0xe
	.4byte	0x72
	.byte	0x5
	.4byte	.LASF13
	.byte	0x2
	.byte	0xfd
	.byte	0xc
	.4byte	0x5d
	.byte	0x5
	.4byte	.LASF14
	.byte	0x2
	.byte	0xfd
	.byte	0x14
	.4byte	0x5d
	.byte	0x5
	.4byte	.LASF15
	.byte	0x2
	.byte	0xfd
	.byte	0x1c
	.4byte	0x5d
	.byte	0x5
	.4byte	.LASF16
	.byte	0x2
	.byte	0xff
	.byte	0xc
	.4byte	0x5d
	.byte	0x6
	.4byte	.LASF20
	.byte	0x1
	.byte	0x5
	.byte	0x5
	.4byte	0x5d
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.byte	0x1
	.byte	0x9c
	.byte	0x7
	.string	"fd"
	.byte	0x1
	.byte	0x5
	.byte	0x11
	.4byte	0x5d
	.4byte	.LLST0
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.byte	0x1
	.byte	0x11
	.byte	0x1
	.byte	0x25
	.byte	0xe
	.byte	0x13
	.byte	0xb
	.byte	0x3
	.byte	0xe
	.byte	0x1b
	.byte	0xe
	.byte	0x55
	.byte	0x17
	.byte	0x11
	.byte	0x1
	.byte	0x10
	.byte	0x17
	.byte	0
	.byte	0
	.byte	0x2
	.byte	0x24
	.byte	0
	.byte	0xb
	.byte	0xb
	.byte	0x3e
	.byte	0xb
	.byte	0x3
	.byte	0xe
	.byte	0
	.byte	0
	.byte	0x3
	.byte	0x24
	.byte	0
	.byte	0xb
	.byte	0xb
	.byte	0x3e
	.byte	0xb
	.byte	0x3
	.byte	0x8
	.byte	0
	.byte	0
	.byte	0x4
	.byte	0xf
	.byte	0
	.byte	0xb
	.byte	0xb
	.byte	0x49
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0x5
	.byte	0x34
	.byte	0
	.byte	0x3
	.byte	0xe
	.byte	0x3a
	.byte	0xb
	.byte	0x3b
	.byte	0xb
	.byte	0x39
	.byte	0xb
	.byte	0x49
	.byte	0x13
	.byte	0x3f
	.byte	0x19
	.byte	0x3c
	.byte	0x19
	.byte	0
	.byte	0
	.byte	0x6
	.byte	0x2e
	.byte	0x1
	.byte	0x3f
	.byte	0x19
	.byte	0x3
	.byte	0xe
	.byte	0x3a
	.byte	0xb
	.byte	0x3b
	.byte	0xb
	.byte	0x39
	.byte	0xb
	.byte	0x27
	.byte	0x19
	.byte	0x49
	.byte	0x13
	.byte	0x11
	.byte	0x1
	.byte	0x12
	.byte	0x6
	.byte	0x40
	.byte	0x18
	.byte	0x97,0x42
	.byte	0x19
	.byte	0
	.byte	0
	.byte	0x7
	.byte	0x5
	.byte	0
	.byte	0x3
	.byte	0x8
	.byte	0x3a
	.byte	0xb
	.byte	0x3b
	.byte	0xb
	.byte	0x39
	.byte	0xb
	.byte	0x49
	.byte	0x13
	.byte	0x2
	.byte	0x17
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
.LLST0:
	.4byte	.LVL0
	.4byte	.LVL1
	.2byte	0x1
	.byte	0x5a
	.4byte	.LVL1
	.4byte	.LVL2
	.2byte	0x3
	.byte	0x7a
	.byte	0x1
	.byte	0x9f
	.4byte	.LVL2
	.4byte	.LFE0
	.2byte	0x4
	.byte	0xf3
	.byte	0x1
	.byte	0x5a
	.byte	0x9f
	.4byte	0
	.4byte	0
	.section	.debug_aranges,"",@progbits
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.4byte	0
	.4byte	0
	.section	.debug_ranges,"",@progbits
.Ldebug_ranges0:
	.4byte	.LFB0
	.4byte	.LFE0
	.4byte	0
	.4byte	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF6:
	.string	"long long int"
.LASF8:
	.string	"unsigned int"
.LASF13:
	.string	"optind"
.LASF17:
	.string	"GNU C17 9.2.0 -mexplicit-relocs -march=rv32imac -mabi=ilp32 -mcmodel=medlow -mtune=rocket -g -O3 -fno-inline -funroll-loops -fno-builtin-printf -falign-functions=4 -falign-jumps=4 -falign-loops=4 -ffunction-sections -fdata-sections -fno-common"
.LASF5:
	.string	"long unsigned int"
.LASF7:
	.string	"long long unsigned int"
.LASF19:
	.string	"/home/ws/nucleisys-n-sdk/software/dhrystone"
.LASF14:
	.string	"opterr"
.LASF1:
	.string	"unsigned char"
.LASF10:
	.string	"char"
.LASF4:
	.string	"long int"
.LASF15:
	.string	"optopt"
.LASF3:
	.string	"short unsigned int"
.LASF16:
	.string	"optreset"
.LASF18:
	.string	"/home/ws/nucleisys-n-sdk/bsp/core/stubs/isatty.c"
.LASF9:
	.string	"long double"
.LASF20:
	.string	"_isatty"
.LASF12:
	.string	"optarg"
.LASF2:
	.string	"short int"
.LASF11:
	.string	"environ"
.LASF0:
	.string	"signed char"
	.ident	"GCC: (GNU) 9.2.0"
