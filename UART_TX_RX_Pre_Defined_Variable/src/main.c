/*
 * main.c
 *
 *  Created on: 02-Mar-2024
 *      Author: Rohan
 */

/* Including necessary configuration files. */
#include "sdk_project_config.h"
#include "string.h"
volatile int exit_code = 0;
#define max_size_int 10
int integer = 123;
uint8_t txBuff[max_size_int];
#define welcomeMsg "Welcome to Trial 2\n"
#define waiTing "Change the pre-defined variable in line 14\n"

void int_convertor(int temp){
	int total_digit = 0;
	while(temp > 0 && total_digit < max_size_int){
		txBuff[max_size_int - 1 - total_digit] = ('0' + temp % 10);
		temp /= 10;
		total_digit++;
	}
}


/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    /* Write your code here */
	  status_t error;
	  /* Configure clocks for PORT */
	  error = CLOCK_DRV_Init(&clockMan1_InitConfig0);
	  DEV_ASSERT(error == STATUS_SUCCESS);

	  error = PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
	  DEV_ASSERT(error == STATUS_SUCCESS);

	  error = LPUART_DRV_Init(INST_TERMINAL_SCREEN, &terminal_screen_state, &terminal_screen_InitConfig);
	  DEV_ASSERT(error == STATUS_SUCCESS);

	  LPUART_DRV_SendDataPolling(INST_TERMINAL_SCREEN, (uint8_t *) welcomeMsg , strlen(welcomeMsg));

	  OSIF_TimeDelay(1000);



    for(;;)
    {
       LPUART_DRV_SendDataPolling(INST_TERMINAL_SCREEN, (uint8_t *) waiTing,strlen(waiTing));

//       Below is for Integer Conversion
       int_convertor(integer);

       LPUART_DRV_SendDataPolling(INST_TERMINAL_SCREEN, &txBuff, sizeof(txBuff));

       OSIF_TimeDelay(1000);

    }
    return exit_code;
}

/* END main */
/*!
** @}
*/
