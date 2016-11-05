
/*
   Watering System (c) 2016 Henry Jeynes www.henryjeynes.com

   Designed for the Hydro Mk I board with an ATmega88 running
   at 1MHz. Low speed allows lower power consumption, and
   it is plenty fast enough to run this code properly.

   This sketch currently works on any micro with 4K of
   program space, but 8K is recommended for updates. A light
   version will be available later on for micros with 2k or
   less program space.

   If you are just using a Hydro Mk I, you can just upload
   this code without making any changes.

   This code is unpolished and unfinished, and it is missing
   features like low-power mode and settings stored in
   EEPROM. These will be added later on. If you have any
   idea how to add these features, email me at
   henry.j.biz@gmail.com

   For more info, go to www.henryjeynes.com/projects/hydromki
*/

//TODO: add sleep code for low-power operation



#include "config.h" //configuration file so settings are easier to change
#include "pindefs.h" //pin definiton file

void setup() {

  pinMode(RS1, INPUT_PULLUP); //enable internal pullup resistor, so no external pullup is required
  pinMode(RS2, INPUT_PULLUP); //change to INPUT if an external pullup is used
  pinMode(L, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(PUMP1, OUTPUT);
  pinMode(PUMP2, OUTPUT);

  Serial.begin(9600); //this can also be set to 57600, 115200, etc. but 9600 baud should be enough

  if (digitalRead(RS1) == 0 && digitalRead(RS2) == 0) {
    //do nothing
  }
  digitalWrite(PUMP1, HIGH);
  digitalWrite(PUMP2, HIGH);
}

void loop() {

  if ((analogRead(S1) <= s1_thr) && (analogRead(S2) <=  s2_thr)) { //TODO: set up code for two pumps. current code uses one pump for both plants
    digitalWrite(PUMP1, HIGH);
    digitalWrite(PUMP2, HIGH);
    delay(wateringTime + pump1RiseTime); //rise time plus actual watering time
    digitalWrite(PUMP1, LOW);
    digitalWrite(PUMP2, LOW);
    delay(1000);
  }

  while ((digitalRead(RS1) == 0) && (digitalRead(RS2) == 1)) { //read sensor 1 by holding down button 1
    analogWrite(L1, analogRead(S1));
    Serial.println("S1 value:");
    Serial.println(analogRead(S1));
    delay(10);
    digitalWrite(L1, LOW);
  }

  while ((digitalRead(RS1) == 1) && (digitalRead(RS2) == 0)) { //read sensor 2 by holding down button 2
    analogWrite(L2, analogRead(S2));
    Serial.println("S2 value:");
    Serial.println(analogRead(S2));
    delay(10);
    digitalWrite(L2, LOW);
  }

  while ((digitalRead(RS1) == 0) && (digitalRead(RS2) == 0)) { //force watering by holding both buttons
    digitalWrite(PUMP1, LOW);
    digitalWrite(PUMP2, LOW);
    pumpStatus = 1;
  }

  if (pumpStatus == 1) {
    digitalWrite(PUMP1, HIGH);
    digitalWrite(PUMP2, HIGH);
    pumpStatus = 0;
  }
  idleBlink(); //blink to indicate "standby". replace this with actual sleep code later
}

void idleBlink() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (ledState == LOW) {
      ledState = HIGH;
    }
    else {
      ledState = LOW;
    }
    digitalWrite(L, ledState);
  }
}

