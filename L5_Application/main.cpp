/*
 *     SocialLedge.com - Copyright (C) 2013
 *
 *     This file is part of free software framework for embedded processors.
 *     You can use it and/or distribute it as long as this copyright header
 *     remains unmodified.  The code is free for personal use and requires
 *     permission to use in a commercial product.
 *
 *      THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 *      OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 *      MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 *      I SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 *      CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *     You can reach the author of this software at :
 *          p r e e t . w i k i @ g m a i l . c o m
 */

/**
 * @file
 * @brief This is the application entry point.
 */

#include <stdio.h>
#include "utilities.h"
#include "io.hpp"
#include "gpio.hpp"
#include "lpc_pwm.hpp"


float xaxis();
int redcolor(int);
int bluecolor(int);
int greencolor(int);

int main(void){
   // bool button(); we need the ports for this
   typedef enum {
       off,
       blue,
       red,
       green,
       purple,
       rainbow,
    } lights_t;
    lights_t current_state = off;

    while(1) {
        PWM Lred(PWM::pwm2, 1000);
        PWM Lgreen(PWM::pwm4, 1000);
        PWM Lblue(PWM::pwm6, 1000);
        GPIO pin2_7(P1_20);
        bool button = pin2_7.read();
        int tilt_x = 0;
        int redval = 0;
        int blueval = 0;
        int greenval = 0;
        delay_ms(100);
        switch(current_state){
            case off:
                Lgreen.set(0);
                Lred.set(0);
                Lblue.set(0);
                // all colors off, wait for 85% tilt.


                tilt_x = xaxis();
                if(tilt_x >= 85){
                    current_state=blue;
                }

                break;
            case blue:

                LD.clear();
                //color starts at blue
                Lblue.set(100);
                Lred.set(0);
                Lgreen.set(0);

                delay_ms(500);
                delay_ms(100);
                if(button == 1){
                    current_state = red;
                }
            break;
            case red:
                //color change to red.
                Lred.set(100);
                Lblue.set(0);
                Lgreen.set(0);

                delay_ms(500);
                delay_ms(100);
                if(button==1){
                    current_state = green;
                }
            break;
            case green:
                // color change to green
                Lred.set(0);
                Lgreen.set(100);
                Lblue.set(0);

                delay_ms(500);
                delay_ms(100);
                if(button==1){
                    current_state = purple;
                }
            break;
            case purple:
                // color change to purple using full green and red.
                Lred.set(100);
                Lblue.set(100);
                Lgreen.set(0);

                delay_ms(500);
                delay_ms(100);
                if(button==1){
                    current_state = rainbow;
                }
            break;
            case rainbow:
                // color changes based on tilt.
                delay_ms(10);
                if(button==1){
                    current_state = off;
                    break;
                }
                else{
                    tilt_x = xaxis();
                    redval = redcolor(tilt_x);
                    greenval = greencolor(tilt_x);
                    blueval = bluecolor(tilt_x);
                    Lred.set(redval);
                    Lblue.set(blueval);
                    Lgreen.set(greenval);
                }

            break;
            default:
            break;
        }
    }
}

float xaxis(){
    float xaxis = AS.getX();
    xaxis = ((xaxis+1024)/ 2048) * 100;
    LD.setNumber(xaxis);

    return xaxis;
}

int redcolor(int xtilt){
    int value = 100;
    if (xtilt >= 85){
        value = 1;
        while(xtilt >= 85){
            xtilt= xaxis();
        }
    }
    else if (xtilt >= 80){
        value = 100;
    }
    else if (xtilt >= 75){
        value = 75;
    }
    else if (xtilt >= 70){
        value = 50;
    }
    else if (xtilt >= 65){
        value = 25;
    }
    else if (xtilt >= 60){
        value = 0;
    }
    else if (xtilt >= 55){
        value = 0;
    }
    else if (xtilt >= 50){
        value = 0;
    }
    else if (xtilt >= 45){
        value = 0;
    }
    else if (xtilt >= 40){
        value = 0;
    }
    else if (xtilt >= 35){
        value = 25;
    }
    else if (xtilt >= 30){
        value = 50;
    }
    else if (xtilt >= 25){
        value = 75;
    }
    else if (xtilt >= 20){
        value = 100;
    }
    else if (xtilt >= 15){
        value = 100;
    }
    else if (xtilt >= 10){
        value = 100;
    }
    else if (xtilt >= 5){
        value = 100;
    }
    else if (xtilt >= 0){
        value = 100;
    }
    else{

    }
    return value;
}

int greencolor(int xtilt){
    int value = 100;
    if (xtilt >= 85){
        value = 1;
        while(xtilt >= 85){
            xtilt= xaxis();
        }
    }
    else if (xtilt >= 80){
        value = 0;
    }
    else if (xtilt >= 75){
        value = 0;
    }
    else if (xtilt >= 70){
        value = 0;
    }
    else if (xtilt >= 65){
        value = 0;
    }
    else if (xtilt >= 60){
        value = 0;
    }
    else if (xtilt >= 55){
        value = 25;
    }
    else if (xtilt >= 50){
        value = 50;
    }
    else if (xtilt >= 45){
        value = 75;
    }
    else if (xtilt >= 40){
        value = 100;
    }
    else if (xtilt >= 35){
        value = 75;
    }
    else if (xtilt >= 30){
        value = 50;
    }
    else if (xtilt >= 25){
        value = 25;
    }
    else if (xtilt >= 20){
        value = 0;
    }
    else if (xtilt >= 15){
        value = 25;
    }
    else if (xtilt >= 10){
        value = 50;
    }
    else if (xtilt >= 5){
        value = 75;
    }
    else if (xtilt >= 0){
        value = 100;
    }
    else{

    }
    return value;
}

int bluecolor(int xtilt){
    int value = 100;
    if (xtilt >= 85){
        value = 1;
        while(xtilt >= 85){

            xtilt= xaxis();
        }
    }
    else if (xtilt >= 80){
        value = 100;
    }
    else if (xtilt >= 75){
        value = 75;
    }
    else if (xtilt >= 70){
        value = 50;
    }
    else if (xtilt >= 65){
        value = 25;
    }
    else if (xtilt >= 60){
        value = 100;
    }
    else if (xtilt >= 55){
        value = 75;
    }
    else if (xtilt >= 50){
        value = 50;
    }
    else if (xtilt >= 45){
        value = 25;
    }
    else if (xtilt >= 40){
        value = 0;
    }
    else if (xtilt >= 35){
        value = 0;
    }
    else if (xtilt >= 30){
        value = 0;
    }
    else if (xtilt >= 25){
        value = 0;
    }
    else if (xtilt >= 20){
        value = 0;
    }
    else if (xtilt >= 15){
        value = 25;
    }
    else if (xtilt >= 10){
        value = 50;
    }
    else if (xtilt >= 5){
        value = 75;
    }
    else if (xtilt >= 0){
        value = 100;
    }
    else{

    }
    return value;
}
