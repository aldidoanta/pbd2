#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"
#include "Seven_Segment.h"
#define SEG_N0   0x82 
#define SEG_N1   0xEE 
#define SEG_N2   0x07 
#define SEG_N3   0x46 
#define SEG_N4   0x6A  
#define SEG_N5   0x52 
#define SEG_N6   0x12 
#define SEG_N7   0xE6 
#define SEG_N8   0x02 
#define SEG_N9   0x62  
#define SEG_NA   0x06
#define SEG_NB   0x1A
#define SEG_NC   0x1F
#define SEG_ND   0x0E
#define SEG_NE   0x03
#define SEG_NF   0x33
#define SEG_NULL 0xDF


unsigned char SEG_BUF[17]={SEG_N0, SEG_N1, SEG_N2, SEG_N3, SEG_N4, SEG_N5, SEG_N6, SEG_N7, SEG_N8, SEG_N9, SEG_NA, SEG_NB, SEG_NC, SEG_ND, SEG_NE, SEG_NF,SEG_NULL}; 

void show_seven_segment(unsigned char no, unsigned char number)
{
    unsigned char temp,i;
	temp=SEG_BUF[number];
	
	for(i=0;i<8;i++)
	    {
		if((temp&0x01)==0x01)		   		   
		   DrvGPIO_SetBit(E_GPE,i);
		   else
		   DrvGPIO_ClrBit(E_GPE,i);		  
		   temp=temp>>1;
		}
		DrvGPIO_SetBit(E_GPC,4+no);	

}

void close_seven_segment(void)
{
	DrvGPIO_ClrBit(E_GPC,4);	
    DrvGPIO_ClrBit(E_GPC,5);	
	DrvGPIO_ClrBit(E_GPC,6);	
	DrvGPIO_ClrBit(E_GPC,7);

}
