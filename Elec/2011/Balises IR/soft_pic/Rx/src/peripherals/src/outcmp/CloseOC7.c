#include <outcompare.h>

#ifdef _OC7IF

/********************************************************************
* Function Name :  CloseOC7                                         *
* Description   :  This routine disables the Output Compare and its *
*                  interrupt bits.                                  *
* Parameter     :  None                                             *
* Return Value  :  None                                             *
********************************************************************/

void CloseOC7()
{   
    _OC7IE = 0;/* Disable the Interrupt bit in IEC Register */
#if defined(__dsPIC33E__) || defined(__PIC24E__) 
	OC7CON1bits.OCM = 0;  /* Turn off Output Compare7 */
#else
    OC7CONbits.OCM = 0;  /* Turn off Output Compare7 */
#endif
    _OC7IF = 0;/* Disable the Interrupt Flag bit in IFS Register */
}

#else
#warning "Does not build on this target"
#endif
