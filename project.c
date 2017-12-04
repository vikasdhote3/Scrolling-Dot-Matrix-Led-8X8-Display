///project.c//////
///////////////////
#include<reg51.h>
#include"delay.h"
#include"my_lut.h"
//#include"pro_fun.h"
#include"uart1.h"


void main()
{
	//char s[]="VECTOR";
	unsigned char s[40],i=0,j=0,temp;
	uart_init();
	uart_string("\n\r1.FLASH:\n\r2.SCROLL\n\r3.SIMPLE\n\r4.GSM\n\r");
	j=uart_rx();
	uart_tx(j);
	if(j-48==4)
	{
		while((uart_rx())!='#');
		while((temp=uart_rx())!='#')
		{
		s[i++]=temp;
		uart_tx(temp);
		}
		s[i]='\0';
		while(1)
		 dt_scll(s);
	}	
	uart_string("\n\rENTER THE STRING:");
	while((temp=uart_rx())!=13)
		{
		s[i++]=temp;
		uart_tx(temp);
		}
		s[i]='\0';
		
	while((j-48)==1)
	dt_flash(s);
											
 while(j-48==2)
	 dt_scll(s);
 while(j-48==3)
	 dt_str(s);
} 
//////////////////////////////////////////

//lut.h/////////
sbit _data0=P2^0;
sbit _clk0=P2^1;
sbit _data1=P2^2;
sbit _clk1=P2^3;
sbit _data2=P2^4;
sbit _clk2=P2^5;
sbit _data3=P2^6;
sbit _clk3=P2^7;
sfr rows=0X80;
void m_find(char *);
char chr[30];
code unsigned char lut[27][8]=
	{		
		0xff,0xc3,0x99,0x81,0x81,0x99,0x99,0xff,//A//
		0xff,0x83,0x99,0x81,0x81,0x99,0x83,0xff,//B//
		0xff,0x81,0x83,0x9f,0x9f,0x83,0x81,0xff,//C//
		0xff,0x83,0x99,0x99,0x99,0x99,0x83,0xff,//D//
		0xff,0x81,0x9f,0x83,0x83,0x9f,0x81,0xff,//E//
		0xff,0x81,0x81,0x9f,0x83,0x9f,0x9f,0xff,//F//
		0xff,0xc1,0x81,0x9f,0x91,0x9d,0xc1,0xff,//G//
		0xff,0x99,0x99,0x81,0x81,0x99,0x99,0xff,//H//
		0xff,0x81,0x81,0xE7,0XE7,0X81,0X81,0XFF,//I//
		0XFF,0XC3,0XE7,0XE7,0XE7,0XA7,0X87,0X87,//J//
		0xff,0xc9,0xcb,0xc7,0xc7,0xcb,0xc9,0xff,//K//
		0xff,0xcf,0xcf,0xcf,0xcf,0xc1,0xc1,0xff,//L//
		0xff,0x9c,0x88,0x94,0x9c,0x9c,0x9c,0xff,//M//
		0xff,0x9c,0x8c,0x94,0x98,0x98,0x9c,0xff,//N//
		0xff,0xc1,0xC9,0xC9,0xC9,0xC9,0xC1,0xFF,//O//
		0xff,0x83,0x9d,0x81,0x9f,0x9f,0x9f,0xff,//P//
		0xff,0x81,0xbd,0xad,0xb5,0xb9,0x81,0xfe,//Q//
		0xff,0x83,0xbb,0x83,0xaf,0xb3,0xdd,0xff,//R//
		0xff,0x81,0xbf,0xbf,0x81,0xfd,0x81,0xff,//S//
		0xff,0x81,0x81,0xd7,0xd7,0xd7,0xd7,0xff,//T//
		0xff,0xff,0x99,0x99,0x99,0x81,0x81,0xff,//U//
		0xff,0x9c,0x99,0xc9,0xc3,0xe3,0xf7,0xff,//V//
		0X7E,0X7E,0X7E,0X7E,0X66,0X5A,0X3C,0X7E,//W//
		0X7F,0XBD,0XDB,0XE7,0XE7,0XDB,0XBD,0X7E,//X//
		0X7E,0XBD,0XDB,0XE7,0XEF,0XDF,0XBF,0X7F,//Y//
		0X00,0Xfd,0XFB,0XF7,0XEF,0XDF,0XBF,0X00,//Z//
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff, //off//
	};
	///////////////////////////////
	void dt_str(char *sr)
	{		
		unsigned char k=0,i=0,d[4],j=0,x=0,z;
		m_find(sr);
		{
			k=z=i=j=x=0;
		while(sr[x])
		{		
	
		for(i=0;i<8;i++)
		{
			 
			d[0]=lut[chr[k]][i];
			d[1]=lut[chr[k+1]][i];
			d[2]=lut[chr[k+2]][i];
			d[3]=lut[chr[k+3]][i];
			rows=0X00;    
			for(j=0;j<8;j++)
			{
				
			_data0=(d[0]&(1<<j))?1:0;   
			_clk0=0;
			_clk0=1;
				
			_data1=(d[1]&(1<<j))?1:0;   
			_clk1=0;
			_clk1=1;			
				
			_data2=(d[2]&(1<<j))?1:0;   
			_clk2=0;
			_clk2=1;			
				
			_data3=(d[3]&(1<<j))?1:0;   
			_clk3=0;
			_clk3=1;
			}
   rows=(1<<i); 
   delay(2);  
  }		
	x++;
}
}
}
////////////////////////////////////
	void m_find(char *sr)
		 {
			 char x=0,i,t=0;
			while(sr[x])
			{
					for(i=0;i<27;i++)
					{
					 if(sr[x]=='A'+i)
					 chr[t++]=i;
					
					}
					if(sr[x]==' ') chr[t++]=26;
					x++;
			}	
		}
/////////////////////////////	
	void m_scl(char *sr)
		 {
			 char x=0,i,t=0;
			 for(i=0;i<4;i++)
			 chr[t++]=26;
			while(sr[x])
			{
					for(i=0;i<27;i++)
					{
					 if(sr[x]=='A'+i)
					 chr[t++]=i;
					
					}
					if(sr[x]==' ') chr[t++]=26;
					x++;
			}
			 for(i=0;i<4;i++)
			 chr[t++]=26;	
				chr[t]=0;
		}		
//////////////////////////////////////		
		void dt_scll(char *sr)
	{		
		unsigned char k=0,i=0,d[4],j=0,x=0,z;
		m_scl(sr);

			z=i=j=x=k=0;
		while(sr[x])
		{		
	for(z=0;z<30;z++)
			{
		for(i=0;i<8;i++)
		{
			 
			d[0]=lut[chr[k]][i];
			d[1]=lut[chr[k+1]][i];
			d[2]=lut[chr[k+2]][i];
			d[3]=lut[chr[k+3]][i];
			rows=0X00;    
			for(j=0;j<8;j++)
			{
				
			_data0=(d[0]&(1<<j))?1:0;   
			_clk0=0;
			_clk0=1;
				
			_data1=(d[1]&(1<<j))?1:0;   
			_clk1=0;
			_clk1=1;			
				
			_data2=(d[2]&(1<<j))?1:0;   
			_clk2=0;
			_clk2=1;			
				
			_data3=(d[3]&(1<<j))?1:0;   
			_clk3=0;
			_clk3=1;
			}
   rows=(1<<i); 
   delay(1);  
  }		
}
k++;
x++;
}
}
/////////////////////////////////////
void dt_flash(char *sr)
{
	char i;
for(i=0;i<16;i++)
	dt_str(sr);
	delay(500);}
	/////////////////////////////
//////////////////////////////
//uart.h//////////
//uart.h//
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
////////////////////////////////////////////
//delay.h////
int delay(unsigned int ms)
{
	unsigned char i;
	for(;ms>0;ms--)
	{
 for(i=250;i>0;i--);
 for(i=247;i>0;i--);
	}
	return 0;
}