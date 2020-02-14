/*
 * Project: Si4463 Radio Library for AVR and Arduino
 * Author: Zak Kemble, contact@zakkemble.co.uk
 * Copyright: (C) 2017 by Zak Kemble
 * License: GNU GPL v3 (see License.txt)
 * Web: http://blog.zakkemble.co.uk/si4463-radio-library-avr-arduino/
 */

#ifndef SI446X_SPI_H_
#define SI446X_SPI_H_

void spi_init(void);

inline void spi_transfer_nr(uint8_t data)
{
	// The following is adapted from: https://stackoverflow.com/questions/56440516/stm32-spi-slow-compute.

    *(volatile uint8_t *)&SPI_PORT->DR = data; // Transmit
    while((SPI_PORT->SR & (SPI_SR_TXE | SPI_SR_BSY)) != SPI_SR_TXE)
        ;
}

inline uint8_t spi_transfer(uint8_t data)
{
    *(volatile uint8_t *)&SPI_PORT->DR = data; // Transmit
    while((SPI_PORT->SR & (SPI_SR_TXE | SPI_SR_BSY)) != SPI_SR_TXE)
        ;
    
    // Adapted from STM32 HAL files.
    return *(volatile uint8_t *)&SPI_PORT->DR; // Receive
}


/**
 * @brief Initialize the CR1 Register parameters with a 32 bit input.
 * @param   spi_loc     Location of SPI typedef in.
 * @param   full_value  Full value of input parameters.
 */
static void init_spi_param_cr1(ST_SPI *spi_loc, uint32_t full_value);


/**
 * @brief Initialize the SPI bus
 * @param spi_loc       The location of the SPI struct
 * @param spi_memloc    Pointer to location of SPI in memory
 * @param full_value    Full value of input parameters.
 */
void init_spi(ST_SPI *spi_loc, SPI_TypeDef *spi_memloc, uint32_t full_value);



typedef struct{
    SPI_TypeDef     *Instance;  //Memory location of desired SPI
    ST_SPIINIT      Init;       //Init Params
}ST_SPI;



typedef struct{
    uint32_t        CPHA;       //Clock Phase
    uint32_t        CPOL;       //Clock Polarity
    uint32_t        MSTR;       //Master Select
    uint32_t        BR0;        //Baud-Rate Prescaler bit 0
    uint32_t        BR1;        //Baud-Rate Prescaler bit 1
    uint32_t        BR2;        //Baud-Rate Prescaler bit 2
    uint32_t        SPE;        //SPI Peripheral Enable
    uint32_t        LSBFIRST;   //Least Significant Bit First Enable
    uint32_t        SSI;        //Software Slave Select Internal Default Bitvalue
    uint32_t        SSM;        //Software Slave Management
    uint32_t        RXONLY;     //RX Only Enable
    uint32_t        DFF;        //Data Frame Format
    uint32_t        CRCNEXT;    //CRC Transfer Next   
    uint32_t        CRCEN;      //CRC Enable
    uint32_t        BIDIOE;     //Bidirectional Output Mode Enable
    uint32_t        BIDIMODE;   //Bidirectional Data Mode Enable
}ST_SPIINIT;


#endif /* SI446X_SPI_H_ */
