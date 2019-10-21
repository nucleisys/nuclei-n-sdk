// See LICENSE for license details.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "stdatomic.h"

#include "drivers/func.h"
#include "soc/drivers/soc.h"
#include "soc/drivers/board.h"
#include "drivers/riscv_encoding.h"
#include "drivers/timer.h"
#include "drivers/eclic.h"



#include "riscv_math.h" 
#include "array.h"
#include "riscv_ref_lib/ref_mean.c"

volatile uint32_t  theseSecs = 0;
volatile uint32_t  STARTSecs = 0;
volatile uint32_t  secs;

#define START STARTSecs=read_csr(mcycle);
#define END theseSecs=read_csr(mcycle);  secs = theseSecs - STARTSecs;


void led_init(void)
{
	GPIO_REG(GPIO_INPUT_EN)    &= ~((0x1<< RED_LED_GPIO_OFFSET) | (0x1<< GREEN_LED_GPIO_OFFSET) | (0x1 << BLUE_LED_GPIO_OFFSET)) ;
  	GPIO_REG(GPIO_OUTPUT_EN)   |=  ((0x1<< RED_LED_GPIO_OFFSET)| (0x1<< GREEN_LED_GPIO_OFFSET) | (0x1 << BLUE_LED_GPIO_OFFSET)) ;

  	GPIO_REG(GPIO_OUTPUT_VAL)  |=   (0x1 << RED_LED_GPIO_OFFSET) ;
  	GPIO_REG(GPIO_OUTPUT_VAL)  &=  ~((0x1<< BLUE_LED_GPIO_OFFSET) | (0x1<< GREEN_LED_GPIO_OFFSET)) ;
}


void f32_mean_compare(){

	START;
	riscv_mean_f32(f32_array, ARRAY_SIZE, &f32_out);
	END;

	printf("f32_result_dsp: %f",f32_out);printf("      T: %d\n",secs);

	START;
	ref_mean_f32(f32_array,ARRAY_SIZE, &f32_out_ref);
	END;

	printf("f32_result:     %f",f32_out_ref);printf("      T: %d\n",secs);

}


void q7_mean_compare(){

	START;
	riscv_mean_q7(q7_array, ARRAY_SIZE, &q7_out);
	END;

	printf("q7_result_dsp:   %d",q7_out);printf("             T: %d\n",secs);

	START;
	ref_mean_q7(q7_array, ARRAY_SIZE, &q7_out_ref);
	END;

	printf("q7_result:       %d",q7_out_ref);printf("          T: %d\n",secs);

}


void q15_mean_compare(){

	START;
	riscv_mean_q15(q15_array, ARRAY_SIZE, &q15_out);
	END;

	printf("q15_result_dsp:   %d",q15_out);printf("            T: %d\n",secs);

	START;
	ref_mean_q15(q15_array, ARRAY_SIZE, &q15_out_ref);
	END;

	printf("q15_result:       %d",q15_out_ref);printf("          T: %d\n",secs);

}

void q31_mean_compare(){
	
	START;
	riscv_mean_q31(q31_array, ARRAY_SIZE, &q31_out);
	END;

	printf("q31_result_dsp:   %d",q31_out);printf("          T: %d\n",secs);

	START;
	ref_mean_q31(q31_array, ARRAY_SIZE, &q31_out_ref);
	END;

	printf("q31_result:       %d",q31_out_ref);printf("         T: %d\n",secs);

}



int main(int argc, char **argv)
{
  // Set up the GPIOs such that the LED GPIO
  // can be used as both Inputs and Outputs.
	enable_mcycle_minstret();
	led_init();
 
   f32_mean_compare();
   q7_mean_compare();
   q15_mean_compare();
   q31_mean_compare();

  return 0;

}





