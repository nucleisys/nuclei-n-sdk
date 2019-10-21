TARGET = demo_dsp
CFLAGS += -Os -msave-restore  -fno-unroll-loops -flto

BSP_BASE = ../../bsp

C_SRCS += demo_dsp.c
LDFLAGS +=-L. -lnmsis_dsp_rv32imafdcp -lm
INCLUDES += -Iinclude


include $(BSP_BASE)/core/env/common.mk
