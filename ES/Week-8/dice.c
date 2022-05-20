#include<LPC17xx.h>
#include<stdio.h>
#include<stdlib.h>

#define DATA 0xF<<23
#define RS 1<<27 // RS is register select signal -> 0 = command, 1 = data
#define EN 1<<28 // Enable signal

// Bit:28=EN, Bit:27=RS, Bit[26:23]=Data

int i=0,j=0;
char msg2[1];

void initializeLCD(void);
void writeData(int data, int rs);
void pulsate(void);
void initializeTimer(void);
void delay(int ms);

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

void initializeLCD() {
  LPC_GPIO0->FIODIR|=(DATA|RS|EN);          // setting the p0.28 to p0.23 as output
  writeData(0x33,0);                         // set the lcd in 8-bit mode
  writeData(0x32,0);                       
  writeData(0x28,0);
  writeData(0x0C,0);                 // display on , cursor off
  writeData(0x06,0);									// increment cursor, shift right once
  writeData(0x01,0);								// clear the display
}

void writeData(int data, int rs) {
  LPC_GPIO0->FIOCLR|=(DATA|RS|EN);
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

int main() {
	while(1){
		int num = (rand() % 7);
		msg2[0] = num==0?num++:num +'0';
		initializeLCD();
		writeData(0x80,0);				// Force cursor to the beginning of the first line
		for(i=0; msg2[i]; i++){
			writeData(0x01,0);		
			writeData(msg2[i],1);
		}
	}
}
