#include <XE167F.h>

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

void main() {
	
MAIN_vUnlockProtecReg;
	GPT12E_KSCCFG = 3;
	CC2_KSCCFG		= 3;
MAIN_vLockProtecReg;
	
}