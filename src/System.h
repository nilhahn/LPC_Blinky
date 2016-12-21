/*
 * System.h
 *
 *  Created on: 09.12.2016
 *      Author: Nilhahn
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "chip.h"
#include <cr_section_macros.h>

typedef struct{
	uint16_t port;
	uint16_t pin;
} Gpio;

typedef enum{IN, OUT} Direction;

/**
 * Function: System_EnableGPIO
 * brief: configures the GPIO for later use
 */
void System_EnableGPIO();

/**
 * Function: System_SetPortPin
 * brief: configure the given io
 */
void System_SetPortPin(Gpio* io, uint16_t port, uint16_t pin);

/**
 * Function: System_SetPinMode
 * brief: configure specified port[pin] combi
 * Input:
 * 	Gpio*: 	pointer to port[pin] combi
 * 	mode: 	operation mode for the port[pin]
 */
int16_t System_SetPinMode(const Gpio* io,uint16_t mode);

/**
 * Function: System_SetPinDir
 * brief:  specified port[pin] combi
 * Input:
 * 	Gpio*: 	pointer to port[pin] combi
 * 	Direction: 	direction (defined in the Direction enum)
 */
int16_t System_SetPinDir(const Gpio* io, Direction dir);

/**
 * Function: System_WritePin
 * brief:  write the logic value to the given port
 * Input:
 * 	Gpio*: 		pointer to the output port[pin] combi
 * 	uint16_t: 	write value
 */
int16_t System_WritePin(const Gpio* io, uint16_t value);

#endif /* SYSTEM_H_ */
