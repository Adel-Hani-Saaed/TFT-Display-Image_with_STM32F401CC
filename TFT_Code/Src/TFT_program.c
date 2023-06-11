//********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: HAL			  *******************/
/*************** SWC: TFT 		  	  *******************/
/*************** Date: 9/6/2023 	  *******************/
/*************** Author: Adel Hani    *******************/
/********************************************************/
/********************************************************/


#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "MGPIO_Interface.h"
#include "SPI_interface.h"
#include "SYSTICK_interface.h"

#include "TFT_private.h"
#include "TFT_config.h"
#include "TFT_interface.h"

void TFT_voidResetSequence(void)
{
	/*Reset Pulse ,Tick Time = 0.5 Microsecond*/
	MGPIO_voidSetPinValue(TFT_RST_PIN , MGPIO_HIGH);
	STK_voidSetBusyWaitInterval(200);    //100 Microsecond
	MGPIO_voidSetPinValue(TFT_RST_PIN , MGPIO_LOW);
	STK_voidSetBusyWaitInterval(2);		 //1 Microsecond
	MGPIO_voidSetPinValue(TFT_RST_PIN , MGPIO_HIGH);
	STK_voidSetBusyWaitInterval(200);	 //100 Microsecond
	MGPIO_voidSetPinValue(TFT_RST_PIN , MGPIO_LOW);
	STK_voidSetBusyWaitInterval(200);	 //100 Microsecond
	MGPIO_voidSetPinValue(TFT_RST_PIN , MGPIO_HIGH);
	STK_voidSetBusyWaitInterval(240000); // 120 MS
}

void TFT_voidInit(void)
{
	/*Reset sequence*/
	TFT_voidResetSequence();

	/*Send Sleep_out command ID = 0x11*/
	TFT_voidWriteCommand(0x11);

	/*Delay for 150MS*/
	STK_voidSetBusyWaitInterval(300000);

	/*Choose color coding ID -> 0x3A   ,  RGB656 -> Parameter -> 0x05*/
	TFT_voidWriteCommand(0x3A);   // Id
	TFT_voidWriteData(0x05);	  // Data  -> RGB 656 -> 0x05

	/*Display on Command =? ID = 0x29*/
	TFT_voidWriteCommand(0x29);
}

void TFT_voidDisplayImage (const u16 *Copy_pu16Image)
{
	u16 Local_u16Counter;

	/*Set X Address*/
	TFT_voidWriteCommand(0x2A); 		//Set X address command ID

	/*Start Address*/
	TFT_voidWriteData(0);		//Set X Address Command Data Parameter 1Byte MSB
	TFT_voidWriteData(0);		//Set X Address Command Data Parameter 2Byte LSB

	/*End Address*/
	TFT_voidWriteData(0);		//Set X Address Command Data Parameter 1Byte MSB
	TFT_voidWriteData(127);		//Set X Address Command Data Parameter 2Byte LSB

	/*Set Y Address*/
	TFT_voidWriteCommand(0x2B); 		//Set Y address command ID

	/*Start Address*/
	TFT_voidWriteData(0);		//Set Y Address Command Data Parameter 1Byte MSB
	TFT_voidWriteData(0);		//Set Y Address Command Data Parameter 2Byte LSB

	/*End Address*/
	TFT_voidWriteData(0);		//Set Y Address Command Data Parameter 1Byte MSB
	TFT_voidWriteData(159);		//Set Y Address Command Data Parameter 2Byte LSB


	/* RAM Write command */
	TFT_voidWriteCommand(0x2C);

	/*Display*/
	for(Local_u16Counter = 0 ; Local_u16Counter < TFT_DISPALY_SIZE ; Local_u16Counter++)
	{
		/*Send MSByte*/
		TFT_voidWriteData(Copy_pu16Image[Local_u16Counter] >> 8);
		/*Send LSByte*/
		TFT_voidWriteData(Copy_pu16Image[Local_u16Counter] & 0x00ff);
	}
}

static void TFT_voidWriteCommand(u8 Copy_u8Command)
{
	/*Pull TFT_A0_PIN to ground*/
	MGPIO_voidSetPinValue(TFT_A0_PIN , MGPIO_LOW);

	/*Send value of command   // Type casting for i tell compiler i not care the return  */
	(void)SPI_voidSendReceive(Copy_u8Command);

}

static void TFT_voidWriteData(u8 Copy_u8Data)
{
	/*Pull TFT_A0_PIN to VCC*/
	MGPIO_voidSetPinValue(TFT_A0_PIN , MGPIO_HIGH);

	/*Send value of data   // Type casting for i tell compiler i not care the return*/
	(void)SPI_voidSendReceive(Copy_u8Data);

}
