/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

	if(( Pin_Input_Read() == 0/*Pressed*/) || (Bootloader_GET_RUN_TYPE == Bootloader_START_BTLDR))
	{	
		Bootloader_SET_RUN_TYPE(Bootloader_START_BTLDR);		
	}	

	/* Place your initialization/startup code here (e.g. MyInst_Start()) */
	Bootloader_Start();

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
