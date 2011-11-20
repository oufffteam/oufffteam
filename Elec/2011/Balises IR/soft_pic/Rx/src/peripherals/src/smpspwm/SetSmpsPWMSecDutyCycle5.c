#if defined(__dsPIC30F__) 
#include <p30fxxxx.h>
#elif defined(__dsPIC33F__)
#include <p33Fxxxx.h>
#endif

#if defined(__dsPIC33F__)

#include "smpspwm.h"
#ifdef _ADCP0IF
#ifdef _PWM5IF 


/*************************************************************************
* Function Name     : SetSmpsSecPWMDutyCycle5
* Description       : Provides the duty cycle value for the PWM5L output if independent 
*					  time base is selected                      
* Parameters        : unsigned int dutycycle
* Return Value      : None 
**************************************************************************/

void SetSmpsPWMSecDutyCycle5(unsigned int dutycycle )
{
    SDC5 = dutycycle ; 
	
}
#else
#warning "Does not build on this target"
#endif
#endif 

#endif
