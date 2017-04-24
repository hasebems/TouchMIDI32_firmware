/* ========================================
 *
 *	main.c
 *		description: TouchMidi32 Main Functions
 *
 *	Copyright(c)2017 Masahiko Hasebe at Kigakudoh
 *  This software is released under the MIT License, see LICENSE.txt
 *
 * ========================================
*/
#include "project.h"
#include "tm32_lib.h"
#include "tm32_i2cdev.h"
#include "tm32_app.h"

//---------------------------------------------------------
//
//---------------------------------------------------------
void USBMIDI_callbackLocalMidiEvent(uint8_t cable, uint8_t *midiMsg)
{
	uint8_t i = cable;		//	no meaning
	uint8_t msg = *midiMsg;	//	
	i += msg;				//	
}							

//---------------------------------------------------------
//			Main
//---------------------------------------------------------
int main(void)
{	
	CyGlobalIntEnable; /* Enable global interrupts. */	
	
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
	USBMIDI_Start(0, USBMIDI_DWR_POWER_OPERATION);
//	USBMIDI_MIDI_Init();
	MIDI_UART_Start();
	MIDI_OUT_SetDriveMode(MIDI_OUT_DM_STRONG);	//	Manual page2: PSoC 4 Glitch Avoidance at System Reset

	EZI2C_Start(); /* Start EZI2C component */
	/*
	* Set up communication and initialize data buffer to CapSense data structure
	* to use Tuner application
	*/
	EZI2C_EzI2CSetBuffer1(sizeof(CapSense_dsRam), sizeof(CapSense_dsRam),(uint8 *)&CapSense_dsRam);
	CapSense_Start();
	CapSense_ScanAllWidgets();
	
	SystemTimer_Start();
	isrTimer_Start();

	I2C_Start();
	
	tm32_initLib();
	tm32_init();
	
    for(;;)
    {
        /* Place your application code here. */
		tm32_loop();

		/*	MIDI UART Rx Check	*/
#if ( UART_MIDI_RX != UART_MIDI_NO_USE )
		uint8 rxCount = MIDI_UART_GetRxBufferSize();
		int i;
		for ( i=0; i<rxCount; i++ ){
			uint16_t midiUartRx = MIDI_UART_GetByte();
			if ( midiUartRx & 0xff00 ){ continue; }
			uint8_t mD = (uint8_t)(midiUartRx & 0x00ff);
			tm32_rcvMidiOnUart(mD);
		}
#endif

		/*	Button Type Touch Sensor */
		if ( CapSense_NOT_BUSY == CapSense_IsBusy() ){
			CapSense_ProcessAllWidgets();
			CapSense_RunTuner(); /* To sync with Tuner application */

			uint32 swState = CapSense_IsAnyWidgetActive();
			tm32_generateTouchSenseEvent( swState );
			CapSense_ScanAllWidgets();
		}		
		
		/*	Check if USB-MIDI is inserted	*/
		if (0 != USBMIDI_IsConfigurationChanged()) {
            if (0 != USBMIDI_GetConfiguration()) {
            	USBMIDI_MIDI_EP_Init();
        	}
    	}

		/* Service USB MIDI when device is configured */
        if(0u != USBMIDI_GetConfiguration()){
			USBMIDI_MIDI_IN_Service();
			USBMIDI_MIDI_OUT_EP_Service();
		}		
    }
}

/* [] END OF FILE */
