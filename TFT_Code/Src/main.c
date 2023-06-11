#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "SYSTICK_interface.h"
#include "SPI_interface.h"
#include "image.h"
#include "TFT_interface.h"


int main(void)
{
	/*RCC initialization*/
	MRCC_voidInitSystemClk();
	MRCC_voidEnablePeripheralClock(AHB1, MRCC_PERIPHERAL_EN_GPIOA);
	MRCC_voidEnablePeripheralClock(APB2,MRCC_PERIPHERAL_EN_SPI_1 );

	/*Pin Configuration*/
	MGPIO_voidSetPinMode(MGPIOA_PORT, MGPIO_PIN1, MGPIO_MODE_OUTPUT);	// Reset
	MGPIO_voidSetPinMode(MGPIOA_PORT, MGPIO_PIN2, MGPIO_MODE_OUTPUT);	// A0

	MGPIO_voidSetPinAlternativeFunction(MGPIOA_PORT, MGPIO_PIN5, GPIOx_AF5); // SCK
	MGPIO_voidSetPinAlternativeFunction(MGPIOA_PORT, MGPIO_PIN7, GPIOx_AF5); //MOSI

	/*Systick initialization*/
	STK_voidInit();

	/*SPI initialization*/
	SPI_voidInit();

	/*TFT initialization*/
	TFT_voidInit();

	/*Display Image */
	TFT_voidDisplayImage(Image);

	while(1)
	{


	}
}
