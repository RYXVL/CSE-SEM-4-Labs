#include<LPC17xx.h>
unsigned char tohex[10]={0X06, 0X5B, 0X4F, 0X66};
unsigned int i=0,j=0,k=3;
int main() {
	LPC_GPIO0->FIODIR|=0XFF0;
	LPC_GPIO1->FIODIR|=0XF<<23;
    while (1) {
	    for(i=0; i<4; i++) {
            if(k<0) k=3;
            LPC_GPIO1->FIOPIN=k<<23;
            LPC_GPIO0->FIOPIN=tohex[i]<<4;
            for(j=0; j<30000; j++);
		    k--;
	    }
    }
}
