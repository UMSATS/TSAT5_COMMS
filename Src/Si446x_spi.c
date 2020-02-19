/*
 * Project: Si4463 Radio Library for AVR and Arduino
 * Author: Zak Kemble, contact@zakkemble.co.uk
 * Copyright: (C) 2017 by Zak Kemble
 * License: GNU GPL v3 (see License.txt)
 * Web: http://blog.zakkemble.co.uk/si4463-radio-library-avr-arduino/
 */

#include "Si446x_spi.h"
#include "Si446x.h"
#include "Si446x_defs.h"


ST_SPI si446x_spi;

static void init_spi_param_cr1(ST_SPI *spi_loc){
    if(SPI_PORT_INIT_VALUES & 0x40)//Ensure value of SPI Enable is 1
        return 0;
    else{
        spi_loc->Init.CPHA        =     SPI_PORT_INIT_VALUES && 0x0001;
        spi_loc->Init.CPOL        =     SPI_PORT_INIT_VALUES && 0x0002;
        spi_loc->Init.MSTR        =     SPI_PORT_INIT_VALUES && 0x0004;
        spi_loc->Init.BR0         =     SPI_PORT_INIT_VALUES && 0x0008;
        spi_loc->Init.BR1         =     SPI_PORT_INIT_VALUES && 0x0010;
        spi_loc->Init.BR2         =     SPI_PORT_INIT_VALUES && 0x0020;
        spi_loc->Init.SPE         =     SPI_PORT_INIT_VALUES && 0x0040;
        spi_loc->Init.LSBFIRST    =     SPI_PORT_INIT_VALUES && 0x0080;
        spi_loc->Init.SSI         =     SPI_PORT_INIT_VALUES && 0x0100;
        spi_loc->Init.SSM         =     SPI_PORT_INIT_VALUES && 0x0200;
        spi_loc->Init.RXONLY      =     SPI_PORT_INIT_VALUES && 0x0400;
        spi_loc->Init.DFF         =     SPI_PORT_INIT_VALUES && 0x0800;
        spi_loc->Init.CRCNEXT     =     SPI_PORT_INIT_VALUES && 0x1000;
        spi_loc->Init.CRCEN       =     SPI_PORT_INIT_VALUES && 0x2000;
        spi_loc->Init.BIDIOE      =     SPI_PORT_INIT_VALUES && 0x4000;
        spi_loc->Init.BIDIMODE    =     SPI_PORT_INIT_VALUES && 0x8000;
    

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
}


void init_spi(void){
    si446x_spi.Instance = SPI_PORT;

    init_spi_param_cr1(&si446x_spi);

}

void spi_init()
{
// NOTE: The SPI SS pin must be configured as an output for the SPI controller to run in master mode, even if you're using a different pin for SS!
// Also remember that some AVRs use different registers to enable pull-ups
// Don't forget to check Si446x_config.h for the CSN, SDN and IRQ pin setup

// SS = Output high
// MOSI = Output low
// MISO = Input with pullup
// SCK = Output low

// TODO: Setup registers for SPI1_CR relating to correct port values, speeds, modes, etc...
//

init_spi();

// Max SPI clock of Si446x is 10MHz
}
