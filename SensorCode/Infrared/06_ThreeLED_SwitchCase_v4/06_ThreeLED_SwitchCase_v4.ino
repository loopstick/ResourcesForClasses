/*
  code original source: ThreeLED_SerialRead.ino and 
  SwitchCase: http://www.arduino.cc/en/Tutorial/SwitchCase

  modified by Dr. Sudhu for 
  3 LED shield with 
  Infrared sensor: pin 2
  aux sensor input: pin 0
*/
// these constants won't change. They are the lowest and highest readings you
// get from your sensor:
const int sensorMin = 0;      // sensor minimum
const int sensorMax = 600;    // sensor maximum, discovered with ThreeLED_SerialRead.ino
const int green = 3; 
const int red = 2;
const int yellow = 4;
int sensorValue = 0;
int range = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Teaching Shield: Infrared Sensor and 3 LEDs");
  Serial.println("ThreeLED_SwitchCase_v4.ino");
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
  
  LEDtest(100);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 2:
 sensorValue = analogRead(A2);
    // print out the value you read:
    Serial.print(sensorValue);
  /*
  // map the sensor range to a range of four options:
  int range = map(sensorValue, sensorMin, sensorMax, 0, 3);
  Serial.println(range);
  */
 if(sensorValue >= 400) {
    range = 3;
  }  
  
  if (sensorValue <= 400 && sensorValue >= 250) {
        range = 2;
  }

  if (sensorValue <= 250 && sensorValue >= 100) {
        range = 1;
  }

  if(sensorValue <= 100) {
    range = 0;
  }  
  
  
  // do something different depending on the range value:
  switch (range) {
    case 0:    
      Serial.println("\t out of range");
      LEDsOff();
      break;
    case 1:    // your hand is in range but far away
      Serial.println("\t far");
      greenOn();
      break;
    case 2:    // your hand is a few inches from the sensor
      Serial.println("\t medium");
      yellowOn();
      break;
    case 3:    // your hand is close to the sensor
      Serial.println("\t close");
      redOn();
      break;
  }
  delay(1);        // delay in between reads for stability
}

void LEDsOff() {
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(yellow,LOW);
}

void redOn() {
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW);
  digitalWrite(yellow,LOW);
}

void greenOn() {
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  digitalWrite(yellow,LOW);
}

void yellowOn() {
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(yellow,HIGH);
}



void LEDtest(int wait) {
  redOn();
  delay(wait);
  LEDsOff();
  delay(wait);
  redOn();
  delay(wait);
  LEDsOff();
  delay(wait);
  redOn();
  delay(wait);
  LEDsOff();
  delay(wait); 
}
