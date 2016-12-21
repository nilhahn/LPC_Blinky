/*
 * System.c
 *
 *  Created on: 09.12.2016
 *      Author: Nilhahn
 */

#include "System.h"

#define MASK(x) (1 << x)

LPC_GPIO_T* gpio[5];

//
// System_EnableGPIO()
void System_EnableGPIO(){
	gpio[0] = LPC_GPIO;
	gpio[1] = LPC_GPIO1;
	gpio[2] = LPC_GPIO2;
	gpio[3] = LPC_GPIO3;
	gpio[4] = LPC_GPIO4;

	LPC_SYSCTL->PCONP |= MASK(15);
}

//
// System_SetPortPin()
void System_SetPortPin(Gpio* io, uint16_t port, uint16_t pin){
	io->port = port;
	io->pin = pin;
}

//
// System_SetPinMode()
int16_t System_SetPinMode(const Gpio* io, uint16_t mode){
	uint16_t reg = 2*(io->port) + ((io->pin) > 15 ? 1 : 0);
	uint16_t shift = 2*((io->pin) > 15 ? (io->pin) - 16 : (io->pin));

    if(mode > 0x03){
    	return -1;
    }else{
    	LPC_IOCON->PINSEL[reg] |= mode << shift;
    	return 0;
    }
}

//
// System_SetPinDir
int16_t System_SetPinDir(const Gpio* io, Direction dir){
	if(io->port > 4 && io->pin > 31){
		return -1;
	}

	if(dir == OUT){
		gpio[io->port]->DIR |= MASK(io->pin);
	}else if(dir == IN){
		gpio[io->port]->DIR &= ~MASK(io->pin);
	}

	return 0;
}

//
// System_WritePin()
int16_t System_WritePin(const Gpio* io, uint16_t value){
	if(io->port > 4 && io->pin > 31){
		return -1;
	}

	if(value > 0){
		gpio[io->port]->SET |= MASK(io->pin);
	}else{
		gpio[io->port]->CLR |= MASK(io->pin);
	}

	return 0;
}
