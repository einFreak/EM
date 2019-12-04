//****************************************************************************
// @Module        Project Settings
// @Filename      MAIN.c
// @Project       DAVE-LED.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XE169FH-200F100
//
// @Compiler      Keil
//
// @Codegenerator 2.1
//
// @Description   This file contains the project initialization function.
//
//----------------------------------------------------------------------------
// @Date          27.11.2019 13:00:45
//
//****************************************************************************

// USER CODE BEGIN (MAIN_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"

// USER CODE BEGIN (MAIN_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (MAIN_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (MAIN_General,4)
	#define LCD_RS	P3_OUT_P3
	#define LCD_RW	P3_OUT_P4
	#define LCD_E	P3_OUT_P5
	#define LCD_D	P9_OUT
// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (MAIN_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,7)
int global_Timer100ns = 0;
int global_Timer50us = 0;
// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (MAIN_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (MAIN_General,9)

// USER CODE END


//****************************************************************************
// @Function      void MAIN_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This function initializes the microcontroller.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          27.11.2019
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void MAIN_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  //   globally disable interrupts
  PSW_IEN        =  0;          


  ///  -----------------------------------------------------------------------
  ///  Configuration of the System Clock:
  ///  -----------------------------------------------------------------------
  ///  - VCO clock used, input clock is connected
  ///  - input frequency is 8,00 MHz
  ///  - system clock is 100.00 MHz

  MAIN_vUnlockProtecReg();     // unlock write security

  MAIN_vChangeFreq();          // load PLL control register

  //   -----------------------------------------------------------------------
  //   SCU Interrupt Disable configuration:
  //   -----------------------------------------------------------------------
  SCU_INTDIS     =  0xFFFF;      // SCU Interrupt Disable Register

  //   -----------------------------------------------------------------------
  //   Initialization of the Peripherals:
  //   -----------------------------------------------------------------------

  //   initializes the Parallel Ports
  IO_vInit();

  //   initializes the General Purpose Timer Unit (GPT1)
  GPT1_vInit();

  //   initializes the General Purpose Timer Unit (GPT2)
  GPT2_vInit();

  //   initializes the Capture / Compare Unit 2 (CAPCOM2)
  CC2_vInit();


  //   -----------------------------------------------------------------------
  //   Initialization of the Bank Select registers:
  //   -----------------------------------------------------------------------


  //   -----------------------------------------------------------------------
  //   SCU Interrupt Source Selection configuration:
  //   -----------------------------------------------------------------------
  SCU_ISSR       =  0x0000;      // SCU Interrupt Source Select Register

  SCU_ISSR1      =  0x0000;      // SCU Interrupt Source Select 1 Register

  SCU_ISSR2      =  0x0000;      // SCU Interrupt Source Select 2 Register

  // USER CODE BEGIN (Init,3)

  // USER CODE END

  MAIN_vLockProtecReg();       // lock write security

  //   globally enable interrupts
  PSW_IEN        =  1;          

} //  End of function MAIN_vInit


//****************************************************************************
// @Function      void MAIN_vUnlockProtecReg(void) 
//
//----------------------------------------------------------------------------
// @Description   This function makes it possible to write one protected 
//                register.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          27.11.2019
//
//****************************************************************************

// USER CODE BEGIN (UnlockProtecReg,1)

// USER CODE END

void MAIN_vUnlockProtecReg(void)
{
  uword uwPASSWORD;

    SCU_SLC = 0xAAAA;                   // command 0
    SCU_SLC = 0x5554;                   // command 1

    uwPASSWORD = SCU_SLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;

    SCU_SLC = 0x9600 | uwPASSWORD;      // command 2
    SCU_SLC = 0x0000;                   // command 3

} //  End of function MAIN_vUnlockProtecReg


//****************************************************************************
// @Function      void MAIN_vLockProtecReg(void) 
//
//----------------------------------------------------------------------------
// @Description   This function makes it possible to lock one protected 
//                register.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          27.11.2019
//
//****************************************************************************

// USER CODE BEGIN (LockProtecReg,1)

// USER CODE END

void MAIN_vLockProtecReg(void)
{
  uword uwPASSWORD;

    SCU_SLC = 0xAAAA;                   // command 0
    SCU_SLC = 0x5554;                   // command 1

    uwPASSWORD = SCU_SLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;

    SCU_SLC = 0x9600 | uwPASSWORD;      // command 2
    SCU_SLC = 0x1800;                   // command 3; new PASSWOR is 0x00

    uwPASSWORD = SCU_SLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;
    SCU_SLC = 0x8E00 | uwPASSWORD;      // command 4

} //  End of function MAIN_vLockProtecReg


//****************************************************************************
// @Function      void MAIN_vChangeFreq(void) 
//
//----------------------------------------------------------------------------
// @Description   This function is used to select the external crystal and
//                configure the system frequency to 100MHz/80MHz/66MHz.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          27.11.2019
//
//****************************************************************************

// USER CODE BEGIN (ChangeFreq,1)

// USER CODE END

void MAIN_vChangeFreq(void)
{
  Scs_ErrorType Error;

  Scs_EnableHighPrecOsc(1U);

  //For application and internal application resets, the complete PLL configuration could be avoided
  //The entry from application resets and internal application reset is covered in the following differentiation
  //in int/ext clock in lock/unlocked state.

  if  ((SCU_PLLSTAT & 0x0004) == 0x0004)       // fR derived from Internal clock
  {
    //Normal startup state during boot and the clock
    //has to be in the next step configured on the external crystal
    //use XTAL/VCO, count XTAL clock

    Scs_InitTimer();       // initialize CCU6 timer T13 for SCS driver

    // perform transition from base mode to normal mode, check for error
    Error = Scs_GoFromBaseModeToNormalMode();
    if(Error)
    {
      for(;;)      // this part of code should not be reached
      {
        NOP();
      }
    }

    if ((SCU_PLLSTAT & 0x1009) == 0x1009)      // fR derived from external crystal clock + VCO is locked
    {
      //usually after an application reset where clock need not be configured again.
      //check K2/P/N values and decide whether these values have to be adapted based on application needs.
      NOP();
      //usually the PLL losss of Lock TRAP schould be enabled here.
    }
    else       //fR derived from external crystal clock + VCO is not locked
    {
               //estimate the K1 value and the current frequency
               //reduce K2/P/N values in steps so that the frequency
               //jumps is limited to 20MHz or factor of 5 whichever is minimum
      NOP();
    }


  }

} //  End of function MAIN_vChangeFreq


//****************************************************************************
// @Function      void main(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the main function.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          27.11.2019
//
//****************************************************************************

// USER CODE BEGIN (Main,1)
//wait auslegen auf 100ns
void wait100ns (unsigned int runtime) {
	global_Timer100ns = 0;
	GPT12E_T6CON_T6R = 1; //reset Timer6
	while(global_Timer100ns < runtime) {
		//wait till interupt is executed as often as runtime whises
	}
}

void wait50us (unsigned int runtime) {
	global_Timer50us = 0;
	GPT12E_T6CON_T6R = 1; //reset Timer6
	while(global_Timer50us < runtime) {
		//wait till interupt is executed as often as runtime whises
	}
}



void LCDcommand (unsigned int com) {
	//function set
	LCD_RS = 0;
	LCD_RW = 0;
	//1x wait = 100ns => 100ns + 10ns just to be save
	wait100ns(1);
	NOP();
	LCD_E = 1;
	//30ns
	NOP();
	NOP();
	NOP();
	//insert command
	LCD_D	 = com;
	//wait Enable pulse width (300ns)
	wait100ns(3);
	LCD_E = 0;
	//wait read data hold time 10ns +10ns safety
	NOP();
	NOP();
}

void LCDdata (unsigned int data) {
	//function set
	LCD_RS = 1;
	LCD_RW = 0;
	//1x wait = 100ns => 100ns + 10ns just to be save
	wait100ns(1);
	NOP();
	LCD_E = 1;
	//30ns
	NOP();
	NOP();
	NOP();
	//insert command
	LCD_D	 = data;
	//wait Enable pulse width (300ns)
	wait100ns(3);
	LCD_E = 0;
	//wait read data hold time 10ns +10ns safety
	NOP();
	NOP();
	wait50us(1);
}
// USER CODE END

void main(void)
{
  // USER CODE BEGIN (Main,2)

  // USER CODE END

  MAIN_vInit();

  // USER CODE BEGIN (Main,3)
	
	//function set 0011 1111
	LCDcommand(0x3F);
	//execution time 39us => wait 50us
	wait50us(1);
	
	//Display OnOff Control 0000 1111 (1 + Display on + Curser on + cBlink on)
	LCDcommand(0x0F);
	//no wait needed
	
	//Clear Display 
	LCDcommand(0x01)
	//wait execution time 1,53ms = 1,53 * 1000 = 1530
	wait50us(1550/50);
	
	
	//write Hallo!
	LCDdata(0x48);
	LCDdata(0x61);
	LCDdata(0x6c);
	LCDdata(0x6c);
	LCDdata(0x6f);
	LCDdata(0x21);
	
	//next line 1100 0000 (0x40 = 2nd line, 0x80 = set DDRAM address)
	LCDcommand(0xC0);
	wait50us(1);
	
	//write Embedded World
	LCDdata(0x45);
	LCDdata(0x6D);
	LCDdata(0x62);
	LCDdata(0x65);
	LCDdata(0x64);
	LCDdata(0x64);
	LCDdata(0x65);
	LCDdata(0x64);
	LCDdata(0x20);
	LCDdata(0x57);
	LCDdata(0x6F);
	LCDdata(0x72);
	LCDdata(0x6C);
	LCDdata(0x64);
	
	
  // USER CODE END
  while(1)
  {

   // USER CODE BEGIN (Main,4)
	wait(500000/50);
	P10_OUT_P0 = ~P10_OUT_P0;
	
	//TODO Timer 6/7 einstellen auf 100ns/50us
   // USER CODE END

  }

} //  End of function main



// USER CODE BEGIN (MAIN_General,10)

// USER CODE END


