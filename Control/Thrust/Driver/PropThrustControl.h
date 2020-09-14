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

#include<stdint.h>
#include<stddef.h>
#include<Arduino.h>
#include"../../../utility/definitions.h"

#define HIGH 1
#define LOW 0
#define OUTPUT 1
#define BPIN1 4
#define BPIN2 5
#define BPIN3 6
#define BPIN4 7

//Propeller Thrust Rate Control
//When each of the 4 propellers velocity is adjusted, it causes a change in direction of the craft
//Using this our primary control means we can adjust the direction of yaw movement

class PropThrustControl {
    private:
        AUAC_UBASE_8 thrustWriteFL(double PWM);

        AUAC_UBASE_8 thrustWriteFR(double PWM);

        AUAC_UBASE_8 thrustWriteBL(double PWM);

        AUAC_UBASE_8 thrustWriteBR(double PWM);

        AUAC_UBASE_8 updateThrustValues(uint8_t MOTOR, double tLevel);


    public:
        PropThrustControl();

        AUAC_UBASE_8 PWM_init(uint8_t MOTOR,double M2_VEL);

        //Translates 0 - 9 motor PWM values to 0,175 - 255
        AUAC_BASE_DOUBLE translate(double x);

        AUAC_BASE_DOUBLE *returnCurrentThrustValues();

};