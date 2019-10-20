TARGET := whetstone

C_SRCS := whets.c cpuidc.c
HEADERS :=config.h  cpuidh.h

CFLAGS := -O3 -funroll-loops  -fsingle-precision-constant -flto
LDFLAGS := -lm


BSP_BASE = ../../bsp
include $(BSP_BASE)/core/env/common.mk

