/*
   Watering System (c) 2016 Henry Jeynes www.henryjeynes.com

   This is the config file. You should experiment with the
   values shown here to properly water your plant.

*/

//moisture sensor thresholds
int s1_thr = 0; //change these for different plants.
int s2_thr = 0; //if you are only using one sensor, set this to 1023

//pump settings
int wateringTime = 5000; //automatic watering time
int pump1RiseTime = 1000; //measure this for your own pump
int pump2RiseTime = 1000; //set to 1 sec default, probably needs to be changed

//blink times
int actBlinkOnTime = 50; //activity blink on time
int actBlinkOffTime = 50; //activity blink off time
int idleBlinkOnTime = 100;
int idleBlinkOffTime = 1900;
const long onInterval = 100;
const long offInterval = 1900;


//don't change these
int pumpStatus;
int incomingByte; //incoming serial data
int ledState = LOW;
unsigned long previousMillis = 0;
unsigned long nextMillis = 900;
//don't change these


