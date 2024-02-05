/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

void initTimerA() {
    RCC -> APB1ENR |= 0b10000;
    TIM6 -> PSC = 31999;
    TIM6 -> ARR = 500;
    TIM6 -> CNT = 0;
    TIM6 -> SR = 0;
    TIM6 -> CR1 = 1;
}

void initTimerB() {
    RCC -> APB1ENR |= 0b10000;
    TIM6 -> PSC = 31;
    TIM6 -> ARR = 250;
    TIM6 -> CNT = 0;
    TIM6 -> SR = 0;
    TIM6 -> CR1 = 1;
}

void initTimerC() {
    RCC->APB1ENR |= 0b10000;
    TIM6 -> PSC = 31999;
    TIM6 -> ARR = 1000;
    TIM6 -> CNT = 0;
    TIM6 -> SR = 0;
    TIM6 -> CR1 = 1;
}

int mainABC()
{
    //initTimerA();
    //initTimerB();
    initTimerC();

    DigitalOut led(PC_0);
    led = 0;

    while (true) {
        if (TIM6 -> SR == 1) {
            TIM6 -> SR = 0;
            led = !led;
        }
    }
}

int main() {
    mainABC();
}
