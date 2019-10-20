# 1 "dhry_stubs.c"
# 1 "/home/ws/nucleisys-n-sdk/software/dhrystone//"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/sys/cdefs.h" 1 3
# 43 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/sys/cdefs.h" 3
# 1 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/machine/_default_types.h" 1 3







# 1 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/sys/features.h" 1 3
# 28 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/sys/features.h" 3
# 1 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/_newlib_version.h" 1 3
# 29 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/sys/features.h" 2 3
# 9 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/machine/_default_types.h" 2 3
# 41 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/machine/_default_types.h" 3

# 41 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/machine/_default_types.h" 3
typedef signed char __int8_t;

typedef unsigned char __uint8_t;
# 55 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/machine/_default_types.h" 3
typedef short int __int16_t;

typedef short unsigned int __uint16_t;
# 77 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/machine/_default_types.h" 3
typedef long int __int32_t;

typedef long unsigned int __uint32_t;
# 103 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/machine/_default_types.h" 3
typedef long long int __int64_t;

typedef long long unsigned int __uint64_t;
# 134 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/machine/_default_types.h" 3
typedef signed char __int_least8_t;

typedef unsigned char __uint_least8_t;
# 160 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/machine/_default_types.h" 3
typedef short int __int_least16_t;

typedef short unsigned int __uint_least16_t;
# 182 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/machine/_default_types.h" 3
typedef long int __int_least32_t;

typedef long unsigned int __uint_least32_t;
# 200 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/machine/_default_types.h" 3
typedef long long int __int_least64_t;

typedef long long unsigned int __uint_least64_t;
# 214 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/machine/_default_types.h" 3
typedef long long int __intmax_t;







typedef long long unsigned int __uintmax_t;







typedef int __intptr_t;

typedef unsigned int __uintptr_t;
# 44 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/sys/cdefs.h" 2 3

# 1 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/lib/gcc/riscv-nuclei-elf/9.2.0/include/stddef.h" 1 3 4
# 143 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/lib/gcc/riscv-nuclei-elf/9.2.0/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 209 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/lib/gcc/riscv-nuclei-elf/9.2.0/include/stddef.h" 3 4
typedef unsigned int size_t;
# 321 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/lib/gcc/riscv-nuclei-elf/9.2.0/include/stddef.h" 3 4
typedef int wchar_t;
# 415 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/lib/gcc/riscv-nuclei-elf/9.2.0/include/stddef.h" 3 4
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
# 426 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/lib/gcc/riscv-nuclei-elf/9.2.0/include/stddef.h" 3 4
} max_align_t;
# 46 "/home/ws/gnu-mcu-eclipse/riscv-none-gcc/rv_linux_bare_1910081810/riscv-nuclei-elf/include/sys/cdefs.h" 2 3
# 32 "<command-line>" 2
# 1 "dhry_stubs.c"





# 5 "dhry_stubs.c"
long csr_cycle(void)
{
  return get_cycle_value();
}

long csr_instret(void)
{
  return get_instret_value();
}

long time(void)
{
  return get_timer_value() / get_timer_freq();
}
