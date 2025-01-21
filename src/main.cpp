#include <Arduino.h>

// put function declarations here:
int pin=2;
unsigned long lastTime = 0;
void readpin();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  readpin();
}


void readpin(){ 
  unsigned long startTime = millis(); //starttime is the current time the program runs

  //the DHT11 has a max frequency of 1hz (once per second) so we need to make sure that the program only asks data every second
  if ((startTime - lastTime) < 999L){
    return;
  }
  lastTime = startTime; //setting start time you got the data to the last time for future iterations 

  //5.2 - Arduino sends start signal to DHT
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW); //send a low signal for 18ms to "ensure DHT's detection of MCU's signal"
  delay(18);

  digitalWrite(pin, HIGH); //pull up to high, and become an input for the DHT to send
  pinMode(pin, INPUT);

  //for each bit, drops 50us to start to transmit
  //then 26-28us high voltage means a 0
  //and 70us high voltage means a 1
  //us = microseconds = 10^-6 seconds
  
  //for each bit of information (83 total)
  for (int i = 0; i < 83; i++){
    unsigned int elapsedTime; //The length of time the voltage increases (determining value of bit)
    startTime = micros();
  }

}