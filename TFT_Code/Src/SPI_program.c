/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: SPI 		  	  *******************/
/*************** Date: 8/6/2023 	  *******************/
/*************** Author: Adel Hani    *******************/
/********************************************************/
/********************************************************/

#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "MGPIO_Interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_interface.h"


void SPI_voidInit(void)
{
	/*
	 * 1- Master Mode = 1
	 * 2- CPOL = 1 , CPHA = 1
	 * 3- CLK = 8M Pre_scaler = clk/2     0 0 0
	 * 4- Full Duplex
	 * 5- 8-Bits Data
	 * 6- SSM ,SSI -> 1
	 * 7- SPI Enable
	 * 8- LSB first = 0 then MSB first 1
	 */
	SPI->CR1 = 0x0347;
}


u8 SPI_voidSendReceive(u8 Copy_u8DataToTransmit)
{
	MGPIO_voidSetPinMode(SPI_SLAVE_SELECT, MGPIO_MODE_OUTPUT);
	MGPIO_voidSetPinValue(SPI_SLAVE_SELECT, MGPIO_LOW);

	/* Send Data */
	SPI -> DR = Copy_u8DataToTransmit;

	/* Wait Busy Flag to finish */
	while (GET_BIT(SPI -> SR, 7));

	MGPIO_voidSetPinValue(SPI_SLAVE_SELECT, MGPIO_HIGH);

	/* Return to the received data */
	return (u8)(SPI -> DR);
}
