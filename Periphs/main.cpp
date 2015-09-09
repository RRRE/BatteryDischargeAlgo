

#include <avr/io.h>
#include <avr/interrupt.h>

#include "adc.h"


A2D pAdc;

unsigned int Timer_val = 101;
volatile unsigned long Bat_1_Val, Bat_2_Val, Bat_3_Val;

//OUT Switch1 ('B', 1, false);
//OUT Switch2 ('B', 2, false);
//OUT Switch3 ('B', 3, false);

int main(void)
{

	DDRB  = 0xFF;
	PORTB = 0x00;
	sei();

	pAdc.InitAdc();
	//pAdc.SetReference(ADC_REFERENCE_AREF);		    // set default reference
	//pAdc.SetPrescaler(ADC_PRESCALE_DIV64);			// set default prescaler


	Timer_val = 101;

	Bat_1_Val = pAdc.ValAdc(0);
	Bat_2_Val = pAdc.ValAdc(1);
	Bat_3_Val = pAdc.ValAdc(2);

	while(1)
	{
		if(Timer_val > 100)
		{
			Bat_1_Val = pAdc.ValAdc(0);
			Bat_2_Val = pAdc.ValAdc(1);
			Bat_3_Val = pAdc.ValAdc(2);

			Timer_val = 0x00;
		}

		else
		{
			if((Bat_1_Val > 100)|(Bat_2_Val > 100)|(Bat_3_Val > 100))
			{
				if((Bat_1_Val > Bat_2_Val) && (Bat_1_Val > Bat_3_Val) && (Bat_1_Val > 10))
				{
					PORTB |=  (1<<PINB1);     // Switch 1 on
					PORTB &= ~(1<<PINB2);     // Switch 2 off
					PORTB &= ~(1<<PINB3);     // Switch 3 off
				}
				else if((Bat_2_Val > Bat_1_Val) && (Bat_2_Val > Bat_1_Val) && (Bat_2_Val > 10))
				{
					PORTB |=  (1<<PINB2);     // Switch 2 on
					PORTB &= ~(1<<PINB1);     // Switch 1 off
					PORTB &= ~(1<<PINB3);     // Switch 3 off
				}
				else if((Bat_3_Val > Bat_1_Val) && (Bat_3_Val > Bat_2_Val) && (Bat_3_Val > 10))
				{
					PORTB |=  (1<<PINB3);     // Switch 3
					PORTB &= ~(1<<PINB2);     // Switch 2 off
					PORTB &= ~(1<<PINB1);     // Switch 1 off
				}
				else if((Bat_1_Val == Bat_2_Val) && (Bat_1_Val== Bat_3_Val))
				{
					PORTB |=  (1<<PINB1);     // Switch 1 on
					PORTB |=  (1<<PINB2);     // Switch 2 on
					PORTB |=  (1<<PINB3);     // Switch 3 on
				}
			}
			else
			{
				PORTB &= ~(1<<PINB1);     // Switch 1 off
				PORTB &= ~(1<<PINB2);     // Switch 2 off
				PORTB &= ~(1<<PINB3);     // Switch 3 off
			}

			Timer_val++;

			//PORTB &= ~(1<<PINB1);        // Clr Port Bit
			//PORTB |=  (1<<PINB1);        // Set Port Bit
			//PORTB |= ~PINB0 & 0xFF;  // Masking Pin of Switch 1
		_delay_ms(10);
		}
	}
}
