
#include"main.h"

void dt_flash(char *sr)
{
	char i;
	for(i=0;i<16;i++)
	dt_str(sr);
	delay(500);
}

void uart_init()
{
 SCON=0x50; //REN =1//UART MODE SELEXT
 TMOD =0x20;//TIMER 1,MODE2
 TH1=TL1=253;//SET BARDRATE 9600BPS
 TR1=1;//START TIMER
}

void uart_tx(unsigned char ch)
{
 SBUF =ch;
 while(TI==0); //waiting for charactor transfer//
 TI=0; 
}

unsigned char uart_rx()
{
 while(RI==0);
 RI=0;//imp
 return SBUF;
}

void uart_string(char *s)
{
	while(*s)
	{
		uart_tx(*s++);
	}
	
}
