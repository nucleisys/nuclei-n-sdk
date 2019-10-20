# 1 "/home/ws/nucleisys-n-sdk/bsp/core/env/entry.S"
# 1 "/home/ws/nucleisys-n-sdk/software/dhrystone//"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/home/ws/nucleisys-n-sdk/bsp/core/env/entry.S"





# 1 "/home/ws/nucleisys-n-sdk/bsp/core/drivers/riscv_encoding.h" 1
# 7 "/home/ws/nucleisys-n-sdk/bsp/core/env/entry.S" 2
# 1 "/home/ws/nucleisys-n-sdk/bsp/core/drivers/riscv_bits.h" 1
# 8 "/home/ws/nucleisys-n-sdk/bsp/core/env/entry.S" 2
# 1 "/home/ws/nucleisys-n-sdk/bsp/core/drivers/eclic.h" 1
# 9 "/home/ws/nucleisys-n-sdk/bsp/core/drivers/eclic.h"
# 1 "/home/ws/nucleisys-n-sdk/bsp/soc/drivers/soc.h" 1





# 1 "/home/ws/nucleisys-n-sdk/bsp/core/drivers/riscv_const.h" 1
# 7 "/home/ws/nucleisys-n-sdk/bsp/soc/drivers/soc.h" 2
# 1 "/home/ws/nucleisys-n-sdk/bsp/soc/drivers/gpio.h" 1
# 8 "/home/ws/nucleisys-n-sdk/bsp/soc/drivers/soc.h" 2
# 1 "/home/ws/nucleisys-n-sdk/bsp/soc/drivers/pwm.h" 1
# 9 "/home/ws/nucleisys-n-sdk/bsp/soc/drivers/soc.h" 2
# 1 "/home/ws/nucleisys-n-sdk/bsp/soc/drivers/spi.h" 1
# 10 "/home/ws/nucleisys-n-sdk/bsp/soc/drivers/soc.h" 2
# 1 "/home/ws/nucleisys-n-sdk/bsp/soc/drivers/uart.h" 1
# 11 "/home/ws/nucleisys-n-sdk/bsp/soc/drivers/soc.h" 2
# 1 "/home/ws/nucleisys-n-sdk/bsp/soc/drivers/i2c.h" 1
# 12 "/home/ws/nucleisys-n-sdk/bsp/soc/drivers/soc.h" 2

# 1 "/home/ws/nucleisys-n-sdk/bsp/soc/drivers/board.h" 1
# 14 "/home/ws/nucleisys-n-sdk/bsp/soc/drivers/soc.h" 2
# 10 "/home/ws/nucleisys-n-sdk/bsp/core/drivers/eclic.h" 2
# 9 "/home/ws/nucleisys-n-sdk/bsp/core/env/entry.S" 2
# 1 "/home/ws/nucleisys-n-sdk/bsp/core/drivers/timer.h" 1
# 10 "/home/ws/nucleisys-n-sdk/bsp/core/env/entry.S" 2


###############################################
###############################################
# Disable Interrupt

.macro DISABLE_MIE
  csrc 0x300, 0x00000008
.endm


###############################################
###############################################
#Save caller registers
.macro SAVE_CONTEXT
# 33 "/home/ws/nucleisys-n-sdk/bsp/core/env/entry.S"
  addi sp, sp, -20*(1 << 2)

  sw x1, 0*(1 << 2)(sp)
 sw x4, 1*(1 << 2)(sp)
 sw x5, 2*(1 << 2)(sp)
 sw x6, 3*(1 << 2)(sp)
 sw x7, 4*(1 << 2)(sp)
 sw x10, 5*(1 << 2)(sp)
 sw x11, 6*(1 << 2)(sp)
 sw x12, 7*(1 << 2)(sp)
 sw x13, 8*(1 << 2)(sp)
 sw x14, 9*(1 << 2)(sp)
 sw x15, 10*(1 << 2)(sp)

  sw x16, 11*(1 << 2)(sp)
 sw x17, 12*(1 << 2)(sp)
 sw x28, 13*(1 << 2)(sp)
 sw x29, 14*(1 << 2)(sp)
 sw x30, 15*(1 << 2)(sp)
 sw x31, 16*(1 << 2)(sp)
# 81 "/home/ws/nucleisys-n-sdk/bsp/core/env/entry.S"
.endm


###############################################
###############################################
#restore caller registers
.macro RESTORE_CONTEXT
  lw x1, 0*(1 << 2)(sp)
 lw x4, 1*(1 << 2)(sp)
 lw x5, 2*(1 << 2)(sp)
 lw x6, 3*(1 << 2)(sp)
 lw x7, 4*(1 << 2)(sp)
 lw x10, 5*(1 << 2)(sp)
 lw x11, 6*(1 << 2)(sp)
 lw x12, 7*(1 << 2)(sp)
 lw x13, 8*(1 << 2)(sp)
 lw x14, 9*(1 << 2)(sp)
 lw x15, 10*(1 << 2)(sp)

  lw x16, 11*(1 << 2)(sp)
 lw x17, 12*(1 << 2)(sp)
 lw x28, 13*(1 << 2)(sp)
 lw x29, 14*(1 << 2)(sp)
 lw x30, 15*(1 << 2)(sp)
 lw x31, 16*(1 << 2)(sp)
# 144 "/home/ws/nucleisys-n-sdk/bsp/core/env/entry.S"
 addi sp, sp, 20*(1 << 2)

.endm

###############################################
###############################################
#restore caller registers
.macro RESTORE_CONTEXT_EXCPT_X5
  lw x1, 0*(1 << 2)(sp)
  lw x6, 2*(1 << 2)(sp)
  lw x7, 3*(1 << 2)(sp)
  lw x10, 4*(1 << 2)(sp)
  lw x11, 5*(1 << 2)(sp)
  lw x12, 6*(1 << 2)(sp)
  lw x13, 7*(1 << 2)(sp)
  lw x14, 8*(1 << 2)(sp)
  lw x15, 9*(1 << 2)(sp)

  lw x16, 10*(1 << 2)(sp)
  lw x17, 11*(1 << 2)(sp)
  lw x28, 12*(1 << 2)(sp)
  lw x29, 13*(1 << 2)(sp)
  lw x30, 14*(1 << 2)(sp)
  lw x31, 15*(1 << 2)(sp)

.endm

###############################################
###############################################
#restore caller registers
.macro RESTORE_CONTEXT_ONLY_X5
  lw x5, 1*(1 << 2)(sp)
.endm

###############################################
###############################################
# Save the mepc and mstatus

.macro SAVE_EPC_STATUS
  csrr x5, 0x341
  sw x5, 16*(1 << 2)(sp)
  csrr x5, 0x300
  sw x5, 17*(1 << 2)(sp)
  csrr x5, 0x7c4
  sw x5, 18*(1 << 2)(sp)
.endm

###############################################
###############################################
# Restore the mepc and mstatus

.macro RESTORE_EPC_STATUS
  lw x5, 16*(1 << 2)(sp)
  csrw 0x341, x5
  lw x5, 17*(1 << 2)(sp)
  csrw 0x300, x5
  lw x5, 18*(1 << 2)(sp)
  csrw 0x7c4, x5
.endm



###############################################
###############################################


  .section .text.trap
  .align 6
  .global trap_entry
.weak trap_entry
trap_entry:




  SAVE_CONTEXT

  SAVE_EPC_STATUS


  csrr a0, mcause
  mv a1, sp

  call handle_trap


  RESTORE_EPC_STATUS

  RESTORE_CONTEXT




  mret


###############################################
###############################################


  .section .text.irq
  .align 2
  .global irq_entry
.weak irq_entry
irq_entry:



  SAVE_CONTEXT


  csrrwi x0, 0x7EE, 17

  csrrwi x0, 0x7EF, 18

  csrrwi x0, 0x7EB, 19

service_loop:



  csrrw ra, 0x7ED, ra



  #---- Critical section with interrupts disabled -----------------------
  DISABLE_MIE # Disable interrupts

  lw x5, 19*(1 << 2)(sp)
  csrw 0x7c4, x5
  lw x5, 18*(1 << 2)(sp)
  csrw 0x341, x5
  lw x5, 17*(1 << 2)(sp)
  csrw 0x342, x5


  RESTORE_CONTEXT



  mret
