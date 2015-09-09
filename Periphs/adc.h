
#ifndef _ADC_H_
#define _ADC_H_

//#include <avr/interrupt.h>
#include "main.h"
//#include "Output.h"

extern "C" void ADC_vect(void) __attribute__ ((signal));



#define ADC_resolution   0.48828125       // Vref/1024 (5.0/1024)

//#define MAX_ADC_VAL      100             // MaxVal at +12v is 6300
//#define MIN_ADC_VAL      10              // MinVal at +12v



//#define Channel_1      0
//#define Channel_2      1
//#define Channel_3      2
//#define Channel_4      3

/***** A2D clock prescaler select selects how  *******
 ***** much the CPU clock frequency is divided *******
 ***** to create the A2D clock frequency lower *******
 ***** division ratios make conversion go faster *****
 ***** higher division ratios make conversions more **
 ***** accurate                                *******
*/
typedef enum
{
	ADC_PRESCALE_DIV2 	= 0x00,	 // <0x01,0x00> CPU clk/2
	ADC_PRESCALE_DIV4 	= 0x02,	 // < 0x02 > CPU clk/4
	ADC_PRESCALE_DIV8 	= 0x03,	 // < 0x03 > CPU clk/8
	ADC_PRESCALE_DIV16 	= 0x04,	 // < 0x04 > CPU clk/16
	ADC_PRESCALE_DIV32 	= 0x05,	 // < 0x05 > CPU clk/32
	ADC_PRESCALE_DIV64 	= 0x06,	 // < 0x06 > CPU clk/64
	ADC_PRESCALE_DIV128 = 0x07	 // < 0x07 > CPU clk/128

} ADC_PRESCALE;

// default value
#define ADC_PRESCALE_DEFAULT			ADC_PRESCALE_DIV64


/* 	A2D voltage reference select *****
*	this determines what is used *****
*	as the full-scale voltage point **
*	for A2D conversions **************
*/
typedef enum
{
	ADC_REFERENCE_AREF = 0x00,	// < 0x00 > AREF pin, internal VREF turned off
	ADC_REFERENCE_AVCC = 0x01,	// < 0x01 > AVCC pin, internal VREF turned off
								// < 0x02 > Reserved
	ADC_REFERENCE_256V = 0x03	// < 0x03 > Internal 2.56V VREF
} ADC_REFERENCE;

// default value
#define ADC_REFERENCE_DEFAULT		ADC_REFERENCE_AVCC



class A2D
{
  private:
  
    volatile float Adc_fVal;
    volatile unsigned long Adc_cVal;

  public:
    //volatile static unsigned long Timer_val;  // we can also use internal Timer its just for a small count
    void InitAdc(void);
    unsigned long ValAdc(unsigned int);

    static void AdcOn(void);
    static void AdcOff(void);

    static void SetPrescaler(ADC_PRESCALE prescale);
    static void SetReference(ADC_REFERENCE reference);

    A2D(){}

    /// Interrupt routines.
  	friend void ADC_vect(void);

  	~A2D(){}
};

#endif /*adc_H_*/
