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

#include"MMA.h"

AUAC_UBASE_8 MOTOR_MIXING::THRUST_RANGE_FIX(){

}

AUAC_BASE_DOUBLE MOTOR_MIXING::getCurrentThrustLevel(uint8_t MOTOR){
    PropThrustControl *RETRIEVE = new PropThrustControl;
    double *level = RETRIEVE -> returnCurrentThrustValues();
    double thrust = level[MOTOR - 1];
    delete RETRIEVE;
    return thrust;
}

AUAC_UBASE_8 MOTOR_MIXING::MOTOR_MIX_ROLL(double roll){
    PropThrustControl *ADJUST = new PropThrustControl;
    if(roll < 0){
        ADJUST -> PWM_init(1,getCurrentThrustLevel(1) + roll);
        ADJUST -> PWM_init(2,getCurrentThrustLevel(2) - roll); 
        ADJUST -> PWM_init(3,getCurrentThrustLevel(3) + roll); 
        ADJUST -> PWM_init(4,getCurrentThrustLevel(4) - roll);  
    }else{
        ADJUST -> PWM_init(1,getCurrentThrustLevel(1) - roll);
        ADJUST -> PWM_init(2,getCurrentThrustLevel(2) + roll); 
        ADJUST -> PWM_init(3,getCurrentThrustLevel(3) - roll); 
        ADJUST -> PWM_init(4,getCurrentThrustLevel(4) + roll); 
    }
    delete ADJUST;
    return;
}

AUAC_UBASE_8 MOTOR_MIXING::MOTOR_MIX_YAW(double yaw){
    PropThrustControl *MOD = new PropThrustControl;
    if(yaw < 0){
        MOD -> PWM_init(1,getCurrentThrustLevel(1) - yaw);
        MOD -> PWM_init(2,getCurrentThrustLevel(2) + yaw); 
        MOD -> PWM_init(3,getCurrentThrustLevel(3) + yaw); 
        MOD -> PWM_init(4,getCurrentThrustLevel(4) - yaw);  
    }else{
        MOD -> PWM_init(1,getCurrentThrustLevel(1) + yaw);
        MOD -> PWM_init(2,getCurrentThrustLevel(2) - yaw); 
        MOD -> PWM_init(3,getCurrentThrustLevel(3) - yaw); 
        MOD -> PWM_init(4,getCurrentThrustLevel(4) + yaw); 
    }
    delete MOD;
    return;
}

AUAC_UBASE_8 MOTOR_MIXING::MOTOR_MIX_PITCH(double pitch){
    PropThrustControl *ALTER = new PropThrustControl;
    if(pitch < 0){
        ALTER -> PWM_init(1,getCurrentThrustLevel(1) + pitch);
        ALTER -> PWM_init(2,getCurrentThrustLevel(2) + pitch); 
        ALTER -> PWM_init(3,getCurrentThrustLevel(3) - pitch); 
        ALTER -> PWM_init(4,getCurrentThrustLevel(4) - pitch);  
    }else{
        ALTER -> PWM_init(1,getCurrentThrustLevel(1) - pitch);
        ALTER -> PWM_init(2,getCurrentThrustLevel(2) - pitch); 
        ALTER -> PWM_init(3,getCurrentThrustLevel(3) + pitch); 
        ALTER -> PWM_init(4,getCurrentThrustLevel(4) + pitch); 
    }
    delete ALTER;
    return;
}

AUAC_UBASE_8 MOTOR_MIXING::MOTOR_MIX_THRUST(double thrustLevel){
    PropThrustControl *ALTER = new PropThrustControl;
    //double *thrust = ALTER -> returnCurrentThrustValues();
    ALTER->PWM_init(1,getCurrentThrustLevel(1) + (thrustLevel));
    ALTER->PWM_init(2,getCurrentThrustLevel(2) + (thrustLevel));
    ALTER->PWM_init(3,getCurrentThrustLevel(3) + (thrustLevel));
    ALTER->PWM_init(4,getCurrentThrustLevel(4) + (thrustLevel));
    delete ALTER;
    return;
}