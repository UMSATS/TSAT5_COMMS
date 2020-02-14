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

static void init_spi_param_cr1(ST_SPI *spi_loc, uint32_t full_value){
    if(full_value & 0x40)//Ensure value of SPI Enable is 1
        return 0;
    else{
        spi_loc->Init.CPHA        =     full_value && 0x0001;
        spi_loc->Init.CPOL        =     full_value && 0x0002;
        spi_loc->Init.MSTR        =     full_value && 0x0004;
        spi_loc->Init.BR0         =     full_value && 0x0008;
        spi_loc->Init.BR1         =     full_value && 0x0010;
        spi_loc->Init.BR2         =     full_value && 0x0020;
        spi_loc->Init.SPE         =     full_value && 0x0040;
        spi_loc->Init.LSBFIRST    =     full_value && 0x0080;
        spi_loc->Init.SSI         =     full_value && 0x0100;
        spi_loc->Init.SSM         =     full_value && 0x0200;
        spi_loc->Init.RXONLY      =     full_value && 0x0400;
        spi_loc->Init.DFF         =     full_value && 0x0800;
        spi_loc->Init.CRCNEXT     =     full_value && 0x1000;
        spi_loc->Init.CRCEN       =     full_value && 0x2000;
        spi_loc->Init.BIDIOE      =     full_value && 0x4000;
        spi_loc->Init.BIDIMODE    =     full_value && 0x8000;
    }
}


/**
 * Initialize the SPI bus
 * @param spi_loc       The location of the SPI struct
 * @param spi_memloc    Pointer to location of SPI in memory
 * @param full_value    Full value of 
 */
void init_spi(ST_SPI *spi_loc, SPI_TypeDef *spi_memloc, uint32_t full_value){
    spi_loc->Instance = spi_memloc;

    init_spi_param_cr1(spi_loc, full_value);

    *(volatile uint8_t *)&spi_loc->Instance->CR1 = (
        spi_loc->Init.CPHA        ||
        spi_loc->Init.CPOL        ||
        spi_loc->Init.MSTR        ||
        spi_loc->Init.BR0         ||
        spi_loc->Init.BR1         ||
        spi_loc->Init.BR2         ||
        spi_loc->Init.SPE         ||
        spi_loc->Init.LSBFIRST    ||
        spi_loc->Init.SSI         ||
        spi_loc->Init.SSM         ||
        spi_loc->Init.RXONLY      ||
        spi_loc->Init.DFF         ||
        spi_loc->Init.CRCNEXT     ||
        spi_loc->Init.CRCEN       ||
        spi_loc->Init.BIDIOE      ||
        spi_loc->Init.BIDIMODE    
    );
}


    typedef struct{
        SPI_TypeDef     *Instance;
        ST_SPIINIT      Init;
    }ST_SPI;

    typedef struct{
        uint32_t        CPHA;       //Clock Phase
        uint32_t        CPOL;       //Clock Polarity
        uint32_t        MSTR;       //
        uint32_t        BR0;        //Baud-Rate Prescaler bit 0
        uint32_t        BR1;        //Baud-Rate Prescaler bit 1
        uint32_t        BR2;        //Baud-Rate Prescaler bit 2
        uint32_t        SPE;        //SPI Peripheral Enable
        uint32_t        LSBFIRST;   //Least Significant Bit First Enable
        uint32_t        SSI;        //Software Slave Select Internal Default Bitvalue
        uint32_t        SSM;        //Software Slave Select
        uint32_t        RXONLY;     //RX Only FIFO
        uint32_t        DFF;        //
        uint32_t        CRCNEXT;        
        uint32_t        CRCEN;      //CRC Enable
        uint32_t        BIDIOE;     //Bidirectional Mode Enable
        uint32_t        BIDIMODE;   
    }ST_SPIINIT;


#endif /* SI446X_SPI_H_ */
