/**************************************************************************//**
 * @file     cmsis_gcc.h
 * @brief    NMSIS compiler GCC header file
 * @version  V1.0.0
 * @date     18. October 2019
 ******************************************************************************/

#ifndef __NMSIS_GCC_H
#define __NMSIS_GCC_H

/* ignore some GCC warnings */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wunused-parameter"

/* Fallback for __has_builtin */
#ifndef __has_builtin
  #define __has_builtin(x) (0)
#endif

/* NMSIS compiler specific defines */
#ifndef   __ASM
  #define __ASM                                  __asm
#endif
#ifndef   __INLINE
  #define __INLINE                               inline
#endif
#ifndef   __STATIC_INLINE
  #define __STATIC_INLINE                        static inline
#endif
#ifndef   __STATIC_NOINLINE
  #define __STATIC_NOINLINE                      __attribute__((noinline)) static
#endif
#ifndef   __STATIC_FORCEINLINE                 
  #define __STATIC_FORCEINLINE                   __attribute__((always_inline)) static inline
#endif                                           
#ifndef   __NO_RETURN
  #define __NO_RETURN                            __attribute__((__noreturn__))
#endif
#ifndef   __USED
  #define __USED                                 __attribute__((used))
#endif
#ifndef   __WEAK
  #define __WEAK                                 __attribute__((weak))
#endif
#ifndef   __PACKED
  #define __PACKED                               __attribute__((packed, aligned(1)))
#endif
#ifndef   __PACKED_STRUCT
  #define __PACKED_STRUCT                        struct __attribute__((packed, aligned(1)))
#endif
#ifndef   __PACKED_UNION
  #define __PACKED_UNION                         union __attribute__((packed, aligned(1)))
#endif
#ifndef   __UNALIGNED_UINT32        /* deprecated */
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wpacked"
  #pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed)) T_UINT32 { uint32_t v; };
  #pragma GCC diagnostic pop
  #define __UNALIGNED_UINT32(x)                  (((struct T_UINT32 *)(x))->v)
#endif
#ifndef   __UNALIGNED_UINT16_WRITE
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wpacked"
  #pragma GCC diagnostic ignored "-Wattributes"
  __PACKED_STRUCT T_UINT16_WRITE { uint16_t v; };
  #pragma GCC diagnostic pop
  #define __UNALIGNED_UINT16_WRITE(addr, val)    (void)((((struct T_UINT16_WRITE *)(void *)(addr))->v) = (val))
#endif
#ifndef   __UNALIGNED_UINT16_READ
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wpacked"
  #pragma GCC diagnostic ignored "-Wattributes"
  __PACKED_STRUCT T_UINT16_READ { uint16_t v; };
  #pragma GCC diagnostic pop
  #define __UNALIGNED_UINT16_READ(addr)          (((const struct T_UINT16_READ *)(const void *)(addr))->v)
#endif
#ifndef   __UNALIGNED_UINT32_WRITE
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wpacked"
  #pragma GCC diagnostic ignored "-Wattributes"
  __PACKED_STRUCT T_UINT32_WRITE { uint32_t v; };
  #pragma GCC diagnostic pop
  #define __UNALIGNED_UINT32_WRITE(addr, val)    (void)((((struct T_UINT32_WRITE *)(void *)(addr))->v) = (val))
#endif
#ifndef   __UNALIGNED_UINT32_READ
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wpacked"
  #pragma GCC diagnostic ignored "-Wattributes"
  __PACKED_STRUCT T_UINT32_READ { uint32_t v; };
  #pragma GCC diagnostic pop
  #define __UNALIGNED_UINT32_READ(addr)          (((const struct T_UINT32_READ *)(const void *)(addr))->v)
#endif
#ifndef   __ALIGNED
  #define __ALIGNED(x)                           __attribute__((aligned(x)))
#endif
#ifndef   __RESTRICT
  #define __RESTRICT                             __restrict
#endif
#ifndef   __COMPILER_BARRIER
  #define __COMPILER_BARRIER()                   __ASM volatile("":::"memory")
#endif


#define __NMSIS_GCC_OUT_REG(r) "=r" (r)
#define __NMSIS_GCC_RW_REG(r) "+r" (r)
#define __NMSIS_GCC_USE_REG(r) "r" (r)

/**
  \brief   No Operation
  \details No Operation does nothing. This instruction can be used for code alignment purposes.
 */
#define __NOP()                             __ASM volatile ("nop")

/**
  \brief   Wait For Interrupt
  \details Wait For Interrupt is a hint instruction that suspends execution until one of a number of events occurs.
 */
#define __WFI()                             __ASM volatile ("wfi")

/**
  \brief   Reverse byte order (32 bit)
  \details Reverses the byte order in unsigned integer value. For example, 0x12345678 becomes 0x78563412.
  \param [in]    value  Value to reverse
  \return               Reversed value
 */
//__STATIC_FORCEINLINE uint32_t __REV(uint32_t value)
//{
//  uint32_t result;
//
//  result =  ((value & 0xff000000) >> 24)
//          | ((value & 0x00ff0000) >> 8 )
//          | ((value & 0x0000ff00) << 8 )
//          | ((value & 0x000000ff) << 24);
//  return result;
//}

/**
  \brief   Reverse byte order (16 bit)
  \details Reverses the byte order within each halfword of a word. For example, 0x12345678 becomes 0x34127856.
  \param [in]    value  Value to reverse
  \return               Reversed value
 */
//__STATIC_FORCEINLINE uint32_t __REV16(uint32_t value)
//{
//  uint32_t result;
//    result =  ((value & 0xff000000) >> 8)
//              | ((value & 0x00ff00000) << 8 )
//              | ((value & 0x0000ff00) >> 8 )
//              | ((value & 0x000000ff) << 8) ;
//
//  __ASM volatile ("rev16 %0, %1" : __NMSIS_GCC_OUT_REG (result) : __NMSIS_GCC_USE_REG (value) );
//  return result;
//}


/**
  \brief   Reverse byte order (16 bit)
  \details Reverses the byte order in a 16-bit value and returns the signed 16-bit result. For example, 0x0080 becomes 0x8000.
  \param [in]    value  Value to reverse
  \return               Reversed value
 */
//__STATIC_FORCEINLINE int16_t __REVSH(int16_t value)
//{
//  int16_t result;
//  result = ((value & 0xff00) >> 8) | ((value & 0x00ff) << 8);
//  return result;
//}

/**
  \brief   Rotate Right in unsigned value (32 bit)
  \details Rotate Right (immediate) provides the value of the contents of a register rotated by a variable number of bits.
  \param [in]    op1  Value to rotate
  \param [in]    op2  Number of Bits to rotate
  \return               Rotated value
 */
__STATIC_FORCEINLINE uint32_t __ROR(uint32_t op1, uint32_t op2)
{
  op2 %= 32U;
  if (op2 == 0U)
  {
    return op1;
  }
  return (op1 >> op2) | (op1 << (32U - op2));
}

/**
  \brief   Reverse bit order of value
  \details Reverses the bit order of the given value.
  \param [in]    value  Value to reverse
  \return               Reversed value
 */
//__STATIC_FORCEINLINE uint32_t __RBIT(uint32_t value)
//{
//  uint32_t result;
//  uint32_t s = (4U /*sizeof(v)*/ * 8U) - 1U; /* extra shift needed at end */
//
//  result = value;                      /* r will be reversed bits of v; first get LSB of v */
//  for (value >>= 1U; value != 0U; value >>= 1U)
//  {
//    result <<= 1U;
//    result |= value & 1U;
//    s--;
//  }
//  result <<= s;                        /* shift when v's highest bits are zero */
//  return result;
//}

/**
  \brief   Count leading zeros
  \details Counts the number of leading zeros of a data value.
  \param [in]  value  Value to count the leading zeros
  \return             number of leading zeros in value
 */
__STATIC_FORCEINLINE uint8_t __CLZ(uint32_t data)
{
#if defined(ARM_MATH_DSP)
  uint8_t count;
  __ASM volatile(
  		"clz32 %0, %1\n"
  		:"=r"(count)
  		:"r"(data)
    );
  return count;
#else
  uint8_t ret = 0;
  uint32_t temp = ~data;
  while(temp & 0x80000000) {
  	temp <<= 1;
  	ret++;
  }
  return ret;
#endif
}


/**
  \brief   Signed Saturate
  \details Saturates a signed value.
  \param [in]  value  Value to be saturated
  \param [in]    sat  Bit position to saturate to (1..32)
  \return             Saturated value
 */
__STATIC_FORCEINLINE int32_t __SSAT(int32_t val, const uint32_t sat)
{
#if defined(ARM_MATH_DSP)
	int32_t result;
    __ASM volatile (
  	    "sclip32 %0, %1, %2"
  	    :"=r" (result)
  	    :"r"(val), "K"(sat-1)
	);
    return result;
#else
	if ((sat >= 1U) && (sat <= 32U))
	{
		const int32_t max = (int32_t)((1U << (sat - 1U)) - 1U);
		const int32_t min = -1 - max ;
		if (val > max)
		{
			return max;
		}
		else if (val < min)
		{
			return min;
		}
	}
	return val;
#endif
}

/**
  \brief   Unsigned Saturate
  \details Saturates an unsigned value.
  \param [in]  value  Value to be saturated
  \param [in]    sat  Bit position to saturate to (0..31)
  \return             Saturated value
 */
__STATIC_FORCEINLINE uint32_t __USAT(uint32_t val, const uint32_t sat)
{
#if defined(ARM_MATH_DSP)
	uint32_t result;
	__ASM volatile (
	"uclip32 %0, %1, %2"
	:"=r" (result)
	:"r"(val), "K"(sat)
	);
	return result;
#else
	if (sat <= 31U)
	{
	  const uint32_t max = ((1U << sat) - 1U);
	  if (val > (int32_t)max)
	  {
	    return max;
	  }
	  else if (val < 0)
	  {
	    return 0U;
	  }
	}
	return (uint32_t)val;
#endif
}

/* ###################  Compiler specific Intrinsics  ########################### */
/** \defgroup NMSIS_SIMD_intrinsics NMSIS SIMD Intrinsics
  Access to dedicated SIMD instructions
  @{
*/
#if (defined (__RISCV_FEATURE_DSP) && (__RISCV_FEATURE_DSP == 1))

__STATIC_FORCEINLINE int64_t __ADD64(int64_t op1, int64_t op2)
{
	register int64_t result asm("a4");
	register int64_t a asm("a0") = op1;
	register int64_t b asm("a2") = op2;
	__ASM volatile("add64 %0, %1, %2" : "=r"(result) : "r"(a), "r"(b));
	return result;
}

// 3.23: kabs8 (simd 8-bit saturating absolute)
__STATIC_FORCEINLINE int32_t __KABS8(int32_t op)
{
	int32_t result;
	__ASM volatile("kabs8 %0, %1" :"=r"(result) :"r"(op));
	return result;
}

// dkabs8 (simd 8-bit saturating absolute)
__STATIC_FORCEINLINE int64_t __DKABS8(int64_t op)
{
	register int64_t src asm("a0")  = op;
	register int64_t result asm("a2");
	__ASM volatile("dkabs8 %0, %1" :"=r"(result) :"r"(src));
	return result;
}

// 3.24: kabs16 (simd 16-bit saturating absolute)
__STATIC_FORCEINLINE int32_t __KABS16(int32_t op)
{
	int32_t result;
	__ASM volatile("kabs16 %0, %1" :"=r"(result) :"r"(op));
	return result;
}

__STATIC_FORCEINLINE int64_t __DKABS16(int64_t op)
{
	register int64_t src asm("a0") = op;
	register int64_t result asm("a2");
	__ASM volatile("dkabs16 %0, %1" :"=r"(result) :"r"(src));
	return result;
}

// 3.25: kabsw (scalar 32-bit absolute value with saturating)
__STATIC_FORCEINLINE int32_t __KABSW(int32_t op)
{
	int32_t result;
	__ASM volatile("kabsw %0, %1" :"=r"(result) :"r"(op));
	return result;
}

// 3.27. KADD16 (simd 16-bit signed saturating addition)
// {op1[31:16] + op2[31:16] , op1[15:0] + op2[15:0]}
__STATIC_FORCEINLINE int32_t __KADD16(int32_t op1, int32_t op2)
{
	int32_t result;
	__ASM volatile("kadd16 %0, %1, %2" :"=r"(result) :"r"(op1), "r"(op2));
	return result;
}

__STATIC_FORCEINLINE int64_t __DKADD16(int64_t op1, int64_t op2)
{
	register int64_t a asm("a0") = op1;
	register int64_t b asm("a2") = op2;
	register int64_t result asm("a4");
	__ASM volatile("dkadd16 %0, %1, %2" :"=r"(result) :"r"(a), "r"(b));
	return result;
}

// 3.35 KHM8 (simd signed saturating Q7 multiply)
__STATIC_FORCEINLINE int32_t __KHM8(int32_t op1, int32_t op2)
{
	int32_t result;
	__ASM volatile("khm8 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
	return result;
}

__STATIC_FORCEINLINE int64_t __DKHM8(int64_t op1, int64_t op2)
{
	register int64_t result asm("a4");
	register int64_t a asm("a0") = op1;
	register int64_t b asm("a2") = op2;
	__ASM volatile("dkhm8 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
	return result;
}

// 3.36 KHM16 (simd signed saturating Q15 multiply)
__STATIC_FORCEINLINE int32_t __KHM16(int32_t op1, int32_t op2)
{
	int32_t result;
	__ASM volatile("khm16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
	return result;
}

__STATIC_FORCEINLINE int64_t __DKHM16(int64_t op1, int64_t op2)
{
	register int64_t result asm("a4");
	register int64_t a asm("a0") = op1;
	register int64_t b asm("a2") = op2;
	__ASM volatile("dkhm16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
	return result;
}

// 3.59 KSLRA8 (simd 8-bit shift left logical with saturation or shift right arithmetic
__STATIC_FORCEINLINE int32_t __KSLRA8(int32_t op, int8_t shift)
{
	int32_t result;
	__ASM volatile("kslra8 %0, %1, %2" : "=r"(result) : "r"(op), "r"(shift));
	return result;
}

__STATIC_FORCEINLINE int64_t __DKSLRA8(int64_t op, int8_t shift)
{
	register int64_t result asm("a4");
	register int64_t a asm("a0") = op;
	__ASM volatile("dkslra8 %0, %1, %2" : "=r"(result) : "r"(a), "r"(shift));
	return result;
}

// 3.69 KSLRA16 (simd 16bit shift left logical with saturation or shift right arithmetic)
__STATIC_FORCEINLINE int32_t __KSLRA16(int32_t op, int8_t shift)
{
	int32_t result;
	__ASM volatile("kslra16 %0, %1, %2" : "=r"(result) : "r"(op), "r"(shift));
	return result;
}

__STATIC_FORCEINLINE int64_t __DKSLRA16(int64_t op, int8_t shift)
{
	register int64_t result asm ("a4");
	register int64_t a asm("a0") = op;
	__ASM volatile("dkslra16 %0, %1, %2" : "=r"(result) : "r"(a), "r"(shift));
	return result;
}

// 3.66 KSUB16 (simd 16-bit signed saturating subtraction)
__STATIC_FORCEINLINE int32_t __KSUB16(int32_t op1, int32_t op2)
{
	int32_t result;
	__ASM volatile("ksub16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
	return result;
}

__STATIC_FORCEINLINE int64_t __DKSUB16(int64_t op1, int64_t op2)
{
	register int64_t result asm("a4");
	register int64_t a asm("a0") = op1;
	register int64_t b asm("a2") = op2;
	__ASM volatile("dksub16 %0, %1, %2" : "=r"(result) : "r"(a), "r"(b));
	return result;
}

// 3.76 MULSR64 (multiply word signed to 64-bit data)
__STATIC_FORCEINLINE int64_t __MULSR64(int32_t op1, int32_t op2)
{
	register int64_t result asm("a4");
	__ASM volatile("mulsr64 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
	return result;
}

// 3.79.1 PKBB16 (pack two 16-bit data from both bottom half)
__STATIC_FORCEINLINE int32_t __PKBB16(int32_t op1, int32_t op2)
{
	int32_t result;
	__ASM volatile("pkbb16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
	return result;
}

// 3.79.2 PKBT16 (pack two 16-bit data from bottom and top half)
__STATIC_FORCEINLINE int32_t __PKBT16(int32_t op1, int32_t op2)
{
	int32_t result;
	__ASM volatile("pkbt16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
	return result;
}

// 3.79.3 PKTT16 (pack two 16-bit data from top and top half)
__STATIC_FORCEINLINE int32_t __PKTT16(int32_t op1, int32_t op2)
{
	int32_t result;
	__ASM volatile("pktt16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
	return result;
}

// 3.79.4 PKTB16 (pack two 16-bit data from top and bottom half)
__STATIC_FORCEINLINE int32_t __PKTB16(int32_t op1, int32_t op2)
{
	int32_t result;
	__ASM volatile("pktb16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
	return result;
}

// 3.105.1 SMALBB (signed multiply bottom halfs & add 64-bit)
// acc[63:0] + op1[15:0] * op2[15:0]
__STATIC_NOINLINE int64_t __SMALBB(int32_t op1, int32_t op2, int64_t acc)
{
	register int64_t result	 asm("a2") = acc;
	__ASM volatile("smalbb %0, %1, %2\n"
					: "+r"(result)
					: "r"(op1), "r"(op2)
					:);
	return result;
}

// 3.106.1 SMALDA (signed multiply two halfs and two adds 64-bits)
// acc[63:0] + Sint(op1[15:0]) * Sint(op2[15:0]) + Sint(op1[31:16]) * Sint(op2[31:16])
__STATIC_NOINLINE int64_t __SMALDA(int32_t op1, int32_t op2, int64_t acc)
{
	register int64_t result asm("a2") = acc;
	__ASM volatile("smalda %0, %1, %2"
					: "+r"(result)
					: "r"(op1), "r"(op2)
					);
	return result;
}

// 3.108 SMAR64 (signed multiply and add to 64-bit data)
// acc[63:0] + op1[31:0] * op2[31:0]
//__STATIC_FORCEINLINE int64_t __SMAR64(int32_t op1, int32_t op2, int64_t acc)
__STATIC_FORCEINLINE int64_t __SMAR64(int32_t op1, int32_t op2, int64_t acc)
{
	register int64_t result asm("a2") = acc;
	__ASM volatile("smar64 %0, %1, %2\n"
					: "+r"(result)
					: "r"(op1), "r"(op2)
	                :);
	return result;
}

// 3.109 SMAQA (signed multiply four bytes with 32-bit adds)
//  op1[7:0] * op2[7:0] + op1[15:8] * op2[15:8] + op1[23:16] * op2[23:16] + op1[31:24] * op2[31:24] + acc
__STATIC_FORCEINLINE int32_t __SMAQA(int32_t op1, int32_t op2, int32_t acc)
{
	__ASM volatile("smaqa %0, %1, %2"
		: "+r"(acc)
		: "r"(op1), "r"(op2)
	);
	return acc;
}

// 3.113.1 SMBB16 (simd signed multiply bottom half & bottom half)
// op1[15:0] * op2[15:0]
__STATIC_FORCEINLINE int32_t __SMBB16(int32_t op1, int32_t op2)
{
	int32_t result;
	__ASM volatile("smbb16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
	return result;
}

// 3.113.2 SMBT16 (simd signed multiply bottom half & top half)
// op1[15:0] * op2[31:16]
__STATIC_FORCEINLINE int32_t __SMBT16(int32_t op1, int32_t op2)
{
	int32_t result;
	__ASM volatile("smbt16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
	return result;
}

// 3.113.2 SMTT16 (simd signed multiply bottom half & top half)
// op1[31:0] * op2[31:16]
__STATIC_FORCEINLINE int32_t __SMTT16(int32_t op1, int32_t op2)
{
	int32_t result;
	__ASM volatile("smtt16 %0, %1, %2" : "=r"(result) : "r"(op1), "r"(op2));
	return result;
}

// 3.121 SMSR64 (signed multiply and substract from 64-bit data)
//__STATIC_FORCEINLINE int64_t __SMSR64(int32_t op1, int32_t op2, int64_t minuend)
// minuend[63:0] - op1[31:0] * op2[31:0]
__STATIC_FORCEINLINE int64_t __SMSR64(int32_t op1, int32_t op2, int64_t minuend)
{
	register int64_t result asm("a2") = minuend;
	__ASM volatile("smsr64 %0, %1, %2" : "+r"(result) : "r"(op1), "r"(op2));
	return result;
}

// 3.120.1 SMSLDA (signed multiply two halfs & add & subtract 64-bit)
// minuend[63:0] - op1[15:0] * op2[15:0] - op1[31:16] * op2[31:16]
//__STATIC_FORCEINLINE int64_t __SMSLDA(int16_t op1, int16_t op2, int64_t minuend)
__STATIC_FORCEINLINE int64_t __SMSLDA(int32_t op1, int32_t op2, int64_t minuend)
{
	register int64_t result asm("a2") = minuend;
	__ASM volatile("smslda %0, %1, %2" : "+r"(result) : "r"(op1), "r"(op2));
	return result;
}

// 3.138 SUB64 (64-bit subtraction)
__STATIC_FORCEINLINE int64_t __SUB64(int64_t op1, int64_t op2)
{
	register int64_t result asm("a4");
	register int64_t a asm("a0") = op1;
	register int64_t b asm("a2") = op2;
	__ASM volatile("sub64 %0, %1, %2" : "=r"(result) : "r"(a), "r"(b));
	return result;
}

__STATIC_FORCEINLINE int32_t __EXPD80(int8_t offset)
{
   int32_t result;
   __ASM volatile("expd80 %0, %1" : "=r"(result) : "r"(offset));
   return result;
}

__STATIC_FORCEINLINE int32_t __EXPD81(int8_t offset)
{
   int32_t result;
   __ASM volatile("expd81 %0, %1" : "=r"(result) : "r"(offset));
   return result;
}

__STATIC_FORCEINLINE int32_t __EXPD82(int8_t offset)
{
   int32_t result;
   __ASM volatile("expd82 %0, %1" : "=r"(result) : "r"(offset));
   return result;
}

__STATIC_FORCEINLINE int32_t __EXPD83(int8_t offset)
{
   int32_t result;
   __ASM volatile("expd83 %0, %1" : "=r"(result) : "r"(offset));
   return result;
}

#endif // __RISCV_FEATURE_DSP



#if (defined (__ARM_FEATURE_DSP) && (__ARM_FEATURE_DSP == 1))

//__STATIC_FORCEINLINE uint32_t __SADD8(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("add8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

// saturating for 8-bit additions
__STATIC_FORCEINLINE int32_t __QADD8(int32_t op1, int32_t op2)
{
  int32_t result;
  __ASM volatile ("kadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

// saturating for 8-bit additions
__STATIC_FORCEINLINE uint64_t __DQADD8(uint64_t op1, uint64_t op2)
{
	register uint64_t src1 asm("a0") = op1;
	register uint64_t src2 asm("a2") = op2;
  register uint64_t result asm("a4");
  __ASM volatile ("dkadd8 %0, %1, %2" : "=r" (result) : "r" (src1), "r" (src2) );
  return(result);
}

// {(op1[31:24] + op2[31:24]) >> 1, (op1[23:16] + op2[23:16]) >> 1, (op1[15:8] + op2[15:8]) >> 1, (op1[7:0] + op2[7:0]) >> 1}
//__STATIC_FORCEINLINE uint32_t __SHADD8(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("shadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __UADD8(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("add8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __UQADD8(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("ukadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __UHADD8(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("uhadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}


//__STATIC_FORCEINLINE uint32_t __SSUB8(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("ssub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

__STATIC_FORCEINLINE int32_t __QSUB8(int32_t op1, int32_t op2)
{
  int32_t result;
  __ASM volatile ("ksub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__STATIC_FORCEINLINE uint64_t __DQSUB8(uint64_t op1, uint64_t op2)
{
	register uint64_t src1 asm("a0") = op1;
	register uint64_t src2 asm("a2") = op2;
    register uint64_t result asm("a4");

  __ASM volatile ("dksub8 %0, %1, %2" : "=r" (result) : "r" (src1), "r" (src2) );
  return(result);
}

//__STATIC_FORCEINLINE uint32_t __SHSUB8(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("shsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __USUB8(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("usub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __UQSUB8(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("uqsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __UHSUB8(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("uhsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}


//__STATIC_FORCEINLINE uint32_t __SADD16(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("sadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

__STATIC_FORCEINLINE int32_t __QADD16(int32_t op1, int32_t op2)
{
  int32_t result;
  __ASM volatile ("kadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__STATIC_FORCEINLINE int32_t __SHADD16(int32_t op1, int32_t op2)
{
  int32_t result;
  __ASM volatile ("radd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

//__STATIC_FORCEINLINE uint32_t __UADD16(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("uadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __UQADD16(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("uqadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __UHADD16(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("uhadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __SSUB16(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("ssub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

__STATIC_FORCEINLINE int32_t __QSUB16(int32_t op1, int32_t op2)
{
  int32_t result;
  __ASM volatile ("ksub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__STATIC_FORCEINLINE int32_t __SHSUB16(int32_t op1, int32_t op2)
{
  int32_t result;

  __ASM volatile ("rsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

//__STATIC_FORCEINLINE uint32_t __USUB16(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("usub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __UQSUB16(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("uqsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __UHSUB16(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("uhsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __SASX(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("sasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

// saturating add and subtract with exchange the two halfwords of the second operand, performs one unsigned 16-bit
// integer addition and one unsigned 16-bit subtraction, saturated the results to the 16bit unsigned integer range 0 <= x <= 2^16 -1,
// and writes the results to te desination register
// {SInt(op1[31:16]) + Sint(op2[15:0]) , SInt(op1[15:0]) - SInt(op2[31:16])}
__STATIC_FORCEINLINE int32_t __QASX(int32_t op1, int32_t op2)
{
  int32_t result;
  __ASM volatile ("kcras16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

// signed halving add and subtract with exchange exchanges the two halfwords of the second operand, performs one signed 16-bit
// integer addition and one signed 16-bit subtraction, halves the results, and writes the results to the destination register
// {(Sint(op1[31:16]) + Sint(op2[15:0])) >> 1 ,  (Sint(op1[15:0]) - Sint(op2[31:16]) >> 1 }
__STATIC_FORCEINLINE int32_t __SHASX(int32_t op1, int32_t op2)
{
  int32_t result;
  __ASM volatile ("rcras16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

// signed halving subtract and add with exchange exchanges the two halfwords of the second operand, pwerforms one singed 16-bit
// integer subtraction and one signed 16-bit addition, halves the results, and writes the results to the destination
// {(Sint(op1[31:16]) - Sint(op2[15:0])) >> 1 ,  (Sint(op1[15:0]) + Sint(op2[31:16]) >> 1 }
__STATIC_FORCEINLINE int32_t __SHSAX(int32_t op1, int32_t op2)
{
    int32_t result;
    __ASM volatile ("rcrsa16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
    return(result);
}

//__STATIC_FORCEINLINE uint32_t __UASX(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("uasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __UQASX(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("uqasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __UHASX(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("uhasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __SSAX(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("ssax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

// Sint(op1[31:16]) - Sint(op2[15:0]) , Sint(op1[15:0] + Sint(op2[31:16])
__STATIC_FORCEINLINE int32_t __QSAX(int32_t op1, int32_t op2)
{
  int32_t result;
  __ASM volatile ("kcrsa16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

//__STATIC_FORCEINLINE uint32_t __USAX(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("usax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __UQSAX(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("uqsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __UHSAX(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("uhsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __USAD8(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("usad8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __USADA8(uint32_t op1, uint32_t op2, uint32_t op3)
//{
//  uint32_t result;
//
//  __ASM volatile ("usada8 %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
//  return(result);
//}

//#define __SSAT16(ARG1,ARG2) \
//({                          \
//  int32_t __RES, __ARG1 = (ARG1); \
//  __ASM ("ssat16 %0, %1, %2" : "=r" (__RES) :  "I" (ARG2), "r" (__ARG1) ); \
//  __RES; \
// })
//
//#define __USAT16(ARG1,ARG2) \
//({                          \
//  uint32_t __RES, __ARG1 = (ARG1); \
//  __ASM ("usat16 %0, %1, %2" : "=r" (__RES) :  "I" (ARG2), "r" (__ARG1) ); \
//  __RES; \
// })

//__STATIC_FORCEINLINE uint32_t __UXTB16(uint32_t op1)
//{
//  uint32_t result;
//
//  __ASM volatile ("uxtb16 %0, %1" : "=r" (result) : "r" (op1));
//  return(result);
//}

//__STATIC_FORCEINLINE uint32_t __UXTAB16(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("uxtab16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

__STATIC_FORCEINLINE int32_t __SXTB16(int32_t op1)
{
	int32_t result;
    //return ((uint32_t)(((((int32_t)op1 << 24) >> 24) & (int32_t)0x0000FFFF) |
    //                   ((((int32_t)op1 <<  8) >>  8) & (int32_t)0xFFFF0000)  ));
    __ASM volatile(
    		"sunpkd820 %0, %1"
    		:"=r"(result)
    		:"r"(op1)
    );
    return result;
}

//__STATIC_FORCEINLINE uint32_t __SXTAB16(uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("sxtab16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

// signed dual multiply add performs two signed 16x16 bit multiplications. It adds the products together, and write the result to the destination register.
// SInt(op1[15:0]) * SInt(op2[15:0] + SInt(op1[31:16]) * SInt(op2[31:16])
__STATIC_FORCEINLINE int32_t __SMUAD  (int32_t op1, int32_t op2)
{
	int32_t rl = __SMBB16(op1, op2);
	int32_t rh = __SMTT16(op1, op2);
	return (rl + rh);
}

// signed dula multiply add performs two signed 16 x 16-bit multiplication.
// Sing(op1[15:0]) * SInt(op2[31:16]) + Sint(op1[31:16]) * SInt(op2[15:0])
__STATIC_FORCEINLINE int32_t __SMUADX (int32_t op1, int32_t op2)
{
	int32_t a = __SMBT16(op1, op2);
	int32_t b = __SMBT16(op2, op1);
	return (a + b);
}

// signed multiply accumulate dual performs two 16x16 bit multiplications. it adds the products to a 32-bit accumulate operand
// SInt(op1[15:0]) * SInt(op1[15:0] + SInt(op1[31:16]) * SInt(op2[31:16]) + op3
__STATIC_FORCEINLINE int32_t __SMLAD (int32_t op1, int32_t op2, int32_t op3)
{
    //return ((int32_t)(((((int32_t)op1 << 16) >> 16) * (((int32_t)op2 << 16) >> 16)) +
    //                   ((((int32_t)op1      ) >> 16) * (((int32_t)op2      ) >> 16)) +
    //                   ( ((int32_t)op3    )                                  )   ));
    int32_t rl = __SMBB16(op1, op2);
    int32_t rh = __SMTT16(op1, op2);
    return (rl + rh + op3);
}

// signed multiply accumulate dual performs two 16x16 bit multiplications. it adds the products to a 32-bit accumulate operand
// SInt(op1[15:0]) * SInt(op1[31:16] + SInt(op1[31:16]) * SInt(op2[15:0]) + op3
__STATIC_FORCEINLINE int32_t __SMLADX (int32_t op1, int32_t op2, int32_t op3)
{
	 //return ((int32_t)(((((int32_t)op1 << 16) >> 16) * (((int32_t)op2      ) >> 16)) +
     //                  ((((int32_t)op1      ) >> 16) * (((int32_t)op2 << 16) >> 16)) +
     //                  ( ((int32_t)op3    )                                  )   ));
	 int32_t a = __SMBT16(op1, op2);
	 int32_t b = __SMBT16(op2, op1);
	 return (a + b + op3);
}

// signed multiply accumulate Long Dual performs two signed 16x16 bit multiplications. it adds the products to a 64-bit accumulate operand
// SInt(op1[15:0]) * SInt(op2[15:0]) + SInt(op1[31:16]) * SInt(op2[31:16]) + acc[63:0]
__STATIC_FORCEINLINE int64_t __SMLALD (int32_t op1, int32_t op2, int64_t acc)
{
	 //return ((int64_t)(((((int32_t)op1 << 16) >> 16) * (((int32_t)op2 << 16) >> 16)) +
     //                  ((((int32_t)op1      ) >> 16) * (((int32_t)op2      ) >> 16)) +
     //                  ( ((int64_t)acc    )                                  )   ));
	 int32_t rl = __SMBB16(op1, op2);
	 int32_t rh = __SMTT16(op1, op2);
	 return (acc + (int64_t)rl + (int64_t)rh);
}

// signed multiply accumulate Long Dual performs two signed 16x16 bit multiplications. it adds the products to a 64-bit accumulate operand
// SInt(op1[15:0]) * SInt(op2[31:0]) + SInt(op1[31:16]) * SInt(op2[15:0]) + acc[63:0]
__STATIC_FORCEINLINE int64_t __SMLALDX (int32_t op1, int32_t op2, int64_t acc)
{
	 int32_t rl = __SMBT16(op1, op2);
	 int32_t rh = __SMBT16(op2, op1);
	 return (acc + (int64_t)rl + (int64_t)rh);
}

// Sint(op1[15:0]) * Sint(op2[15:0]) - Sint(op1[31:16]) * Sint(op2[31:16])
__STATIC_FORCEINLINE int32_t __SMUSD  (int32_t op1, int32_t op2)
{
  int32_t result;
  __ASM volatile ("smds %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(-result);
}

// Sint(op1[15:0]) * Sint(op2[31:15]) - Sint(op1[31:16]) * Sint(op2[15:0])
__STATIC_FORCEINLINE int32_t __SMUSDX (int32_t op1, int32_t op2)
{
  int32_t result;
  __ASM volatile ("smxds %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(-result);
}

//__STATIC_FORCEINLINE uint32_t __SMLSD (uint32_t op1, uint32_t op2, uint32_t op3)
//{
//  uint32_t result;
//
//  __ASM volatile ("smlsd %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
//  return(result);
//}

// Sint(op1[15:0]) * Sint(op2[31:16]) - Sint(op1[31:16]) * Sint(op2[15:0]) + op3
__STATIC_NOINLINE int32_t __SMLSDX (int32_t op1, int32_t op2, int32_t op3)
{
  int32_t result;
  __ASM volatile ("smxds %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return (op3 - result);
}

//__STATIC_FORCEINLINE uint64_t __SMLSLD (uint32_t op1, uint32_t op2, uint64_t acc)
//{
//  union llreg_u{
//    uint32_t w32[2];
//    uint64_t w64;
//  } llr;
//  llr.w64 = acc;
//  __ASM volatile ("smlsld %0, %1, %2, %3" : "=r" (llr.w32[0]), "=r" (llr.w32[1]): "r" (op1), "r" (op2) , "0" (llr.w32[0]), "1" (llr.w32[1]) );
//  return(llr.w64);
//}

//__STATIC_FORCEINLINE uint64_t __SMLSLDX (uint32_t op1, uint32_t op2, uint64_t acc)
//{
//  union llreg_u{
//    uint32_t w32[2];
//    uint64_t w64;
//  } llr;
//  llr.w64 = acc;
//  __ASM volatile ("smlsldx %0, %1, %2, %3" : "=r" (llr.w32[0]), "=r" (llr.w32[1]): "r" (op1), "r" (op2) , "0" (llr.w32[0]), "1" (llr.w32[1]) );
//  return(llr.w64);
//}

//__STATIC_FORCEINLINE uint32_t __SEL  (uint32_t op1, uint32_t op2)
//{
//  uint32_t result;
//
//  __ASM volatile ("sel %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
//  return(result);
//}

__STATIC_FORCEINLINE  int32_t __QADD( int32_t op1,  int32_t op2)
{
  int32_t result;
  __ASM volatile ("kaddw %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__STATIC_FORCEINLINE  int32_t __QSUB( int32_t op1,  int32_t op2)
{
  int32_t result;
  __ASM volatile ("ksubw %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

//#if 0
//#define __PKHBT(ARG1,ARG2,ARG3) \
//({                          \
//  uint32_t __RES, __ARG1 = (ARG1), __ARG2 = (ARG2); \
//  __ASM ("pkhbt %0, %1, %2, lsl %3" : "=r" (__RES) :  "r" (__ARG1), "r" (__ARG2), "I" (ARG3)  ); \
//  __RES; \
// })
//
//#define __PKHTB(ARG1,ARG2,ARG3) \
//({                          \
//  uint32_t __RES, __ARG1 = (ARG1), __ARG2 = (ARG2); \
//  if (ARG3 == 0) \
//    __ASM ("pkhtb %0, %1, %2" : "=r" (__RES) :  "r" (__ARG1), "r" (__ARG2)  ); \
//  else \
//    __ASM ("pkhtb %0, %1, %2, asr %3" : "=r" (__RES) :  "r" (__ARG1), "r" (__ARG2), "I" (ARG3)  ); \
//  __RES; \
// })
//#endif

__STATIC_FORCEINLINE int32_t __SMMLA (int32_t op1, int32_t op2, int32_t op3)
{
  //return (op3 + (int32_t) (((int64_t) op1 * op2) >> 32));
  int32_t mul;
  __ASM volatile(
  		"smmul %0, %1, %2"
		:"+r"(mul)
		:"r"(op1), "r"(op2)
		);
  return (op3 + mul);
}

#endif /* (__ARM_FEATURE_DSP == 1) */
/*@} end of group NMSIS_SIMD_intrinsics */

#define __PKHBT(ARG1,ARG2,ARG3)          ( ((((uint32_t)(ARG1))          ) & 0x0000FFFFUL) |  \
                                           ((((uint32_t)(ARG2)) << (ARG3)) & 0xFFFF0000UL)  )

#define __PKHTB(ARG1,ARG2,ARG3)          ( ((((uint32_t)(ARG1))          ) & 0xFFFF0000UL) |  \
                                           ((((uint32_t)(ARG2)) >> (ARG3)) & 0x0000FFFFUL)  )

#pragma GCC diagnostic pop

#endif /* __NMSIS_GCC_H */
