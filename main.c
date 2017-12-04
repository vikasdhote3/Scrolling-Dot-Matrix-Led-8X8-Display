#include<reg51.h>
#include"delay.h"
#include"my_lut.h"
//#include"pro_fun.h"
#include"uart1.h"


void main()
{
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
		while(1) {
		 dt_scll(s);
		}
	}	
	uart_string("\n\rENTER THE STRING:");
	while((temp=uart_rx())!=13)
		{
			s[i++]=temp;
			uart_tx(temp);
		}
		s[i]='\0';
		
	while((j-48)==1){
	dt_flash(s);
	}
											
	while(j-48==2){
	 dt_scll(s);
	}
	
	while(j-48==3){
	 dt_str(s);
 }
} 