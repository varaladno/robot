#include "MeMegaPi.h"

MeMegaPiDCMotor motor3(PORT2A);
MeMegaPiDCMotor motor4(PORT2B);

MeMegaPiDCMotor motor5(PORT3A);
MeMegaPiDCMotor motor6(PORT3B);

MeMegaPiDCMotor motor1(PORT4A);
MeMegaPiDCMotor motor2(PORT4B);

MeMegaPiDCMotor motor7(PORT1A);
MeMegaPiDCMotor motor8(PORT1B);
void setup() {

// put your setup code here, to run once:
pinMode(A10,INPUT);
pinMode(A8,INPUT);
pinMode(A7,INPUT);
pinMode(A9,INPUT);
Serial.begin(9600);
}

void loop() {
int a = pulseIn(A10,HIGH);
int b = pulseIn(A8,HIGH);
int c = pulseIn(A7,HIGH);
int d = pulseIn(A9,HIGH);
int sp = ((a-1122)/1.696-285)/2;
int sp2 = ((b-1115)/1.7-285)/2;

if( c>1800){
  motor7.run(100);
  motor8.run(100);
  }
if( c<1200){
  motor7.run(-100);
  motor8.run(-100 );
  }
if( c<1800 && c>1200){
  motor7.run(0);
  motor8.run(0);
  }

  if (d>=1800) {
motor1.run(100 );
motor2.run(100 );
   }

if (d<=1200) {
motor1.run(-100);
motor2.run(-100);
}

 if (d>1200 && d<1800) {
motor1.run(0);
motor2.run(0);
 }

  motor3.run(-sp2+sp);
  motor4.run(-sp2+sp);
  motor5.run(sp2+sp);
  motor6.run(sp2+sp);


  

Serial.println(d);
}
//Первый порт - правый джостик лево-право
//Второй порт - правый джостик вверх-вниз
//Третий порт - правый джостик вверх-вниз
//Четвертый порт - правый джостик лево-право

