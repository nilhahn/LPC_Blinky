/*
===============================================================================
 Name        : LPC_Blink_02.c
 Author      : Nilhahn
 Version     :
 Copyright   :
 Description : main definition
===============================================================================
*/

#include "System.h"

#define LED1_PORT 0
#define LED2_PORT 0
#define LED3_PORT 0
#define LED4_PORT 0

#define LED1_PIN 21
#define LED2_PIN 22
#define LED3_PIN 21
#define LED4_PIN 23

//
// main()
int main(void) {

    SystemCoreClockUpdate();
    volatile static int i = 0 ;

    System_EnableGPIO();

    Gpio led_red;
    System_SetPortPin(&led_red,LED2_PORT,LED2_PIN);

    Gpio led_yellow;
    System_SetPortPin(&led_yellow,LED3_PORT,LED3_PIN);

    Gpio led_red_01;
    System_SetPortPin(&led_red_01,LED4_PORT,LED4_PIN);

    System_SetPinMode(&led_red,0b00);
    System_SetPinMode(&led_red_01,0b00);
    System_SetPinMode(&led_yellow,0b00);
    System_SetPinDir(&led_red,OUT);
    System_SetPinDir(&led_red_01,OUT);
    System_SetPinDir(&led_yellow,OUT);

    while(1) {
        System_WritePin(&led_red,1);
        System_WritePin(&led_red_01,1);
        System_WritePin(&led_yellow,1);

        for(i = 0; i < 6000000/2; i++);
        System_WritePin(&led_yellow,0);
        for(i = 0; i < 6000000/4; i++);
        System_WritePin(&led_yellow,1);
        for(i = 0; i < 6000000/4; i++);

        System_WritePin(&led_red, 0);
        System_WritePin(&led_red_01, 0);
        System_WritePin(&led_yellow, 0);

        for(i = 0; i < 6000000/2; i++);
        System_WritePin(&led_red_01, 1);
        for(i = 0; i < 6000000/4; i++);
        System_WritePin(&led_red_01, 0);
        for(i = 0; i < 6000000/4; i++);
    }
    return 0 ;
}
