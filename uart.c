#include <xc.h>

#ifndef __UART_H
#define __UART_H

#ifndef _XTAL_FREQ
	#define _XTAL_FREQ   20000000  
#endif



#define BAUDRATE 9600  



void InitUART(void);
void SendByteSerially(char);
unsigned char ReceiveByteSerially(void);

#endif


#pragma config FOSC = HS, WDTE = OFF, PWRTE = OFF, BOREN = OFF, LVP = OFF, CPD = OFF, WRT = OFF, CP = OFF
		

void main(void)
{
	InitUART();							
    
    char ch[] = "hello world!";
    
    for(int i=0;ch[i]!='\0';i++)
    {
        SendByteSerially(ch[i]); // Transmit predefined string
    }

	GIE  = 1;  							
    PEIE = 1;  							

	while(1)
	{
		
		SendByteSerially(ReceiveByteSerially()); 
    } 
}

void InitUART(void)
{
	TRISC6 = 1;   					
	TRISC7 = 1;   					
	
	SPBRG = ((_XTAL_FREQ/16)/BAUDRATE) - 1;
	BRGH  = 1;                   	
	SYNC  = 0;						
	SPEN  = 1;						
	CREN  = 1;						
	SREN  = 0;						
	TXIE  = 0;						
	RCIE  = 1;						
	TX9   = 0;						
	RX9   = 0;						
	TXEN  = 0;						
	TXEN  = 1;						
}


void SendByteSerially(char Byte)  
{
	while(!TXIF);  
	TXREG = Byte;
}

unsigned char ReceiveByteSerially(void)   
{
	if(OERR) 
	{
		CREN = 0;
		CREN = 1;
	}
	
	while(!RCIF);  
	
	return RCREG;
}

