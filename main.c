#include "stdint.h"
#include <string.h>	
#include <stdlib.h>
#include <math.h>
#include "tm4c123gh6pm.h"

#define PI 3.14159265359
#define R 6372795
#define DISTINATION_OFFSET 10		


uint8_t  numbersArr[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
uint32_t distance = 0;
uint8_t	currentnumber=0;



void SystemInit(void){
	NVIC_CPAC_R |= 0x00F00000;		//enable FPU - Floating-point numbers
}

void portE_enables_init (void){
	SYSCTL_RCGCGPIO_R |=0x10;
		while (( SYSCTL_PRGPIO_R &0x10) == 0);
		GPIO_PORTE_LOCK_R=0x4c4f434b ;
		GPIO_PORTE_CR_R |=0X1E ;
		GPIO_PORTE_AFSEL_R &=~ 0X1E;		
		GPIO_PORTE_PCTL_R = 0;
		GPIO_PORTE_AMSEL_R &=~0X1E;
		GPIO_PORTE_DEN_R |=0X1E;
		GPIO_PORTE_DIR_R |=0X1E;
		GPIO_PORTE_PUR_R |=0X00;
		
	}

double getDistance(double p1[],double p2[]){
   double lat1=p1[0];
   double lon1=p1[1];
   double lat2=p2[0];
   double lon2=p2[1];
	 double x1 = lat1*(PI/180);
   double x2 = lat2*(PI/180);
   double dx = (lat2-lat1)*(PI/180);
   double dy = (lon2-lon1)*(PI/180);

   double a=sin((dx/2))*sin((dx/2))+cos((x1))*cos((x2))
         *sin((dy/2))*sin((dy/2));
   double c=2*atan2(sqrt(a),sqrt((1-a)));
   double d=(R*c);

     return d;
}


int main(void){

}

void SysTick_Handler (void)
{
	  
   if (distance>9999){
		 
		 GPIO_PORTE_DATA_R=0x10;
		 GPIO_PORTB_DATA_R= numbersArr[1];
	 }
	else{
	
	}
}


