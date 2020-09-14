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

#include"PropThrustControl.h"

double *currentMotorValues = (double*)malloc(4);

PropThrustControl::PropThrustControl(){
	pinMode(BPIN1,OUTPUT);
    pinMode(BPIN2,OUTPUT);
    pinMode(BPIN3,OUTPUT);
    pinMode(BPIN4,OUTPUT);
}
			
AUAC_UBASE_8 PropThrustControl::PWM_init(uint8_t MOTOR,double M_VEL) {
 	switch(MOTOR){
		case 1:
			thrustWriteFL(M_VEL);
			break;
		case 2:
			thrustWriteFR(M_VEL);
			break;
		case 3:
			thrustWriteBL(M_VEL);
			break;
		case 4:
			thrustWriteBR(M_VEL);
			break;		
	 }
	return;
}	 


AUAC_UBASE_8 PropThrustControl::thrustWriteFL(double PWM){
	analogWrite(BPIN1,PWM);		//CLOCKWISE
	updateThrustValues(1,PWM);
	return;
}

AUAC_UBASE_8 PropThrustControl::thrustWriteFR(double PWM){
	analogWrite(BPIN2,PWM);    //ANTI-CLOCKWISE
	updateThrustValues(2,PWM);
	return;
}

AUAC_UBASE_8 PropThrustControl::thrustWriteBL(double PWM){
	analogWrite(BPIN3,PWM);    //ANTICLOCKWISE
	updateThrustValues(3,PWM);
	return;
}

AUAC_UBASE_8 PropThrustControl::thrustWriteBR(double PWM){
	analogWrite(BPIN4,PWM);    //CLOCKWISE
	updateThrustValues(4,PWM);
	return;
}

AUAC_UBASE_8 PropThrustControl::updateThrustValues(uint8_t MOTOR, double tLevel){
	currentMotorValues[MOTOR - 1] = tLevel;
	return;
}

AUAC_BASE_DOUBLE *PropThrustControl::returnCurrentThrustValues(){
	return currentMotorValues;
}