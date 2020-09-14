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

#ifndef ILC
#define ILC

#include"../Thrust/MotorMixing/MMA.h"
#include"../PID/PID.h"
#include"../../AUAC_TYPEDEFS/AUAC_TYPEDEFS.h"
#include<stdint.h>
#include<stddef.h>

//PID controllers to change and maintain DOF

class InnerLoopControl {
    public:
        AUAC_BASE_DOUBLE ADJUST_ROLL(AUAC_BASE_AUAC_BASE_DOUBLE set,AUAC_BASE_AUAC_BASE_DOUBLE current);

        AUAC_BASE_DOUBLE ADJUST_PITCH(AUAC_BASE_DOUBLE set,AUAC_BASE_DOUBLE current);
        
        AUAC_BASE_DOUBLE ADJUST_YAW(AUAC_BASE_DOUBLE set,AUAC_BASE_DOUBLE current);

        

};

#endif