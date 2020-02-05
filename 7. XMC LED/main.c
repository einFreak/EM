/*
 * main.c
 *
 *  Created on: 2020 Jan 08 11:48:52
 *  Author: wif32384
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if(status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  void LED1_IRQHandler (void)
  {
  DIGITAL_IO_ToggleOutput(&LED1);
  }

  uint32_t BTN2_status;

  while(1U)
  {
	  BTN2_status = DIGITAL_IO_GetInput(&BTN2);
	  if(BTN2_status != 0)
	  {
		  DIGITAL_IO_SetOutputLow(&LED2);
	  }
	  else
	  {
		  DIGITAL_IO_SetOutputHigh(&LED2);
	  }


  }


}
