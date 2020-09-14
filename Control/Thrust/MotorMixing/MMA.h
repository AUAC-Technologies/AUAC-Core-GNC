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

#ifndef MMA
#define MMA

#include<stdint.h>
#include<stddef.h>
#include"../Driver/PropThrustControl.h"
//#include"../../../utility/definitions.h"

//Class for motor mixing algorithm

class MOTOR_MIXING {
    private:
        AUAC_UBASE_8 THRUST_RANGE_FIX();

        AUAC_BASE_DOUBLE getCurrentThrustLevel(uint8_t MOTOR);
        
    public:
        AUAC_UBASE_8 MOTOR_MIX_ROLL(double roll);

        AUAC_UBASE_8 MOTOR_MIX_YAW(double yaw);

        AUAC_UBASE_8 MOTOR_MIX_PITCH(double pitch);

        AUAC_UBASE_8 MOTOR_MIX_THRUST(double thrustLevel);

};

#endif