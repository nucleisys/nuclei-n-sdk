/*
    FreeRTOS V9.0.0 - Copyright (C) 2016 Real Time Engineers Ltd.
    All rights reserved

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation >>>> AND MODIFIED BY <<<< the FreeRTOS exception.

    ***************************************************************************
    >>!   NOTE: The modification to the GPL is included to allow you to     !<<
    >>!   distribute a combined work that includes FreeRTOS without being   !<<
    >>!   obliged to provide the source code for proprietary components     !<<
    >>!   outside of the FreeRTOS kernel.                                   !<<
    ***************************************************************************

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  Full license text is available on the following
    link: http://www.freertos.org/a00114.html

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS provides completely free yet professionally developed,    *
     *    robust, strictly quality controlled, supported, and cross          *
     *    platform software that is more than just the market leader, it     *
     *    is the industry's de facto standard.                               *
     *                                                                       *
     *    Help yourself get started quickly while simultaneously helping     *
     *    to support the FreeRTOS project by purchasing a FreeRTOS           *
     *    tutorial book, reference manual, or both:                          *
     *    http://www.FreeRTOS.org/Documentation                              *
     *                                                                       *
    ***************************************************************************

    http://www.FreeRTOS.org/FAQHelp.html - Having a problem?  Start by reading
    the FAQ page "My application does not run, what could be wrong?".  Have you
    defined configASSERT()?

    http://www.FreeRTOS.org/support - In return for receiving this top quality
    embedded software for free we request you assist our global community by
    participating in the support forum.

    http://www.FreeRTOS.org/training - Investing in training allows your team to
    be as productive as possible as early as possible.  Now you can receive
    FreeRTOS training directly from Richard Barry, CEO of Real Time Engineers
    Ltd, and the world's leading authority on the world's leading RTOS.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, a DOS
    compatible FAT file system, and our tiny thread aware UDP/IP stack.

    http://www.FreeRTOS.org/labs - Where new FreeRTOS products go to incubate.
    Come and try FreeRTOS+TCP, our new open source TCP/IP stack for FreeRTOS.

    http://www.OpenRTOS.com - Real Time Engineers ltd. license FreeRTOS to High
    Integrity Systems ltd. to sell under the OpenRTOS brand.  Low cost OpenRTOS
    licenses offer ticketed support, indemnification and commercial middleware.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.

    1 tab == 4 spaces!
*/

/*-----------------------------------------------------------
 * Implementation of functions defined in portable.h for the ARM CM3 port.
 *----------------------------------------------------------*/

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "portmacro.h"



#include <stdio.h>

#include "drivers/func.h"
#include "drivers/riscv_encoding.h"
#include "drivers/timer.h"
#include "drivers/eclic.h"

/* Standard Includes */
#include <stdlib.h>
#include <unistd.h>



/* Each task maintains its own interrupt status in the critical nesting
variable. */
UBaseType_t uxCriticalNesting = 0xaaaaaaaa;

#if USER_MODE_TASKS
	unsigned long MSTATUS_INIT = (MSTATUS_MPIE);
#else
	unsigned long MSTATUS_INIT = (MSTATUS_MPP | MSTATUS_MPIE);
#endif


/*
 * Used to catch tasks that attempt to return from their implementing function.
 */
static void prvTaskExitError( void );


/*-----------------------------------------------------------*/

void set_msip_int()
{
  *(volatile uint8_t *) (TIMER_CTRL_ADDR + TIMER_MSIP) |=0x01;
}

void clear_msip_int()
{
  *(volatile uint8_t *) (TIMER_CTRL_ADDR + TIMER_MSIP) &= ~0x01;
}

void taskswitch(void)
{
	uint32_t mcause = read_csr(mcause);
  uint32_t msubm = read_csr(0x7c4);
	uint32_t mepc = read_csr(mepc);

	vPortRaiseMTH();
	set_csr(mstatus,MSTATUS_MIE);
	
	vTaskSwitchContext();

	
	clear_csr(mstatus,MSTATUS_MIE);
	vPortClearRaiseMTH();
	

	write_csr(0x7c4, msubm);
  write_csr(mcause, mcause); 
	write_csr(mepc, mepc);
	
}


void vPortRaiseMTH(void )
{
	*(volatile uint8_t*)(ECLIC_ADDR_BASE+ECLIC_MTH_OFFSET)=(((configMAX_SYSCALL_INTERRUPT_PRIORITY)<<5)|0x1f);
}

void vPortClearRaiseMTH(void)
{
	*(volatile uint8_t*)(ECLIC_ADDR_BASE+ECLIC_MTH_OFFSET)=0;
}


void vPortEnterCritical( void )
{

		//portDISABLE_INTERRUPTS();
		//eclic_set_mth ((configMAX_SYSCALL_INTERRUPT_PRIORITY)<<5);
		//eclic_set_mth (((configMAX_SYSCALL_INTERRUPT_PRIORITY)<<5)|0x1f);
		portDISABLE_INTERRUPTS();
		__asm volatile("fence");                                     \
	 __asm volatile("fence.i");                                   

	uxCriticalNesting++;
}
/*-----------------------------------------------------------*/

void vPortExitCritical( void )
{
	configASSERT( uxCriticalNesting );
	uxCriticalNesting--;
	if( uxCriticalNesting == 0 )
	{
		#if USER_MODE_TASKS
			ECALL(IRQ_ENABLE);
		#else
		//	eclic_set_mth (0); 
		portENABLE_INTERRUPTS()	;
		#endif
	}
	return;
}
/*-----------------------------------------------------------*/


/*-----------------------------------------------------------*/

/* Clear current interrupt mask and set given mask */
void vPortClearInterruptMask(uint8_t int_mask)
{
*(volatile uint8_t*)(ECLIC_ADDR_BASE+ECLIC_MTH_OFFSET)=(int_mask); 

	
}
/*-----------------------------------------------------------*/

/* Set interrupt mask and return current interrupt enable register */
uint8_t xPortSetInterruptMask()
{
	uint8_t int_mask=0;
	int_mask=eclic_get_mth();
	
	//eclic_set_mth ((configMAX_SYSCALL_INTERRUPT_PRIORITY)<<5);
*(volatile uint8_t*)(ECLIC_ADDR_BASE+ECLIC_MTH_OFFSET)= (((configMAX_SYSCALL_INTERRUPT_PRIORITY)<<5)|0x1f);
	return int_mask;
}

/*-----------------------------------------------------------*/
/*
 * See header file for description.
 */
StackType_t *pxPortInitialiseStack( StackType_t *pxTopOfStack, TaskFunction_t pxCode, void *pvParameters )
{
	/* Simulate the stack frame as it would be created by a context switch
	interrupt. */

	register int *tp asm("x3");
	pxTopOfStack--;
	*pxTopOfStack = (portSTACK_TYPE)pxCode;			/* Start address */

	//set the initial mstatus value
	pxTopOfStack--;
	*pxTopOfStack = MSTATUS_INIT;

	pxTopOfStack -= 22;
	*pxTopOfStack = (portSTACK_TYPE)pvParameters;	/* Register a0 */
	//pxTopOfStack -= 7;
	//*pxTopOfStack = (portSTACK_TYPE)tp; /* Register thread pointer */
	//pxTopOfStack -= 2;
	pxTopOfStack -=9;
	*pxTopOfStack = (portSTACK_TYPE)prvTaskExitError; /* Register ra */
	pxTopOfStack--;

	return pxTopOfStack;
}
/*-----------------------------------------------------------*/


void prvTaskExitError( void )
{
	/* A function that implements a task must not exit or attempt to return to
	its caller as there is nothing to return to.  If a task wants to exit it
	should instead call vTaskDelete( NULL ).
	Artificially force an assert() to be triggered if configASSERT() is
	defined, then stop here so application writers can catch the error. */
	configASSERT( uxCriticalNesting == ~0UL );
	portDISABLE_INTERRUPTS();
//	printf ("prvTaskExitError\n");
	for( ;; );
}
/*-----------------------------------------------------------*/


/*Entry Point for Machine Timer Interrupt Handler*/
//Bob: add the function argument int_num

void vPortSysTickHandler(){
  uint64_t volatile then = 0;

  volatile uint64_t * mtime       = (uint64_t*) (TIMER_CTRL_ADDR + TIMER_MTIME);
  volatile uint64_t * mtimecmp    = (uint64_t*) (TIMER_CTRL_ADDR + TIMER_MTIMECMP);

	uint32_t mcause = read_csr(mcause);
  uint32_t msubm = read_csr(0x7c4);
	uint32_t mepc = read_csr(mepc);

	vPortEnterCritical()	;
	set_csr(mstatus,MSTATUS_MIE);
	
	*mtime = (uint64_t) 0x00;
  volatile uint64_t  now = *mtime;

	then = now + (configRTC_CLOCK_HZ / configTICK_RATE_HZ);

	*mtimecmp = then;

	/* Increment the RTOS tick. */
	if( xTaskIncrementTick() != pdFALSE )
	{
		portYIELD();
	}
	
	clear_csr(mstatus,MSTATUS_MIE);
	vPortExitCritical();
	write_csr(0x7c4, msubm);
  write_csr(mcause, mcause); 
	write_csr(mepc, mepc);
	
	}
/*-----------------------------------------------------------*/


void vPortSetupTimer(void)	{
    //uint8_t mtime_intattr;
    // Set the machine timer
    //Bob: update it to TMR
    //volatile uint64_t * mtime       = (uint64_t*) (CLINT_CTRL_ADDR + CLINT_MTIME);
    //volatile uint64_t * mtimecmp    = (uint64_t*) (CLINT_CTRL_ADDR + CLINT_MTIMECMP);
    volatile uint64_t * mtime       = (uint64_t*) (TIMER_CTRL_ADDR + TIMER_MTIME);
    volatile uint64_t * mtimecmp    = (uint64_t*) (TIMER_CTRL_ADDR + TIMER_MTIMECMP);
	 // volatile uint32_t * mtimectl    = (uint32_t*) (TIMER_CTRL_ADDR + TIMER_CTL);
	//	 *mtimectl = 0x02;
     *mtime = 0x0;
    uint64_t then = (configRTC_CLOCK_HZ / configTICK_RATE_HZ);
    *mtimecmp = then;
		
    // mtime_intattr=eclic_get_intattr (ECLIC_INT_MTIP);
    // mtime_intattr|=ECLIC_INT_ATTR_SHV;
    // eclic_set_intattr(ECLIC_INT_MTIP,mtime_intattr);
    // eclic_enable_interrupt (ECLIC_INT_MTIP);

    //eclic_set_nlbits(4);
    // eclic_set_irq_lvl_abs(ECLIC_INT_MTIP,1);
    // set_csr(mstatus, MSTATUS_MIE);

 // The MTIME using Vector-Mode
 		eclic_enable_interrupt (ECLIC_INT_MTIP);
	  eclic_set_irq_lvl_abs(ECLIC_INT_MTIP,1);
    eclic_set_vmode(ECLIC_INT_MTIP);
}

void vPortSetupMSIP(void){
		eclic_enable_interrupt (ECLIC_INT_MSIP);
	  eclic_set_irq_lvl_abs(ECLIC_INT_MSIP,1);
	  eclic_set_vmode(ECLIC_INT_MSIP);
}
/*-----------------------------------------------------------*/


void vPortSetup()	{

	vPortSetupTimer();
	vPortSetupMSIP();
	vPortClearRaiseMTH();
	uxCriticalNesting = 0;
}
/*-----------------------------------------------------------*/
