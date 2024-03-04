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
#define max_size_float 20
float float_value = 3.1428;
char txBuff[max_size_float];
#define welcomeMsg "Welcome to Trial 2\n"
#define waiTing "Change the pre-defined variable in line 13\n"

//void float_convertor(float temp){
//	int temp_int_part = (int)float_value;
//	float temp_float_part = float_value - temp_int_part;
//	int total_digit = 0;
//	while(temp_int_part > 0 && total_digit < max_size_float){
//			txBuff[max_size_float - 1 - total_digit] = ('0' + temp_int_part % 10);
//			temp_int_part /= 10;
//			total_digit++;
//		}
//	int size = max_size_float - total_digit - 1;
//	char temp_float_part_for_concatenate[size];
//	total_digit++;
//	while(temp_float_part > 0 && total_digit < size){
//		temp_float_part *= 10;
//		temp_float_part_for_concatenate[size] = (char)'0' + (int)temp_float_part;
//		temp_float_part -= (int)temp_float_part;
//		total_digit++;
//	}
//	temp_float_part_for_concatenate[0] = '0' - 2;
//	strcat(temp_float_part_for_concatenate, txBuff);
//
//}

void float_to_ascii_array(float float_value, char* txBuff) {
    // Convert float to string
    char float_str[20]; // Assuming a maximum of 20 characters for the string
    sprintf(float_str, "%f", float_value);

    // Copy characters to the ASCII array
    strcpy(txBuff, float_str);
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

//       Below is for Float Convertor
//	   float_convertor(float_value);
	   float_to_ascii_array(float_value, txBuff);

       LPUART_DRV_SendDataPolling(INST_TERMINAL_SCREEN, &txBuff, sizeof(txBuff));

       OSIF_TimeDelay(1000);

    }
    return exit_code;
}

/* END main */
/*!
** @}
*/
