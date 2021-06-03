#include "stdint.h"
#include <string.h>	
#include <stdlib.h>
#include <math.h>
#include "tm4c123gh6pm.h"

#define PI 3.14159265359
#define R 6372795
#define DISTINATION_OFFSET 10		

void SystemInit(void){
	NVIC_CPAC_R |= 0x00F00000;		//enable FPU - Floating-point numbers
}

int main(void){

}
