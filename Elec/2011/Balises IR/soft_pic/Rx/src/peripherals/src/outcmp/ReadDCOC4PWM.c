#include <outcompare.h>

#ifdef _OC4IF

/********************************************************************
*    Function Name:  ReadDCOC4PWM                                   *
*    Description:    This routine reads duty cycle from Master      *
*                    register in PWM mode                           *
*    Parameters:     None                                           *
*    Return Value:   unsigned int:duty cycle from Secondary register*
********************************************************************/

unsigned int ReadDCOC4PWM()
{
    /* check if OC is in PWM Mode */
#if defined(__dsPIC33E__) || defined(__PIC24E__) 

    if((OC4CON1bits.OCM & 0x06) == 0x06)
    {       
        return OC4R;   /* Output Compare Secondary Register */
    }

#else

    if((OC4CONbits.OCM & 0x06) == 0x06)
    {       
        return OC4RS;   /* Output Compare Secondary Register */
    }

#endif

    else 
        return -1;
}

#else
#warning "Does not build on this target"
#endif
