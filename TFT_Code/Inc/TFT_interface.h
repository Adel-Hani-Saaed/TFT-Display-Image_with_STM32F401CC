/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: HAL			  *******************/
/*************** SWC: TFT 		  	  *******************/
/*************** Date: 9/6/2023 	  *******************/
/*************** Author: Adel Hani    *******************/
/********************************************************/
/********************************************************/
#ifndef TFT_INTERFACE_H_
#define TFT_INTERFACE_H_

#define TFT_DISPALY_SIZE	20480


void TFT_voidResetSequence(void);

void TFT_voidInit(void);

void TFT_voidDisplayImage (const u16 *Copy_pu16Image);

#endif /* TFT_INTERFACE_H_ */
