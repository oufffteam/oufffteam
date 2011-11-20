#include <outcompare.h>

#ifdef _OC3IF

/*************************************************************************
*    Function Name:  SetPulseOC3                                         *
*    Description:    This routine writes the pulse_start to Main register*
*                    and pulse_stop to Secondary register                *
*    Parameters:     unsigned int pulse_start,unsigned int pulse_stop    *
*    Return Value:   None                                                *
*************************************************************************/

void SetPulseOC3(unsigned int pulse_start, unsigned int pulse_stop)
{   

#if defined(__dsPIC33E__) || defined(__PIC24E__) 

    /* check if OC is in NON PWM Mode */
    if( (OC3CON1bits.OCM & 0x06) != 0x06) 
    {
        OC3R = pulse_start; /* assign pulse_start to Main Register */
        OC3RS = pulse_stop; /* assign pulse_stop to Secondary Register */
    }

#else

    /* check if OC is in NON PWM Mode */
    if( (OC3CONbits.OCM & 0x06) != 0x06) 
    {
        OC3R = pulse_start; /* assign pulse_start to Main Register */
        OC3RS = pulse_stop; /* assign pulse_stop to Secondary Register */
    }
#endif
}

#else
#warning "Does not build on this target"
#endif
