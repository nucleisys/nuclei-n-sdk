	.file	"dhry_stubs.c"
	.option nopic
	.attribute arch, "rv32i2p0_m2p0_a2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.text.csr_cycle,"ax",@progbits
	.align	1
	.align	2
	.globl	csr_cycle
	.type	csr_cycle, @function
csr_cycle:
.LFB0:
	.file 1 "dhry_stubs.c"
	.loc 1 6 1
	.cfi_startproc
	.loc 1 7 3
	.loc 1 7 10 is_stmt 0
	tail	get_cycle_value
.LVL0:
	.cfi_endproc
.LFE0:
	.size	csr_cycle, .-csr_cycle
	.section	.text.csr_instret,"ax",@progbits
	.align	1
	.align	2
	.globl	csr_instret
	.type	csr_instret, @function
csr_instret:
.LFB1:
	.loc 1 11 1 is_stmt 1
	.cfi_startproc
	.loc 1 12 3
	.loc 1 12 10 is_stmt 0
	tail	get_instret_value
.LVL1:
	.cfi_endproc
.LFE1:
	.size	csr_instret, .-csr_instret
	.section	.text.time,"ax",@progbits
	.align	1
	.align	2
	.globl	time
	.type	time, @function
time:
.LFB2:
	.loc 1 16 1 is_stmt 1
	.cfi_startproc
	.loc 1 17 3
	.loc 1 16 1 is_stmt 0
	addi	sp,sp,-16
	.cfi_def_cfa_offset 16
	sw	ra,12(sp)
	sw	s0,8(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	.loc 1 17 10
	call	get_timer_value
.LVL2:
	mv	s0,a0
	.loc 1 17 30
	call	get_timer_freq
.LVL3:
	.loc 1 18 1
	div	a0,s0,a0
	lw	ra,12(sp)
	.cfi_restore 1
	lw	s0,8(sp)
	.cfi_restore 8
	addi	sp,sp,16
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE2:
	.size	time, .-time
	.text
.Letext0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.4byte	0x15c
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
	.4byte	.LASF12
	.byte	0x1
	.byte	0xf
	.byte	0x6
	.4byte	0x41
	.4byte	.LFB2
	.4byte	.LFE2-.LFB2
	.byte	0x1
	.byte	0x9c
	.4byte	0xc3
	.byte	0x5
	.4byte	.LASF10
	.byte	0x1
	.byte	0x11
	.byte	0xa
	.4byte	0x5d
	.4byte	0x9e
	.byte	0x6
	.byte	0
	.byte	0x5
	.4byte	.LASF11
	.byte	0x1
	.byte	0x11
	.byte	0x1e
	.4byte	0x5d
	.4byte	0xb0
	.byte	0x6
	.byte	0
	.byte	0x7
	.4byte	.LVL2
	.4byte	0x12f
	.byte	0x7
	.4byte	.LVL3
	.4byte	0x13b
	.byte	0
	.byte	0x4
	.4byte	.LASF13
	.byte	0x1
	.byte	0xa
	.byte	0x6
	.4byte	0x41
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.byte	0x1
	.byte	0x9c
	.4byte	0xf9
	.byte	0x5
	.4byte	.LASF14
	.byte	0x1
	.byte	0xc
	.byte	0xa
	.4byte	0x5d
	.4byte	0xef
	.byte	0x6
	.byte	0
	.byte	0x8
	.4byte	.LVL1
	.4byte	0x147
	.byte	0
	.byte	0x4
	.4byte	.LASF15
	.byte	0x1
	.byte	0x5
	.byte	0x6
	.4byte	0x41
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.byte	0x1
	.byte	0x9c
	.4byte	0x12f
	.byte	0x5
	.4byte	.LASF16
	.byte	0x1
	.byte	0x7
	.byte	0xa
	.4byte	0x5d
	.4byte	0x125
	.byte	0x6
	.byte	0
	.byte	0x8
	.4byte	.LVL0
	.4byte	0x153
	.byte	0
	.byte	0x9
	.4byte	.LASF10
	.4byte	.LASF10
	.byte	0x1
	.byte	0x11
	.byte	0xa
	.byte	0x9
	.4byte	.LASF11
	.4byte	.LASF11
	.byte	0x1
	.byte	0x11
	.byte	0x1e
	.byte	0x9
	.4byte	.LASF14
	.4byte	.LASF14
	.byte	0x1
	.byte	0xc
	.byte	0xa
	.byte	0x9
	.4byte	.LASF16
	.4byte	.LASF16
	.byte	0x1
	.byte	0x7
	.byte	0xa
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
	.byte	0x1
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0x5
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
	.byte	0x49
	.byte	0x13
	.byte	0x3c
	.byte	0x19
	.byte	0x1
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0x6
	.byte	0x18
	.byte	0
	.byte	0
	.byte	0
	.byte	0x7
	.byte	0x89,0x82,0x1
	.byte	0
	.byte	0x11
	.byte	0x1
	.byte	0x31
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0x8
	.byte	0x89,0x82,0x1
	.byte	0
	.byte	0x11
	.byte	0x1
	.byte	0x95,0x42
	.byte	0x19
	.byte	0x31
	.byte	0x13
	.byte	0
	.byte	0
	.byte	0x9
	.byte	0x2e
	.byte	0
	.byte	0x3f
	.byte	0x19
	.byte	0x3c
	.byte	0x19
	.byte	0x6e
	.byte	0xe
	.byte	0x3
	.byte	0xe
	.byte	0x3a
	.byte	0xb
	.byte	0x3b
	.byte	0xb
	.byte	0x39
	.byte	0xb
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.4byte	0x2c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.4byte	.LFB2
	.4byte	.LFE2-.LFB2
	.4byte	0
	.4byte	0
	.section	.debug_ranges,"",@progbits
.Ldebug_ranges0:
	.4byte	.LFB0
	.4byte	.LFE0
	.4byte	.LFB1
	.4byte	.LFE1
	.4byte	.LFB2
	.4byte	.LFE2
	.4byte	0
	.4byte	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF10:
	.string	"get_timer_value"
.LASF8:
	.string	"unsigned int"
.LASF11:
	.string	"get_timer_freq"
.LASF1:
	.string	"unsigned char"
.LASF5:
	.string	"long unsigned int"
.LASF3:
	.string	"short unsigned int"
.LASF15:
	.string	"csr_cycle"
.LASF13:
	.string	"csr_instret"
.LASF19:
	.string	"/home/ws/nucleisys-n-sdk/software/dhrystone"
.LASF14:
	.string	"get_instret_value"
.LASF18:
	.string	"dhry_stubs.c"
.LASF7:
	.string	"long long unsigned int"
.LASF12:
	.string	"time"
.LASF16:
	.string	"get_cycle_value"
.LASF6:
	.string	"long long int"
.LASF2:
	.string	"short int"
.LASF4:
	.string	"long int"
.LASF17:
	.string	"GNU C17 9.2.0 -mexplicit-relocs -march=rv32imac -mabi=ilp32 -mcmodel=medlow -mtune=rocket -g -O3 -fno-inline -funroll-loops -fno-builtin-printf -falign-functions=4 -falign-jumps=4 -falign-loops=4 -ffunction-sections -fdata-sections -fno-common"
.LASF9:
	.string	"long double"
.LASF0:
	.string	"signed char"
	.ident	"GCC: (GNU) 9.2.0"
