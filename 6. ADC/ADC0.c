//****************************************************************************
// @Module        Analog / Digital Converter  (ADC0)
// @Filename      ADC0.c
// @Project       DAVE-ADC.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE169FH-200F100
//
// @Compiler      Keil
//
// @Codegenerator 2.1
//
// @Description   This file contains functions that use the ADC0 module.
//
//----------------------------------------------------------------------------
// @Date          04.12.2019 12:51:08
//
//****************************************************************************

// USER CODE BEGIN (ADC0_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"

// USER CODE BEGIN (ADC0_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (ADC0_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (ADC0_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (ADC0_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (ADC0_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (ADC0_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (ADC0_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (ADC0_General,9)

// USER CODE END


//****************************************************************************
// @Function      void ADC0_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the ADC function 
//                library. It is assumed that the SFRs used by this library 
//                are in reset state. 
//                
//                Following SFR fields will be initialized:
//                GLOBCTR  - Global Control
//                RSPR0    - Priority and Arbitration Register
//                ASENR    - Arbitration slot enable register
//                CHCTRx   - Channel Control Register x
//                RCRx     - Result Control Register x
//                KSCFG    - Module configuration Register
//                INPCR    - Input class Registers
//                CHINPRx  - Channel Interrupt register
//                EVINPRx  - Event Interrupt register
//                SYNCTR   - Synchronisation control register
//                LCBRx    - Limit check boundary register
//                PISEL    - Port input selection
//                QMR0     - Sequential 0 mode register
//                CRMR1    - Parallel mode register
//                QMR2     - Sequential 2 mode register
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

// USER CODE BEGIN (ADC0_Init,1)

// USER CODE END

void ADC0_vInit(void)
{
  volatile unsigned int uwTemp;

  // USER CODE BEGIN (ADC0_Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of ADC0 kernel configuration register:
  ///  -----------------------------------------------------------------------

  ADC0_KSCFG     =  0x0003;      // load ADC0 kernel configuration register

  ///  - the ADC module clock is enabled
  ///  - the ADC module clock = 100,00 MHz

  uwTemp         =  ADC0_KSCFG;  // dummy read to avoid pipeline effects

  ///  -----------------------------------------------------------------------
  ///  Configure global control register:
  ///  -----------------------------------------------------------------------
  ///  --- Conversion Timing -----------------
  ///  - Conversion time (CTC) = 00,85 us
  ///  - Analog clock is 1/5th of module clock and digital clock is 1/1 times 
  ///  of module clock

  ///  - the permanent arbitration mode is selected

  ADC0_GLOBCTR   =  0x0004;      // load global control register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Arbitration Slot enable register and also the Source 
  ///  Priority register:
  ///  -----------------------------------------------------------------------
  ///  - Arbitration Slot 0 is enabled
  ///  - Arbitration Slot 1 is enabled
  ///  - Arbitration Slot 2 is enabled
  ///  - the priority of request source 0 is low
  ///  - the wait-for-start mode is selected for source 0
  ///  - the priority of request source 1 is low
  ///  - the wait-for-start mode is selected for source 1
  ///  - the priority of request source 2 is low
  ///  - the wait-for-start mode is selected for source 2

  ADC0_ASENR     =  0x0007;      // load Arbitration Slot enable register

  ADC0_RSPR0     =  0x0000;      // load Priority and Arbitration register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Channel Control Registers:
  ///  -----------------------------------------------------------------------
  ///  Configuration of Channel 0
  ///  - the result register0 is selected
  ///  - the limit check 0 is selected
  ///  - the reference voltage selected is Standard Voltage (Varef)
  ///  - the input class selected is Input Class 0
  ///  - LCBR0 is selected as upper boundary
  ///  - LCBR1 is selected as lower boundary

  ADC0_CHCTR0    =  0x0004;      // load channel control register

  ///  - No ADC0 Channels are selected

  ///  -----------------------------------------------------------------------
  ///  Configuration of Sample Time and Resolution:
  ///  -----------------------------------------------------------------------

  ///  8 bit resolution selected

  ADC0_INPCR0    =  0x0200;      // load input class0 register

  ///  8 bit resolution selected

  ADC0_INPCR1    =  0x0200;      // load input class1 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Result Control Registers:
  ///  -----------------------------------------------------------------------
  ///  Configuration of Result Control Register 0
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is enabled
  ///  - the FIFO functionality is disabled

  ADC0_RCR0      =  0x0040;      // load result control register 0

  ///  Configuration of Result Control Register 1
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled
  ///  - the FIFO functionality is disabled

  ADC0_RCR1      =  0x0000;      // load result control register 1

  ///  Configuration of Result Control Register 2
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled
  ///  - the FIFO functionality is disabled

  ADC0_RCR2      =  0x0000;      // load result control register 2

  ///  Configuration of Result Control Register 3
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled
  ///  - the FIFO functionality is disabled

  ADC0_RCR3      =  0x0000;      // load result control register 3

  ///  Configuration of Result Control Register 4
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled
  ///  - the FIFO functionality is disabled

  ADC0_RCR4      =  0x0000;      // load result control register 4

  ///  Configuration of Result Control Register 5
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled
  ///  - the FIFO functionality is disabled

  ADC0_RCR5      =  0x0000;      // load result control register 5

  ///  Configuration of Result Control Register 6
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled
  ///  - the FIFO functionality is disabled

  ADC0_RCR6      =  0x0000;      // load result control register 6

  ///  Configuration of Result Control Register 7
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled
  ///  - the FIFO functionality is disabled

  ADC0_RCR7      =  0x0000;      // load result control register 7

  ///  -----------------------------------------------------------------------
  ///  Configuration of Channel Interrupt Node Pointer Register:
  ///  -----------------------------------------------------------------------
  ///  - the SR0 line become activated if channel 0 interrupt is generated

  ADC0_CHINPR0   =  0x0000;      // load channel interrupt node pointer 
                                 // register


  ADC0_CHINPR4   =  0x0000;      // load channel interrupt node pointer 
                                 // register


  ADC0_CHINPR8   =  0x0000;      // load channel interrupt node pointer 
                                 // register


  ADC0_CHINPR12  =  0x0000;      // load channel interrupt node pointer 
                                 // register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Event Interrupt Node Pointer Register for Source 
  ///  Interrupts:
  ///  -----------------------------------------------------------------------
  ///  - the SR 0 line become activated if the event 0 interrupt is generated
  ///  - the SR 0 line become activated if the event 1 interrupt is generated
  ///  - the SR 0 line become activated if the event 2 interrupt is generated

  ADC0_EVINPR0   =  0x0000;      // load event interrupt set flag register 

  ///  -----------------------------------------------------------------------
  ///  Configuration of Event Interrupt Node Pointer Register for Result 
  ///  Interrupts:
  ///  -----------------------------------------------------------------------

  ADC0_EVINPR8   =  0x0000;      // load event interrupt set flag register 


  ADC0_EVINPR12  =  0x0000;      // load event interrupt set flag register 

  ///  -----------------------------------------------------------------------
  ///  Configuration of Service Request Nodes 0 - 3 :
  ///  -----------------------------------------------------------------------

  ///  -----------------------------------------------------------------------
  ///  Configuration of Limit Check Boundary:
  ///  -----------------------------------------------------------------------

  ADC0_LCBR0     =  0x0198;      // load limit check boundary register 0

  ADC0_LCBR1     =  0x0E64;      // load limit check boundary register 1

  ADC0_LCBR2     =  0x0554;      // load limit check boundary register 2

  ADC0_LCBR3     =  0x0AA8;      // load limit check boundary register 3

  ///  -----------------------------------------------------------------------
  ///  Configuration of Gating source and External Trigger Control:
  ///  -----------------------------------------------------------------------
  ///  - No Gating source selected for Arbitration Source 0

  ///  - the trigger input selection is not enabled for source 0

  ADC0_RSIR0     =  0x0000;      // load external trigger control register 
                                 // for Request Source 0

  ///  - No Gating source selected for Arbitration Source 1

  ///  - the trigger input TRSEL selection is not enabled for Source 1

  ADC0_RSIR1     =  0x0000;      // load external trigger control register 
                                 // for Request Source 1

  ///  - No Gating source selected for Arbitration Source 2

  ///  - the trigger input TRSEL selection is not enabled for Source 2

  ADC0_RSIR2     =  0x0000;      // load external trigger control register 
                                 // for Request Source 2

  ///  -----------------------------------------------------------------------
  ///  Configuration of Conversion Queue Mode Register:Sequential Source 0
  ///  -----------------------------------------------------------------------
  ///  - the gating line is permanently Enabled
  ///  - the external trigger is disabled

  ADC0_QMR0      =  0x0001;      // load queue mode register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Conversion Queue Mode Register:Sequential Source 2
  ///  -----------------------------------------------------------------------
  ///  - the gating line is permanently Enabled
  ///  - the external trigger is disabled

  ADC0_QMR2      =  0x0001;      // load queue mode register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Conversion Request Mode Registers:Parallel Source 
  ///  -----------------------------------------------------------------------
  ///  - the gating line is permanently Enabled
  ///  - the external trigger is disabled
  ///  - the source interrupt is disabled
  ///  - the autoscan functionality is disabled

  ADC0_CRMR1     =  0x0001;      // load conversion request mode register 1

  ///  -----------------------------------------------------------------------
  ///  Configuration of Synchronisation Registers:
  ///  -----------------------------------------------------------------------
  ///  - ADC0 is master 

  ADC0_SYNCTR   |=  0x0010;      // Synchronisation register

  P5_DIDIS       =  0x0001;      // Port 5 Digital input disable register

  ADC0_GLOBCTR  |=  0x0300;      // turn on Analog part


  // USER CODE BEGIN (ADC0_Init,3)

  // USER CODE END

} //  End of function ADC0_vInit




// USER CODE BEGIN (ADC0_General,10)

// USER CODE END

