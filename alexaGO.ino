#include <MeMegaPi.h>

MeMegaPiDCMotor motor1(PORT2B);

MeMegaPiDCMotor motor2(PORT1B);

MeMegaPiDCMotor motor3(PORT3B);

MeMegaPiDCMotor motor4(PORT4B);   //  Motor at slot4

uint8_t motorSpeed = 200;

char val;
int card_length_to_ms(float card_length) {
  return 625*card_length;
}

void setup()
{
  Serial.begin(9600);
  Serial.println("<Arduino is ready>");
  
}

void loop()
{
    val = Serial.read();
    if (val== 'x') { //x is for one dimensional, 1-d motion for/back
      motor2.run(motorSpeed);
      motor1.run(-motorSpeed);
      delay(500); 
      motor2.stop();
      motor1.stop(); 
    }
    else if (val== 'y') { //x is for one dimensional, 1-d motion for/back
 
      motor2.run(-motorSpeed);
      motor1.run(motorSpeed);
      delay(500); 
      motor2.stop();
      motor1.stop(); 
    }
    else if (val== 'q') { //x is for one dimensional, 1-d motion for/back
      motor2.run(-motorSpeed);
      motor1.run(-motorSpeed);
      delay(2200);
      motor2.stop();
      motor1.stop();
      motor2.run(motorSpeed);
      motor1.run(-motorSpeed);
      delay(1000); 
      motor2.stop();
      motor1.stop(); 
    }

    else if (val == 'i') {
      motor3.run(-motorSpeed);
      delay(1500);
      motor3.stop();
      motor3.run(motorSpeed);
      delay(1400);
      motor3.stop();
      motor4.run(motorSpeed);
      delay(1500);
      motor4.stop();
    }

    else if (val == 't') {
      //align();
      motor3.run(-motorSpeed);
      delay(500);
      motor3.stop();
      motor4.run(-motorSpeed);
      delay(1500);
      motor4.stop();
      motor2.run(motorSpeed);
      motor1.run(-motorSpeed);
      delay(1000);
      motor2.stop();
      motor1.stop();

      motor4.run(motorSpeed);
      delay(500);
      motor4.stop();

      motor3.run(motorSpeed);
      delay(1000);
      motor3.stop();
    }
    
    else if (val == 'l') {
      motor2.run(-motorSpeed);
      motor1.run(-motorSpeed);
      delay(500);
      motor2.stop();
      motor1.stop();
    }
    else if (val == 'o') {
      motor2.run(-motorSpeed);
      motor1.run(-motorSpeed);
      delay(2200);
      motor2.stop();
      motor1.stop();
    }

    else if (val == 'r') {
      motor2.run(motorSpeed);
      motor1.run(motorSpeed);
      delay(500);
      motor2.stop();
      motor1.stop();
    }

    else if (val == 'd') {
      motor3.run(-motorSpeed);
      delay(1000);
      motor3.stop();
      motor4.run(-motorSpeed);
      delay(300);
      motor4.stop();
      motor2.run(-motorSpeed);
      motor1.run(motorSpeed);
      delay(1000);
      motor2.stop();
      motor1.stop();
    }

    else if (val == 'p') {


        motor3.run(-motorSpeed);
        delay(500);
        motor3.stop();
        motor3.run(motorSpeed);
        delay(550);
        motor3.stop();
        motor3.run(-motorSpeed);
        delay(500);
        motor3.stop();
        motor3.run(motorSpeed);
        delay(550);
        motor3.stop();
        motor3.run(-motorSpeed);
        delay(500);
        motor3.stop();
        motor3.run(motorSpeed);
        delay(550);
        motor3.stop();

      //reset
      motor3.run(motorSpeed);
      delay(700);
      motor3.stop();
      motor3.run(-motorSpeed);
      delay(600);
      motor3.stop();

     
    }
    else if (val=='z') {
      motor1.stop();
      motor2.stop();
      motor3.stop();
      motor4.stop();
    }


}

