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

void systick_init(){
		NVIC_ST_CTRL_R = 0;									//disable timer
		NVIC_ST_RELOAD_R = (16000*5 - 1);		//time, every (16000-1) = 1 millisec
		NVIC_ST_CURRENT_R = 0;							//clear current r, clear count flag
		NVIC_ST_CTRL_R |= 0x07;							//enable timer and set clck src and start inturrept
}
void portF_led_init()
{
		SYSCTL_RCGC2_R |= 0x00000020;;
		GPIO_PORTF_AFSEL_R =0x00;
		GPIO_PORTF_PCTL_R = 0;
    GPIO_PORTF_DIR_R = 0x0E;

		GPIO_PORTF_AMSEL_R = 0;
    GPIO_PORTF_DEN_R = 0x0F;
		GPIO_PORTF_LOCK_R = 0x4C4F434B;
		GPIO_PORTF_CR_R = 0x0F;
    GPIO_PORTF_PUR_R = 0x01;

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
void portB_segments_init(void){
	if(SYSCTL_PRGPIO_R & 0xFD)!= SYSCTL_PRGPIO_R){} // checks if already the port is enabled and does nothing
		else{
			SYSCTL_RCGCGPIO_R |= 0x02;     //Enables port B
			while((SYSCTL_PRGPIO_R & 0xFD)==SYSCTL_PRGPIO_R){}  //waits until port is into clock
			GPIO_PORTB_LOCK_R = 0x4C4F434B;
			GPIO_PORTB_CR_R|= 0x7F; // unlock first seven pins
			GPIO_PORTB_AMSEL_R &= ~0x7F;
			GPIO_PORTB_AFSEL_R&=~0x7F;
			GPIO_PORTB_DEN_R|=0x7F;
			GPIO_PORTB_PCTL_R = 0x00000000; // used as GPIO so PCTL and AMSEL are reset
			GPIO_PORTB_DIR_R|=0x7F;
			GPIO_PORTB_PUR_R &=~0x7F;

		}




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
