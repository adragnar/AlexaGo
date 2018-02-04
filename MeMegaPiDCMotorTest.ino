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
    
    if (val == 'w') {
      motor2.run(motorSpeed);
      motor1.run(-motorSpeed);
      delay(1000);
      motor2.stop();
      motor1.stop();
    }
    else if (val == 's') {
      motor2.run(-motorSpeed);
      motor1.run(motorSpeed);
      delay(1000);
      motor2.stop();
      motor1.stop();
    }
    else if (val == 'a') {
      motor2.run(-motorSpeed);
      motor1.run(-motorSpeed);
      delay(1000);
      motor2.stop();
      motor1.stop();
    }
    else if (val == 'd') {
      motor2.run(motorSpeed);
      motor1.run(motorSpeed);
      delay(1000);
      motor2.stop();
      motor1.stop();
    }
    else if (val == 'q') {
      motor3.run(-motorSpeed);
      delay(500);
      motor3.stop();
      motor4.run(-200);
      delay(5000);
      motor4.stop();
    }
    else if (val == 'e') {
      motor3.run(motorSpeed);
      delay(500);
      motor3.stop();
      motor4.run(200);
      delay(5000);
      motor4.stop();
    }  

    else if (val == 'p') { 
      motor2.run(motorSpeed);
      motor1.run(-motorSpeed);
      delay(1000);
      motor2.stop();
      motor1.stop();
      motor3.run(-motorSpeed);
      //delay(card_length_to_ms())
      
    }
    else if (val == 't') {
        align();
        motor3.run(-motorSpeed);
        delay(1200);
        motor3.stop();

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
      
//      motor4.stop();
//      motor3.run(-motorSpeed);
//      delay(500);
//      motor3.stop();
//      motor4.run(motorSpeed);
//      delay(1000);      
//      motor4.stop();
//      motor3.run(motorSpeed);
//      delay(1000);
//      motor3.stop();
      
    }
    else if (val == 'i') {
      motor3.run(motorSpeed);
      delay(2000);
      motor3.stop();
      motor4.run(-motorSpeed);
      delay(1500)
      motor4.stop();
    }
}

void align()
{
  while(imageNotCentred){
    //keep spinning
    if(centred){
      break;
    }
  }
}

