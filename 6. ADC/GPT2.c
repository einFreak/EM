//****************************************************************************
// @Module        General Purpose Timer Unit (GPT2)
// @Filename      GPT2.c
// @Project       DAVE-ADC.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE169FH-200F100
//
// @Compiler      Keil
//
// @Codegenerator 2.1
//
// @Description   This file contains functions that use the GPT2 module.
//
//----------------------------------------------------------------------------
// @Date          04.12.2019 12:51:08
//
//****************************************************************************

// USER CODE BEGIN (GPT2_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"

// USER CODE BEGIN (GPT2_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (GPT2_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (GPT2_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (GPT2_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (GPT2_General,6)
extern int global_Timer100ns;
extern int global_Timer50us;
// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (GPT2_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (GPT2_General,8)

// USER CODE END



//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (GPT2_General,9)

// USER CODE END


//****************************************************************************
// @Function      void GPT2_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the GPT2 function 
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
// @Date          04.12.2019
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void GPT2_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END
  ///  -----------------------------------------------------------------------
  ///  Configuration of Timer Block Prescaler 2:
  ///  -----------------------------------------------------------------------
  ///  - prescaler for timer block 2 is 2


  ///  -----------------------------------------------------------------------
  ///  Configuration of the GPT2 Core Timer 5:
  ///  -----------------------------------------------------------------------
  ///  - timer 5 works in timer mode
  ///  - prescaler factor is 2
  ///  - up/down control bit is reset
  ///  - external up/down control is disabled
  ///  - timer 5 remote control is disabled

  GPT12E_T5CON   =  0x0000;      // load timer 5 control register
  GPT12E_T5      =  0xFFFB;      // load timer 5 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the GPT2 Core Timer 6:
  ///  -----------------------------------------------------------------------
  ///  - timer 6 works in timer mode
  ///  - prescaler factor is 2
  ///  - up/down control bit is reset
  ///  - external up/down control is disabled
  ///  - alternate output function T6OUT (P6.2) is disabled
  ///  - alternate output function T6OUT (P7.0) is disabled
  ///  - alternate output function T6OUT (P13.7) is disabled
  ///  - timer 6 output toggle latch (T6OTL) is set to 0
  ///  - timer 6 is not cleared on a capture

  GPT12E_T6CON   =  0x0800;      // load timer 6 control register
  GPT12E_T6      =  0xF63C;      // load timer 6 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the GPT2 CAPREL:
  ///  -----------------------------------------------------------------------
  ///  - capture T5 into CAPREL is disabled
  ///  - capture trigger from pin CAPIN
  ///  - capure is disabled
  ///  - timer 5 is not cleared on a capture

  GPT12E_T5CON  |=  0x0000;      // load timer 5 control register
  GPT12E_CAPREL  =  0x0000;      // load CAPREL register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used GPT2 Port Pins:
  ///  -----------------------------------------------------------------------



  ///  -----------------------------------------------------------------------
  ///  Configuration of the used GPT2 Interrupts:
  ///  -----------------------------------------------------------------------
  ///  timer 5 service request node configuration:
  ///  - timer 5 interrupt priority level (ILVL) = 1
  ///  - timer 5 interrupt group level (GLVL) = 0
  ///  - timer 5 group priority extension (GPX) = 0

  GPT12E_T5IC    =  0x0044;     

  ///  timer 6 service request node configuration:
  ///  - timer 6 interrupt priority level (ILVL) = 1
  ///  - timer 6 interrupt group level (GLVL) = 1
  ///  - timer 6 group priority extension (GPX) = 0

  GPT12E_T6IC    =  0x0045;     



  // USER CODE BEGIN (GPT2_Function,3)

  // USER CODE END

  GPT12E_T5CON_T5R  =  1;        // set timer 5 run bit

  GPT12E_T6CON_T6R  =  1;        // set timer 6 run bit

} //  End of function GPT2_viCAPREL

//****************************************************************************
// @Function      void GPT2_viTmr6(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the GPT2 timer 6. 
//                It is called up in the case of over or underflow of the 
//                timer 6 register.
//                
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
// @Date          04.12.2019
//
//****************************************************************************

// USER CODE BEGIN (Tmr6,1)

// USER CODE END

void GPT2_viTmr6(void) interrupt T6INT
{
  // USER CODE BEGIN (Tmr6,2)
  //T6 soll im 100us Takt zählen
	global_Timer50us++;
  // USER CODE END

} //  End of function GPT2_viTmr6


//****************************************************************************
// @Function      void GPT2_viTmr5(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the GPT2 timer 5. 
//                It is called up in the case of over or underflow of the 
//                timer 5 register.
//                
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
// @Date          04.12.2019
//
//****************************************************************************

// USER CODE BEGIN (Tmr5,1)

// USER CODE END

void GPT2_viTmr5(void) interrupt T5INT
{
  // USER CODE BEGIN (Tmr5,2)
  //T5 soll im 100ns Takt zählen
	global_Timer100ns++;
  // USER CODE END

} //  End of function GPT2_viTmr5




// USER CODE BEGIN (GPT2_General,10)

// USER CODE END

