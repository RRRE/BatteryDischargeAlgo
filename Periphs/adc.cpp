

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "adc.h"


void A2D::InitAdc(void)
{
  ADMUX  = (0<<ADLAR);   // Right Justified Result of ADC
  ADCSRA = (1<<ADFR) |(1<<ADIF) |(1<<ADSC) ;
  //ADCSRA |= (1 << ADIE);                      /* enable interrupt  */
  //ADCSRA |= (1 << ADEN);       			    /* enable ADC module */

  A2D::SetReference(ADC_REFERENCE_AREF);		    // set reference voltage
  A2D::SetPrescaler(ADC_PRESCALE_DIV64);			// set prescaler value

  AdcOn();
}

unsigned long A2D::ValAdc(unsigned int Channel)
{
  ADMUX |= (Channel & 0x07);

  while (ADIF==0);
  _delay_ms(10);

  Adc_fVal  = (ADCL)|(ADCH << 8);
  Adc_cVal  = (Adc_fVal*ADC_resolution);
  
  //ADCSRA |= (1<<ADSC);

  return  Adc_cVal;
}

// configure A2D converter voltage reference
void A2D::SetReference(ADC_REFERENCE reference)
{
	ADMUX |= (reference<<6) & 0xC0;
}

// configure A2D converter clock division (prescaling)
void A2D::SetPrescaler(ADC_PRESCALE prescale)
{
	ADCSRA |= prescale & 0x07 ;
}

// turn off a2d converter
void A2D::AdcOff()
{
	ADCSR |= (0<<ADIE);				// disable ADC interrupts
	ADCSR |= (0<<ADEN);				// disable ADC (turn off ADC power)
}

void A2D::AdcOn()
{
	ADCSR |= (1<<ADIE);				// enable ADC interrupts
	ADCSR |= (1<<ADEN);				// enable ADC (turn on ADC power)
}

void ADC_vect(void)
{
  //ADC::Adc_Val = (ADCH << 8) | (ADCL);    // OutPut to the Temp variable

  //A2D::Timer_val = A2D::Timer_val++;
  //ADCSRA |= (1<<ADIE);
  ADCSRA |= (1<<ADSC);  //   Start Conversion
}
