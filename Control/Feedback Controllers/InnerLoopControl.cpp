/*MIT License

Copyright (c) 2020 Nyameaama Gambrah

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include"InnerLoopControl.h"

AUAC_BASE_AUAC_BASE_DOUBLE ADJUST_ROLL(AUAC_BASE_DOUBLE set, AUAC_BASE_DOUBLE current){
    PROPORTIONAL_INTEGRAL_DERIVATIVE *control = new PROPORTIONAL_INTEGRAL_DERIVATIVE;
    MOTOR_MIXING *mix = new MOTOR_MIXING;
    AUAC_BASE_DOUBLE kp,kd,ki;  //<- Tune PID gains
    control -> createPIDinstance("innerLoopRoll",kp,ki,kd);
    AUAC_BASE_DOUBLE newR = control -> PID_MAIN("innerLoopRoll",set,current);
    mix -> MOTOR_MIX_ROLL(newR);
    delete control;
    delete mix;
    return;
}

AUAC_BASE_AUAC_BASE_DOUBLE ADJUST_PITCH(AUAC_BASE_DOUBLE set, AUAC_BASE_DOUBLE current){
    PROPORTIONAL_INTEGRAL_DERIVATIVE *control = new PROPORTIONAL_INTEGRAL_DERIVATIVE;
    MOTOR_MIXING *mix = new MOTOR_MIXING;
    AUAC_BASE_DOUBLE kp,kd,ki;  //<- Tune PID gains
    control -> createPIDinstance("innerLoopPitch",kp,ki,kd);
    AUAC_BASE_DOUBLE newP = control -> PID_MAIN("innerLoopPitch",set,current);
    mix -> MOTOR_MIX_ROLL(newP);
    delete control;
    delete mix;
    return;
}
        
AUAC_BASE_AUAC_BASE_DOUBLE ADJUST_YAW(AUAC_BASE_DOUBLE set, AUAC_BASE_DOUBLE current){
    PROPORTIONAL_INTEGRAL_DERIVATIVE *control = new PROPORTIONAL_INTEGRAL_DERIVATIVE;
    MOTOR_MIXING *mix = new MOTOR_MIXING;
    AUAC_BASE_DOUBLE kp,kd,ki; //<- Tune PID gains
    control -> createPIDinstance("innerLoopYaw",kp,ki,kd);
    AUAC_BASE_DOUBLE newY = control -> PID_MAIN("innerLoopYaw",set,current);
    mix -> MOTOR_MIX_ROLL(newY);
    delete control;
    delete mix;
    return;
}