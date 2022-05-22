#include<LPC17xx.h>

#define RS 1<<27
#define EN 1<<28
#define DATA 0xF<<23

unsigned char msg1[13]="KEY PRESSED=";
unsigned char row, flag, key;
unsigned long int i, j, var, temp1, temp2;
unsigned char scan_code[16]={0x11, 0x21, 0x41, 0x81, 0x12, 0x22, 0x42, 0x82, 0x14, 0x24, 0x44, 0x84, 0x18, 0x28, 0x48, 0x88};
unsigned char ascii_code[16]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void initializeLCD(void);
void writeData(int data, int rs);
void pulsate(void);
void initializeTimer(void);
void delay(int ms);
void displayLCD(unsigned char* arr);
void scan(void);

void initializeLCD(void) {
	LPC_GPIO0->FIODIR|=(DATA|RS|EN);
    writeData(0x33,0);
    writeData(0x32,0);
    writeData(0x28,0);
    writeData(0x0C,0);
    writeData(0x06,0);
    writeData(0x01,0);
}

void writeData(int data, int rs) {
    LPC_GPIO0->FIOCLR |= (DATA|RS|EN);
    if(rs==1)
        LPC_GPIO0->FIOPIN|=RS;
    LPC_GPIO0->FIOPIN|=(data&0xF0)<<19;
    pulsate();
        LPC_GPIO0->FIOCLR|=DATA;
    LPC_GPIO0->FIOPIN|=(data&0x0F)<<23;
    pulsate();
}

void pulsate() {
	LPC_GPIO0->FIOPIN|=EN;
	delay(3000);
	LPC_GPIO0->FIOCLR|=EN;
    delay(3000);
}

void initializeTimer() {
    LPC_TIM0->CTCR=0x0;
    LPC_TIM0->PR=2;
    LPC_TIM0->MR0=999;
    LPC_TIM0->MCR=0x02;
    LPC_TIM0->EMR=0x02<<4;
    LPC_TIM0->TCR=0x02;
    LPC_TIM0->TCR=0x01;
}

void delay(int ms) {
	initializeTimer();
    for(j=0; j<ms; j++)
		while(!(LPC_TIM0->EMR & 1));
}

void displayLCD(unsigned char* arr) {
    i = 0;
	while(arr[i]!='\0') {
        writeData(arr[i];, 1);
        i++;
	}
}

void scan(void) {
	temp2=LPC_GPIO1->FIOPIN&0x07800000;
	if(temp2!=0X00000000) {
		flag=1;
		temp2>>=19;
		temp1>>=10;
		key=temp2|temp1;
	}
}

int main() {
	LPC_GPIO2->FIODIR|=0X00003C00;
	LPC_GPIO1->FIODIR&=0XF87FFFFF;
	
	initializeLCD();
	
	writeData(0X80, 0);
	displayLCD(&msg1[0]);
    writeData(0xc0, 0);
	
	while(1) {
		while(1) {
			for(row=1; row<5; row++) {
				if(row==1)
					var=0X000000400;
				else if(row==2)
					var=0X000000800;
				else if(row==3)
					var=0X00001000;
				else if(row==4)
					var=0X00002000;
				
				temp1=var;
				LPC_GPIO2->FIOCLR=0X00003C00;
				LPC_GPIO2->FIOSET=var;
				flag=0;
				scan();
				if(flag==1)
					break;
			}
			if(flag==1) break;
	    }
		
        for(i=0; i<16; i++) {
            if(key==scan_code[i]) {
                key=ascii_code[i];
                break;
            }
        }
        writeData(0XC0, 0);
        displayLCD(&key);
	}
}
