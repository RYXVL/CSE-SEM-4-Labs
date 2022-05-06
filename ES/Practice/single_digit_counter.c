//Single digit counter 
#include<LPC17xx.h>

unsigned char tohex[10]={0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X6F};

unsigned int i=0,j=0;

int main()
{
	LPC_GPIO0->FIODIR|=0XFF0;
	LPC_GPIO1->FIODIR|=0XF<<23;
	LPC_GPIO1->FIOPIN=0<<23;
    while (1)
      {
	 for(i=0; i<10; i++)
		{
						
		LPC_GPIO0->FIOPIN=tohex[i]<<4;
		for(j=0; j<100000; j++);
		}
					 
	
      }
}
