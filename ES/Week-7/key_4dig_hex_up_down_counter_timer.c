#include<LPC17xx.h>
unsigned char tohex[16]={0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X6F, 0X77, 0X7C, 0X39, 0X5E, 0X79, 0X71};
long int arr[4]={0,0,0,0};
unsigned int i=0,j=0;
int main() {
	LPC_GPIO0->FIODIR|=0XFF0;
	LPC_GPIO1->FIODIR|=0XF<<23;
	LPC_GPIO2->FIODIR|=0<<0;
	if(LPC_GPIO2->FIOPIN & 1<<0) {
        for(arr[3]=0; arr[3]<16; arr[3]++)
            for(arr[2]=0; arr[2]<16; arr[2]++)
                for(arr[1]=0; arr[1]<16; arr[1]++)
                    for(arr[0]=0; arr[0]<16; arr[0]++) {
                        for(i=0; i<4; i++) {
                            LPC_GPIO1->FIOPIN=i<<23;
                            LPC_GPIO0->FIOPIN=tohex[arr[i]]<<4;
                            for(j=0; j<1000; j++);
                        }
                        for(j=0; j<1000; j++);
                        LPC_GPIO0->FIOCLR|=0X00000FF0;
                    }
	}
	else {
        for(arr[3]=15; arr[3]>=0; arr[3]--)
            for(arr[2]=15; arr[2]>=0; arr[2]--)
                for(arr[1]=15; arr[1]>=0; arr[1]--)
                    for(arr[0]=15; arr[0]>=0; arr[0]--) {
                        for(i=0; i<4; i++) {
                            LPC_GPIO1->FIOPIN=i<<23;
                            LPC_GPIO0->FIOPIN=tohex[arr[i]]<<4;
                            for(j=0; j<1000; j++);
                        }
                        for(j=0; j<1000; j++);
                        LPC_GPIO0->FIOCLR|=0X00000FF0;
                    }
	}
}
