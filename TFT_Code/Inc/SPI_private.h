/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: SPI 		  	  *******************/
/*************** Date: 8/6/2023 	  *******************/
/*************** Author: Adel Hani    *******************/
/********************************************************/
/********************************************************/
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPI_BASE_ADDRESS		0x40013000

typedef struct
{
	volatile u32 CR1    ;
	volatile u32 CR2    ;
	volatile u32 SR     ;
	volatile u32 DR     ;
	volatile u32 CRCPR  ;
	volatile u32 RXCRCR ;
	volatile u32 TXCRCR ;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR  ;

}SPI_Register;


#define SPI   ((SPI_Register*)SPI_BASE_ADDRESS)


#endif /* SPI_PRIVATE_H_ */
