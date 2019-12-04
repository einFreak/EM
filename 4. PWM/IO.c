//****************************************************************************
// @Module        Parallel Ports
// @Filename      IO.c
// @Project       PWM.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE169FH-200F100
//
// @Compiler      Keil
//
// @Codegenerator 2.1
//
// @Description   This file contains functions that use the IO module.
//
//----------------------------------------------------------------------------
// @Date          13.11.2019 12:47:14
//
//****************************************************************************

// USER CODE BEGIN (IO_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"

// USER CODE BEGIN (IO_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (IO_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (IO_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (IO_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (IO_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (IO_General,9)

// USER CODE END


//****************************************************************************
// @Function      void IO_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the IO function 
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
// @Date          13.11.2019
//
//****************************************************************************

// USER CODE BEGIN (IO_Function,1)

// USER CODE END

void IO_vInit(void)
{
  // USER CODE BEGIN (IO_Function,2)

  // USER CODE END


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P0:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P0 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P1:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P1 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P2:
  ///  -----------------------------------------------------------------------
  ///  P2.3 is used as alternate output for the CAPCOM2 output(CC2_16)
  ///  - push/pull output is selected

  ///  P2.0 - P2.3 output driver characteristic: strong driver
  ///  P2.4 - P2.7 output driver characteristic: strong driver
  ///  P2.8 - P2.13 output driver characteristic: strong driver

  ///  P2.0 - P2.3 output edge characteristic: sharp edge mode
  ///  P2.4 - P2.7 output edge characteristic: sharp edge mode
  ///  P2.8 - P2.13 output edge characteristic: sharp edge mode


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P3:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P3 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P4:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P4 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P5:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P5 is used
  ///  - Port5 Data register P5(Read only)


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P6:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P6 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P7:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P7 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P8:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P8 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P9:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P9 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P10:
  ///  -----------------------------------------------------------------------
  ///  P10.0 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.1 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.2 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.3 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.4 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.5 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.6 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P10.7 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level

  ///  P10.0 - P10.3 output driver characteristic: strong driver
  ///  P10.4 - P10.7 output driver characteristic: strong driver
  ///  P10.8 - P10.11 output driver characteristic: strong driver
  ///  P10.12 - P10.15 output driver characteristic: strong driver

  ///  P10.0 - P10.3 output edge characteristic: sharp edge mode
  ///  P10.4 - P10.7 output edge characteristic: sharp edge mode
  ///  P10.8 - P10.11 output edge characteristic: sharp edge mode
  ///  P10.12 - P10.15 output edge characteristic: sharp edge mode

  P10_IOCR00     =  0x0080;      // load port control register 0
  P10_IOCR01     =  0x0080;      // load port control register 1
  P10_IOCR02     =  0x0080;      // load port control register 2
  P10_IOCR03     =  0x0080;      // load port control register 3
  P10_IOCR04     =  0x0080;      // load port control register 4
  P10_IOCR05     =  0x0080;      // load port control register 5
  P10_IOCR06     =  0x0080;      // load port control register 6
  P10_IOCR07     =  0x0080;      // load port control register 7

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P11:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P11 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P12:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P12 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P13:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P13 is used


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P14:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P14 is used
  ///  - Port14 Data register P14(Read only)


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P15:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P15 is used
  ///  - Port15 Data register P15(Read only)



  // USER CODE BEGIN (IO_Function,3)

  // USER CODE END

} //  End of function IO_vInit




// USER CODE BEGIN (IO_General,10)

// USER CODE END

