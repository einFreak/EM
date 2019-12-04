// File: Blinken.c - Blinken einer DIODE
//
// XE167.h muss eingebunden werden, weil dann die symbolischen
// Namen wie z.B. P10_OUT_P0 verwendet werden können und nicht
// Adresse von P10_OUT_P0 verwendet werden muss!
//
#include <XE167F.h>
volatile unsigned int counter1,counter2;
// Funktion wait() braucht ~1 sek.

void wait()
{
	counter1 = 0x40*0.15;
	while (counter1 > 0)
	{
		counter1--;
		counter2 = 0xFFFF;
		while (counter2 > 0)
		{
		counter2--;
		}
	}
}

void led0 () {P10_OUT_P0 = ~P10_OUT_P0;}
void led1 () {P10_OUT_P1 = ~P10_OUT_P1;}
void led2 () {P10_OUT_P2 = ~P10_OUT_P2;}
void led3 () {P10_OUT_P3 = ~P10_OUT_P3;}
void led4 () {P10_OUT_P4 = ~P10_OUT_P4;}
void led5 () {P10_OUT_P5 = ~P10_OUT_P5;}
void led6 () {P10_OUT_P6 = ~P10_OUT_P6;}
void led7 () {P10_OUT_P7 = ~P10_OUT_P7;}

void ledaus () {
	P10_OUT = 0xFFFF;
}

//Working
void blinkrb() {
	int mask  = 0xFFFF;
	int blink = 0x0001;
	int i;
	
	ledaus();
	P10_OUT = mask ^ blink;
	wait();
	for (i=0; i < 8; i++)
	{
		blink = blink<<1;
		P10_OUT = mask ^ blink;
		wait();
	}
	ledaus();
} 

//Working
void blinklb() {
	int i;
	int mask = 0xFFFF;
	int blink = 0x0080;
	
	ledaus();
	P10_OUT = mask ^ blink;
	wait();
	for (i=0; i < 8; i++)
	{
		blink = blink/2;
		//blink = blink>>1;
		P10_OUT = mask ^ blink;
		wait();
	}
	ledaus();
}

//von Außen nach Mitte und wieder raus
void blinkmb() {
	int mask = 0xFFFF;
	ledaus();
	wait();
	P10_OUT = mask ^ 0x0081;
	wait();
	P10_OUT = mask ^ 0x0042;
	wait();
	P10_OUT = mask ^ 0x0024;
	wait();
	P10_OUT = mask ^ 0x0018;
	wait();
	P10_OUT = mask ^ 0x0024;
	wait();
	P10_OUT = mask ^ 0x0042;
	wait();
	P10_OUT = mask ^ 0x0081;
	wait();
	ledaus();
}



void main(void)
{

// Initialize IO
// Pin 0-7 von Port 10 auf "OUT"
P10_IOCR00 = 0x0080;
P10_IOCR01 = 0x0080;
P10_IOCR02 = 0x0080;
P10_IOCR03 = 0x0080;
P10_IOCR04 = 0x0080;
P10_IOCR05 = 0x0080;
P10_IOCR06 = 0x0080;
P10_IOCR07 = 0x0080;

//Pin 2-5 von Port 4 auf "IN"
P4_IOCR02  = 0x0020;
P4_IOCR03  = 0x0020;
P4_IOCR04  = 0x0020;
P4_IOCR05  = 0x0020;

ledaus();
// Wichtig: einfügen einer „Endlosschleife“

while (1) {

	if (P4_IN_P2)	blinkrb();
	if (P4_IN_P3)	blinklb();
	if (P4_IN_P4)	blinkmb();

}
}