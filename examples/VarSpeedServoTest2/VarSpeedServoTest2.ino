#include <Arduino.h>
#include <VarSpeedServo.h> 


VarSpeedServo servo1;
VarSpeedServo servo2;

void setup() {
  Serial.begin(9600);

  servo1.attach(9);
  servo2.attach(8);

  test2();

}

void test2() {

  int S1 = 0;
  int S2 = 90;
  int max = 5;

  Serial.println("t0 - direct test");
  delay(1000);
  servo1.write(S1);
  delay(1000);
  servo1.write(S2);
  delay(2000);


  Serial.println("t1 - full direct");
  for (int var = 0; var <= max; ++var) {
      int sleep = 200;
      servo1.write(S1);
      delay(sleep);
      servo1.write(S2);
      delay(sleep);
  }

  delay(1000);
  Serial.println("t2 - speed 255 - wait");
  for (int var = 0; var <= max; ++var) {
      int sleep = 10 * (max - var);
      Serial.println(sleep);
      servo1.write(S1, 255);
      servo1.wait();
      delay(sleep);
      servo1.write(S2, 255);
      servo1.wait();
      delay(sleep);
  }

  delay(1000);
  Serial.println("t3 - speed 200 - wait");

  for (int var = 0; var <= max; ++var) {
      int sleep = 10 * (max - var);
      Serial.println(sleep);
      servo1.write(S1, 200);
      servo1.wait();
      delay(sleep);
      servo1.write(S2, 200);
      servo1.wait();
      delay(sleep);
  }

  delay(1000);
  Serial.println("t4 - speed 255 - sleep - waitAndDetach");

  for (int var = 0; var <= max; ++var) {
      int sleep = 10 * (max - var);
      Serial.println(sleep);
      servo1.write(S1, 255);
      servo1.waitAndDetach();
      delay(sleep);
      servo1.write(S2, 255);
      servo1.waitAndDetach();
      delay(sleep);
  }


  delay(1000);
  Serial.println("t5 - speed 255 - wait inline");
  for (int var = 0; var <= max; ++var) {
      Serial.println(var);
      servo1.write(S1, 255, true);
      servo1.write(S2, 255, true);
  }

  delay(1000);
  Serial.println("t6 - speed 255 - waitAndDetach");

  for (int var = 0; var <= max; ++var) {
      Serial.println(var);
      servo1.write(S1, 255);
      servo1.waitAndDetach();
      servo1.write(S2, 255);
      servo1.waitAndDetach();
  }


  delay(1000);
  servo1.detach();

}


void loop() {
}


