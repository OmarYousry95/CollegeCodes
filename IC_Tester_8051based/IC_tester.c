#include <reg52.h>
#include "header.h"
#include "IC_tester.h"

void SetupSerial();
void SendChar(unsigned char ch);

void main(void)
{
	unsigned int x;
	SetupSerial();
	/*Display IC TESTER on serial terminal; sent char by char through UART*/
	SendChar('I'); SendChar('C'); SendChar(' '); SendChar('T'); SendChar('E'); SendChar('S'); SendChar('T'); SendChar('E');
	SendChar('R'); SendChar('\n');
	Test_switch = 1;
	/*Initial Label*/
	initial:
	P1 = 0xFF; P2 = 0xFF;
	goto begin;
	/*NOT IC Label*/
	NOT:
	P1 = 0xEA; P2 = 0xEA;
	goto backnot;
	/*NAND IC Label*/
	NAND:
	P1 = 0xDB; P2 = 0xF6;
	goto backnand;
	/*OR IC Label*/
	OR:
	P1 = 0xDB; P2 = 0xF6;
	goto backor;
	/*AND IC Label*/
	AND:
	P1 = 0xDB; P2 = 0xF6;
	goto backand;
	/*XOR IC Label*/
	XOR:
	P1 = 0xDB; P2 = 0xF6;
	goto backxor;
	/*AND with 3-inputs IC Label*/
	AND3IN:
	P1 = 0xCF; P2 = 0xEE;
	goto backand3in;
	/*Begin Label*/
	begin:
	while(1)
	{
		if(Test_switch == 0)
		{
			t_delay(20000);
			goto NOT;
			/*back not label*/
			backnot:
			P1 = 0xFF; P2 = 0xFF;
			x = test_7404();
			if(x == 1)
			{ SendChar('7'); SendChar('4'); SendChar('0'); SendChar('4'); SendChar('\n'); goto initial; }
		
			t_delay(20000);
			goto NAND;
			/*backnand label*/
			backnand:
			P1 = 0xFF; P2 = 0xFF;
			x = test_7400();
			if(x == 1)
			{ SendChar('7'); SendChar('4'); SendChar('0'); SendChar('0'); SendChar('\n'); goto initial; }
		
			t_delay(20000);
			goto OR;
			/*backor label*/
			backor:
			P1 = 0xFF; P2 = 0xFF;
			x = test_7432();
			if(x == 1)
			{ SendChar('7'); SendChar('4'); SendChar('3'); SendChar('2'); SendChar('\n'); goto initial; }
		
			t_delay(20000);
			goto AND;
			/*backand label*/
			backand:
			P1 = 0xFF; P2 = 0xFF;
			x = test_7408();
			if(x == 1)
			{ SendChar('7'); SendChar('4'); SendChar('0'); SendChar('8'); SendChar('\n'); goto initial; }
		
			t_delay(20000);
			goto XOR;
			/*backxor label*/
			backxor:
			P1 = 0xFF; P2 = 0xFF;
			x = test_7486();
			if(x == 1)
			{ SendChar('7'); SendChar('4'); SendChar('8'); SendChar('6'); SendChar('\n'); goto initial; }
		
			t_delay(20000);
			goto AND3IN;
			/*backand3in label*/
			backand3in:
			P1 = 0xFF; P2 = 0xFF;
			x = test_7411();
			if(x == 1)
			{ SendChar('7'); SendChar('4'); SendChar('1'); SendChar('1'); SendChar('\n'); goto initial; }
			
			/*Non-defined/Courrupted IC*/
			if(x == 0)
			{ SendChar('U'); SendChar('n'); SendChar('d'); SendChar('e'); SendChar('f'); SendChar('i'); SendChar('n');
			  SendChar('e'); SendChar('d'); SendChar('\n'); goto initial; }
		}
	}
}

/*Function to setup UART baud-rate*/
void SetupSerial()
{
    SCON  = 0x50;		        		
    TMOD |= 0x20;               
  	TH1   = 250;                
    TR1   = 1;                             
}

/*Function to send a char using UART*/
void SendChar(unsigned char ch)
{
    /*Insert the char needed in SBUF buffer*/
	SBUF = ch;
	/*Busy-wait till char is successfully sent*/
	while(TI==0);
	/*Clear TI flag for further characters to be sent*/
	TI = 0;
}

/*Function to test 7404: Hex NOT gate IC*/
unsigned int test_7404()
{
	//P10 --> P11
	P10=0;
	if(P11==0)
	{ return 0; }
	P10=1;
	if(P11==1)
	{ return 0; }
	
	//P12 --> P13
	P12=0;
	if(P13==0)
	{ return 0; }
	P12=1;
	if(P13==1)
	{ return 0; }
	
	//P14 --> P15
	P14=0;
	if(P15==0)
	{ return 0; }
	P14=1;
	if(P15==1)
	{ return 0; }
	
	//P21 --> P20
	P21=0;
	if(P20==0)
	{ return 0; }
	P21=1;
	if(P20==1)
	{ return 0; }

	//P23 --> P22
	P23=0;
	if(P22==0)
	{ return 0; }
	P23=1;
	if(P22==1)
	{ return 0; }

	//P25 --> P24
	P25=0;
	if(P24==0)
	{ return 0; }
	P25=1;
	if(P24==1)
	{ return 0; }

	return 1;	
}

/*Function to test 7400: Quad 2-input NAND gate IC*/
unsigned int test_7400()
{
	//(P10,P11) --> P12
	P10=0; P11=0;
	if(P12==0)
	{ return 0; }
	P10=0; P11=1;
	if(P12==0)
	{ return 0; }
	P10=1; P11=0;
	if(P12==0)
	{ return 0; }
	P10=1; P11=1;
	if(P12==1)
	{ return 0; }
	
	//(P13,P14) --> P15
	P13=0; P14=0;
	if(P15==0)
	{ return 0; }
	P13=0; P14=1;
	if(P15==0)
	{ return 0; }
	P13=1; P14=0;
	if(P15==0)
	{ return 0; }
	P13=1; P14=1;
	if(P15==1)
	{ return 0; }
	
	//(P22,P21) --> P20
	P22=0; P21=0;
	if(P20==0)
	{ return 0; }
	P22=0; P21=1;
	if(P20==0)
	{ return 0; }
	P22=1; P21=0;
	if(P20==0)
	{ return 0; }
	P22=1; P21=1;
	if(P20==1)
	{ return 0; }
	
	//(P25,P24) --> P23
	P25=0; P24=0;
	if(P23==0)
	{ return 0; }
	P25=0; P24=1;
	if(P23==0)
	{ return 0; }
	P25=1; P24=0;
	if(P23==0)
	{ return 0; }
	P25=1; P24=1;
	if(P23==1)
	{ return 0; }
	
	return 1;
}

/*Function to test 7432: Quad 2-input OR gate IC*/
unsigned int test_7432()
{
	//(P10,P11) --> P12
	P10=0; P11=0;
	if(P12==1)
	{ return 0; }
	P10=0; P11=1;
	if(P12==0)
	{ return 0; }
	P10=1; P11=0;
	if(P12==0)
	{ return 0; }
	P10=1; P11=1;
	if(P12==0)
	{ return 0; }
	
	//(P13,P14) --> P15
	P13=0; P14=0;
	if(P15==1)
	{ return 0; }
	P13=0; P14=1;
	if(P15==0)
	{ return 0; }
	P13=1; P14=0;
	if(P15==0)
	{ return 0; }
	P13=1; P14=1;
	if(P15==0)
	{ return 0; }
	
	//(P22,P21) --> P20
	P22=0; P21=0;
	if(P20==1)
	{ return 0; }
	P22=0; P21=1;
	if(P20==0)
	{ return 0; }
	P22=1; P21=0;
	if(P20==0)
	{ return 0; }
	P22=1; P21=1;
	if(P20==0)
	{ return 0; }
	
	//(P25,P24) --> P23
	P25=0; P24=0;
	if(P23==1)
	{ return 0; }
	P25=0; P24=1;
	if(P23==0)
	{ return 0; }
	P25=1; P24=0;
	if(P23==0)
	{ return 0; }
	P25=1; P24=1;
	if(P23==0)
	{ return 0; }
	
	return 1;
}

/*Function to test 7408: Quad 2-input AND gate IC*/
unsigned int test_7408()
{
	//(P10,P11) --> P12
	P10=0; P11=0;
	if(P12==1)
	{ return 0; }
	P10=0; P11=1;
	if(P12==1)
	{ return 0; }
	P10=1; P11=0;
	if(P12==1)
	{ return 0; }
	P10=1; P11=1;
	if(P12==0)
	{ return 0; }
	
	//(P13,P14) --> P15
	P13=0; P14=0;
	if(P15==1)
	{ return 0; }
	P13=0; P14=1;
	if(P15==1)
	{ return 0; }
	P13=1; P14=0;
	if(P15==1)
	{ return 0; }
	P13=1; P14=1;
	if(P15==0)
	{ return 0; }
	
	//(P22,P21) --> P20
	P22=0; P21=0;
	if(P20==1)
	{ return 0; }
	P22=0; P21=1;
	if(P20==1)
	{ return 0; }
	P22=1; P21=0;
	if(P20==1)
	{ return 0; }
	P22=1; P21=1;
	if(P20==0)
	{ return 0; }
	
	//(P25,P24) --> P23
	P25=0; P24=0;
	if(P23==1)
	{ return 0; }
	P25=0; P24=1;
	if(P23==1)
	{ return 0; }
	P25=1; P24=0;
	if(P23==1)
	{ return 0; }
	P25=1; P24=1;
	if(P23==0)
	{ return 0; }
	
	return 1;
}

/*Function to test 7486: Quad 2-input XOR gate IC*/
unsigned int test_7486()
{
	//(P10,P11) --> P12
	P10=0; P11=0;
	if(P12==1)
	{ return 0; }
	P10=0; P11=1;
	if(P12==0)
	{ return 0; }
	P10=1; P11=0;
	if(P12==0)
	{ return 0; }
	P10=1; P11=1;
	if(P12==1)
	{ return 0; }
	
	//(P13,P14) --> P15
	P13=0; P14=0;
	if(P15==1)
	{ return 0; }
	P13=0; P14=1;
	if(P15==0)
	{ return 0; }
	P13=1; P14=0;
	if(P15==0)
	{ return 0; }
	P13=1; P14=1;
	if(P15==1)
	{ return 0; }
	
	//(P22,P21) --> P20
	P22=0; P21=0;
	if(P20==1)
	{ return 0; }
	P22=0; P21=1;
	if(P20==0)
	{ return 0; }
	P22=1; P21=0;
	if(P20==0)
	{ return 0; }
	P22=1; P21=1;
	if(P20==1)
	{ return 0; }
	
	//(P25,P24) --> P23
	P25=0; P24=0;
	if(P23==1)
	{ return 0; }
	P25=0; P24=1;
	if(P23==0)
	{ return 0; }
	P25=1; P24=0;
	if(P23==0)
	{ return 0; }
	P25=1; P24=1;
	if(P23==1)
	{ return 0; }
	
	return 1;
}

/*Function to test 7411: Triple 3-input AND gate IC*/
unsigned int test_7411()
{
	//(P10,P11,P25) --> P24
	P10=0; P11=0; P25=0;
	if(P24==1)
	{ return 0; }
	P10=0; P11=0; P25=1;
	if(P24==1)
	{ return 0; }
	P10=0; P11=1; P25=0;
	if(P24==1)
	{ return 0; }
	P10=0; P11=1; P25=1;
	if(P24==1)
	{ return 0; }
	P10=1; P11=0; P25=0;
	if(P24==1)
	{ return 0; }
	P10=1; P11=0; P25=1;
	if(P24==1)
	{ return 0; }
	P10=1; P11=1; P25=0;
	if(P24==1)
	{ return 0; }
	P10=1; P11=1; P25=1;
	if(P24==0)
	{ return 0; }
	
	//(P12,P13,P14) --> P15
	P12=0; P13=0; P14=0;
	if(P15==1)
	{ return 0; }
	P12=0; P13=0; P14=1;
	if(P15==1)
	{ return 0; }
	P12=0; P13=1; P14=0;
	if(P15==1)
	{ return 0; }
	P12=0; P13=1; P14=1;
	if(P15==1)
	{ return 0; }
	P12=1; P13=0; P14=0;
	if(P15==1)
	{ return 0; }
	P12=1; P13=0; P14=1;
	if(P15==1)
	{ return 0; }
	P12=1; P13=1; P14=0;
	if(P15==1)
	{ return 0; }
	P12=1; P13=1; P14=1;
	if(P15==0)
	{ return 0; }
	
	//(P23,P22,P21) --> P20
	P23=0; P22=0; P21=0;
	if(P20==1)
	{ return 0; }
	P23=0; P22=0; P21=1;
	if(P20==1)
	{ return 0; }
	P23=0; P22=1; P21=0;
	if(P20==1)
	{ return 0; }
	P23=0; P22=1; P21=1;
	if(P20==1)
	{ return 0; }
	P23=1; P22=0; P21=0;
	if(P20==1)
	{ return 0; }
	P23=1; P22=0; P21=1;
	if(P20==1)
	{ return 0; }
	P23=1; P22=1; P21=0;
	if(P20==1)
	{ return 0; }
	P23=1; P22=1; P21=1;
	if(P20==0)
	{ return 0; }
	
	return 1;
}	