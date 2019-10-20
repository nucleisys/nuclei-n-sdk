# 1 "/home/ws/nucleisys-n-sdk/bsp/core/env/start.S"
# 1 "/home/ws/nucleisys-n-sdk/software/dhrystone//"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/home/ws/nucleisys-n-sdk/bsp/core/env/start.S"


# 1 "/home/ws/nucleisys-n-sdk/bsp/core/drivers/riscv_encoding.h" 1
# 4 "/home/ws/nucleisys-n-sdk/bsp/core/env/start.S" 2

 .section .init

 .globl _start
 .type _start,@function
_start:
 csrc 0x300, 0x00000008

     li t0, (0x1 << 9);
     csrs 0x7d0, t0


     la t0, vector_base
     csrw 0x307, t0


     la t0, irq_entry
     csrw 0x7EC, t0
     csrs 0x7EC, 0x1


     la t0, trap_entry
     csrw 0x305, t0
# 36 "/home/ws/nucleisys-n-sdk/bsp/core/env/start.S"
     .option push
     .option norelax
 la gp, __global_pointer$
     .option pop
 la sp, _sp


 la a0, _ilm_lma
 la a1, _ilm
        beq a0, a1, 2f
 la a2, _eilm
 bgeu a1, a2, 2f
1:
 lw t0, (a0)
 sw t0, (a1)
 addi a0, a0, 4
 addi a1, a1, 4
 bltu a1, a2, 1b
2:


 la a0, _data_lma
 la a1, _data
 la a2, _edata
 bgeu a1, a2, 2f
1:
 lw t0, (a0)
 sw t0, (a1)
 addi a0, a0, 4
 addi a1, a1, 4
 bltu a1, a2, 1b
2:


 la a0, __bss_start
 la a1, _end
 bgeu a0, a1, 2f
1:
 sw zero, (a0)
 addi a0, a0, 4
 bltu a0, a1, 1b
2:

        csrci 0x320, 0x5

 la a0, __libc_fini_array
 call atexit
 call __libc_init_array



 li a0, 0
 li a1, 0
 call main
 tail exit

1:
 j 1b

 .global disable_mcycle_minstret
disable_mcycle_minstret:
        csrsi 0x320, 0x5
 ret

 .global enable_mcycle_minstret
enable_mcycle_minstret:
        csrci 0x320, 0x5
 ret

 .global core_wfe
core_wfe:
     csrc 0x300, 0x00000008
     csrs 0x810, 0x1
     wfi
     csrc 0x810, 0x1
     csrs 0x300, 0x00000008
 ret
