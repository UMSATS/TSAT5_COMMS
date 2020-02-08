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

#endif /* SI446X_SPI_H_ */
