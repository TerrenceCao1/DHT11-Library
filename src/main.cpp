#include <Arduino.h>

// put function declarations here:
int sensor=2;
unsigned long lastTime = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);

}


// put function definitions here:
void readsensor(){ 
  unsigned long startTime = millis(); //starttime is the current time the program runs

  //the DHT11 has a max frequency of 1hz (once per second) so we need to make sure that the program only asks data every second
  if ((startTime - lastTime) < 999L){
    return;
  }
  lastTime = startTime; //setting start time you got the data to the last time for future iterations 

  pinMode(sensor, OUTPUT);
  digitalWrite(sensor, LOW); //send a low signal for 18ms to "ensure DHT's detection of MCU's signal"
  delay(18);

  digitalWrite(sensor, HIGH); //pull up to high, and become an input for the DHT to send
  pinMode(sensor, INPUT);

  
}