#include <outcompare.h>

#ifdef _OC1IF

/********************************************************************
*    Function Name:  ReadRegOC1		                            *
*    Description:    In Non PWM Mode, this function reads the OCRS  *
*                    reg or OCR reg based on input parameter        *
*    Parameters:     char reg                                       *
*    Return Value:   unsigned int OCRS (if reg is 0)                *
*                    or OCR (if reg is 1)                           *
********************************************************************/

unsigned int ReadRegOC1(char reg )
{   

#if defined(__dsPIC33E__) || defined(__PIC24E__) 
    /* check if OC is in NON_PWM Mode */
    if((OC1CON1bits.OCM & 0x06) != 0x06) 
    {                                                    
        if(reg)
        {       
            return OC1R; /* Output Compare main Register */
            
        }     
        return OC1RS;    /* Output Compare Secondary Register */
    }  

#else    
    /* check if OC is in NON_PWM Mode */
    if((OC1CONbits.OCM & 0x06) != 0x06) 
    {                                                    
        if(reg)
        {       
            return OC1R; /* Output Compare main Register */
            
        }     
        return OC1RS;    /* Output Compare Secondary Register */
    }  

#endif

    return -1;  
}

#else
#warning "Does not build on this target"
#endif

