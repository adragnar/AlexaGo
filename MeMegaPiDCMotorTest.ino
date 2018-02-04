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

int process_input_time (int amount_for) {
  if (amount_for < 0) {
        amount_for = -1*amount_for;
  }
  return amount_for;
}

void setup()
{
  Serial.begin(9600);
  Serial.println("<Arduino is ready>");
  
}

void loop()
{
    val = Serial.read();

    if (val== 'y') { //y is for one dimensional, 1-d motion for/back
      int amount_for = Serial.read(); 
      amount_for = process_input_time(amount_for);
      motor2.run(motorSpeed);
      motor1.run(-motorSpeed);
      delay(amount_for); 
      motor2.stop();
      motor1.stop(); 
    }

    if (val == 'i') {
      motor3.run(motorSpeed);
      delay(2000);
      motor3.stop();
      motor4.run(-motorSpeed);
      delay(1500);
      motor4.stop();
    }

    if (val == 't') {
      //align();
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
    }
    
    if (val == 'l') {
      int amount_for = Serial.read(); 
      amount_for = process_input_time(amount_for);
      motor2.run(-motorSpeed);
      motor1.run(-motorSpeed);
      delay(amount_for);
      motor2.stop();
      motor1.stop();
    }

    if (val == 'r') {
      int amount_for = Serial.read(); 
      amount_for = process_input_time(amount_for);
      motor2.run(motorSpeed);
      motor1.run(motorSpeed);
      delay(amount_for);
      motor2.stop();
      motor1.stop();
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


}
