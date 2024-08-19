/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int LED_PIN = 15;
const int BTN_PIN = 28;

const int A_PIN = 6;
const int B_PIN = 7;
const int C_PIN = 8;
const int D_PIN = 9;

const int turns = 360/(4*0.176);

int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(A_PIN);
    gpio_set_dir(A_PIN, GPIO_OUT);
    
    gpio_init(B_PIN);
    gpio_set_dir(B_PIN, GPIO_OUT);
    
    gpio_init(C_PIN);
    gpio_set_dir(C_PIN, GPIO_OUT);

    gpio_init(D_PIN);
    gpio_set_dir(D_PIN, GPIO_OUT);

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    while (true) {
        if(!gpio_get(BTN_PIN)){
            gpio_put(LED_PIN, 1);

            for(int i=0; i<turns; ++i){
                gpio_put(A_PIN, 1);
                sleep_ms(10);

                gpio_put(A_PIN, 0);
                gpio_put(B_PIN, 1);
                sleep_ms(10);

                gpio_put(B_PIN, 0);
                gpio_put(C_PIN, 1);
                sleep_ms(10);

                gpio_put(C_PIN, 0);
                gpio_put(D_PIN, 1);
                sleep_ms(10);

                gpio_put(D_PIN, 0);
                sleep_ms(10);
            }

            gpio_put(LED_PIN, 0);
            sleep_ms(250);

            while(!gpio_get(BTN_PIN)){
            };
        }
    }
}
