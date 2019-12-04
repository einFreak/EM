//****************************************************************************
// @Module        Capture / Compare Unit 2 (CAPCOM2)
// @Filename      CC2.c
// @Project       cc2.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE169FH-200F100
//
// @Compiler      Keil
//
// @Codegenerator 2.1
//
// @Description   This file contains functions that use the CC2 module.
//
//----------------------------------------------------------------------------
// @Date          30.10.2019 13:10:36
//
//****************************************************************************

// USER CODE BEGIN (CC2_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"

// USER CODE BEGIN (CC2_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (CC2_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (CC2_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (CC2_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (CC2_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (CC2_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (CC2_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (CC2_General,9)

// USER CODE END


//****************************************************************************
// @Function      void CC2_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the CAPCOM2 function 
//                library. It is assumed that the SFRs used by this library 
//                are in reset state. 
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          30.10.2019
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void CC2_vInit(void)
{
  volatile unsigned int uwTemp;
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of  Kernel state configuration Control:
  ///  -----------------------------------------------------------------------
  ///  - the Peripheral is supplied with clock signal for CAPCOM2 unit
  ///  - the CC2 module clock = 100,00 MHz

  CC2_KSCCFG     =  0x0003;      // load CAPCOM2 Kernel state configuration 
                                 // register

  uwTemp         =  CC2_KSCCFG;  // dummy read to avoid pipeline effects

  ///  -----------------------------------------------------------------------
  ///  Configuration of CAPCOM2 Control:
  ///  -----------------------------------------------------------------------
  ///  - staggered mode is enabled

  ///  -----------------------------------------------------------------------
  ///  Configuration of CAPCOM2 Timer 7:
  ///  -----------------------------------------------------------------------
  ///  - timer 7 works in timer mode
  ///  - prescaler factor is 8
  ///  - timer 7 run bit is reset

  ///  -----------------------------------------------------------------------
  ///  Configuration of CAPCOM2 Timer 8:
  ///  -----------------------------------------------------------------------
  ///  - timer 8 works in timer mode
  ///  - prescaler factor is 1024
  ///  - timer 8 run bit is reset


  CC2_T78CON     =  0x0700;      // load CAPCOM2 timer 7 and timer 8 control 
                                 // register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Timer Port Pins:
  ///  -----------------------------------------------------------------------


  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Timer Interrupts:
  ///  -----------------------------------------------------------------------


  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 16:
  ///  -----------------------------------------------------------------------
  ///  - capture on Positive transition (rising edge) at pin CC16IO (P2.3)
  ///  - CC16 allocated to CAPCOM2 timer 7
  ///  - single event mode is disabled


  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 17:
  ///  -----------------------------------------------------------------------
  ///  - channel 17 is disabled

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 18:
  ///  -----------------------------------------------------------------------
  ///  - capture on Positive transition (rising edge) at pin CC18IO (P2.5)
  ///  - CC18 allocated to CAPCOM2 timer 8
  ///  - single event mode is disabled


  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 19:
  ///  -----------------------------------------------------------------------
  ///  - channel 19 is disabled

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 20:
  ///  -----------------------------------------------------------------------
  ///  - channel 20 is disabled

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 21:
  ///  -----------------------------------------------------------------------
  ///  - channel 21 is disabled

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 22:
  ///  -----------------------------------------------------------------------
  ///  - channel 22 is disabled

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 23:
  ///  -----------------------------------------------------------------------
  ///  - channel 23 is disabled

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 24:
  ///  -----------------------------------------------------------------------
  ///  - channel 24 is disabled

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 25:
  ///  -----------------------------------------------------------------------
  ///  - channel 25 is disabled

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 26:
  ///  -----------------------------------------------------------------------
  ///  - channel 26 is disabled

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 27:
  ///  -----------------------------------------------------------------------
  ///  - channel 27 is disabled

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 28:
  ///  -----------------------------------------------------------------------
  ///  - channel 28 is disabled

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 29:
  ///  -----------------------------------------------------------------------
  ///  - channel 29 is disabled

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 30:
  ///  -----------------------------------------------------------------------
  ///  - channel 30 is disabled

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 31:
  ///  -----------------------------------------------------------------------
  ///  - channel 31 is disabled

  CC2_M4         =  0x0901;      // load CAPCOM2 mode register 4

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel Port Pins:
  ///  -----------------------------------------------------------------------
  ///  - P2.3 is used for CAPCOM2 input(CC2_16)
  ///  - P2.5 is used for CAPCOM2 input(CC2_18)

  P2_IOCR03 = 0x0010;    //set direction register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channels Interrupts:
  ///  -----------------------------------------------------------------------
  ///  CC16 service request node configuration:
  ///  - CC16 interrupt priority level (ILVL) = 1
  ///  - CC16 interrupt group level (GLVL) = 0
  ///  - CC16 group priority extension (GPX) = 0

  CC2_CC16IC     =  0x0044;     


  ///  CC18 service request node configuration:
  ///  - CC18 interrupt priority level (ILVL) = 1
  ///  - CC18 interrupt group level (GLVL) = 1
  ///  - CC18 group priority extension (GPX) = 0

  CC2_CC18IC     =  0x0045;     




  // USER CODE BEGIN (CC31,3)

  // USER CODE END

} //  End of function CC2_viCC31


//****************************************************************************
// @Function      void CC2_viCC16(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the CAPCOM2 
//                Channel CC16. If the content of the corresponding compare 
//                timer (configurable) equals the content of the 
//                capture/compare register CC16 or if a capture event occurs 
//                at the associated port pin, the interrupt request flag is 
//                set and an interrupt is triggered (only if enabled).
//                Please note that you have to add application specific code 
//                to this function.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          30.10.2019
//
//****************************************************************************

// USER CODE BEGIN (CC16,1)
int counter = 0;
// USER CODE END

void CC2_viCC16(void) interrupt CC2_CC16INT
{
  // USER CODE BEGIN (CC16,2)
	
	// Schaltzähler
	/* int mask  = 0xFFFF;
	int blink = 0x0000;
	int pot = 2;
	int i;
	counter++;
	for (i=0; i < counter; i++)
	{
		blink = pot-1;
		P10_OUT = mask ^ blink;
		pot = pot * 2;
		
	}
	
	if (counter > 7) counter = 0; */
 
	CC2_T8REL = 0;
	CC2_T78CON_T8R = 1;

  // USER CODE END

} //  End of function CC2_viCC16


//****************************************************************************
// @Function      void CC2_viCC18(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the CAPCOM2 
//                Channel CC18. If the content of the corresponding compare 
//                timer (configurable) equals the content of the 
//                capture/compare register CC18 or if a capture event occurs 
//                at the associated port pin, the interrupt request flag is 
//                set and an interrupt is triggered (only if enabled).
//                Please note that you have to add application specific code 
//                to this function.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          30.10.2019
//
//****************************************************************************

// USER CODE BEGIN (CC18,1)

// USER CODE END

void CC2_viCC18(void) interrupt CC2_CC18INT
{
  // USER CODE BEGIN (CC18,2)
	int mask  = 0xFFFF;
	int blink = 0x0000;
	CC2_T78CON_T8R = 0;
	blink = CC2_CC18 >> 8;
	P10_OUT = mask ^ blink;
  // USER CODE END

} //  End of function CC2_viCC18




// USER CODE BEGIN (CC2_General,10)

// USER CODE END

