// File: Blinken.c - Blinken einer DIODE
//
// XE167.h muss eingebunden werden, weil dann die symbolischen
// Namen wie z.B. P10_OUT_P0 verwendet werden können und nicht
// Adresse von P10_OUT_P0 verwendet werden muss!
//
#include <XE167F.h>
volatile unsigned int counter1,counter2;
// Funktion wait() braucht ~1 sek.

typedef unsigned int uword;
void MAIN_vUnlockProtecReg(void)
{
	uword uwPASSWORD;
	SCU_SLC = 0xAAAA; // command 0
	SCU_SLC = 0x5554; // command 1
	uwPASSWORD = SCU_SLS & 0x00FF;
	uwPASSWORD = (~uwPASSWORD) & 0x00FF;
	SCU_SLC = 0x9600 | uwPASSWORD; // command 2
	SCU_SLC = 0x0000; // command 3
}

void MAIN_vLockProtecReg(void)
{
	uword uwPASSWORD;
	SCU_SLC = 0xAAAA; // command 0
	SCU_SLC = 0x5554; // command 1
	uwPASSWORD = SCU_SLS & 0x00FF;
	uwPASSWORD = (~uwPASSWORD) & 0x00FF;
	SCU_SLC = 0x9600 | uwPASSWORD; // command 2
	SCU_SLC = 0x1800; // command 3; new PASSWOR is 0x00
	uwPASSWORD = SCU_SLS & 0x00FF;
	uwPASSWORD = (~uwPASSWORD) & 0x00FF;
	SCU_SLC = 0x8E00 | uwPASSWORD; // command 4
}

void led0 () {P10_OUT_P0 = ~P10_OUT_P0;}

void GPT2_viT6(void) interrupt 0x24 // Interrupt von Timer6
{
	led0();
}

void ledaus () {
	P10_OUT = 0xFFFF;
}

void main(void)
{

// Initialize IO
// Pin 0 von Port 10 auf "OUT"
P10_IOCR00 = 0x0080;


MAIN_vUnlockProtecReg();
	GPT12E_KSCCFG = 3;
	CC2_KSCCFG = 3;
MAIN_vLockProtecReg();
	

//1001 0000 1100 0111
GPT12E_T6CON 	= 0x90C7;
GPT12E_CAPREL	= 0x2000;
GPT12E_T6IC		= 0x0050;
PSW_IEN = 1;

ledaus();

// Wichtig: einfügen einer „Endlosschleife“
while (1) {


}
}