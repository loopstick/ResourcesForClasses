/*
* source code - Ping
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
* http://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
*
*/
// defines pins numbers
const int trigPin = 2;
const int echoPin = 4;
// defines variables
long duration;
int distance;
  // set 3 pins as outputs for RGB LED - use 9, 10, 11 for PWM
  //const int redLEDPin = 11;     // LED connected to digital pin 9
  const int redLEDPin = 9;     // LED connected to digital pin 9
  const int greenLEDPin = 10;    // LED connected to digital pin 10
  const int blueLEDPin = 11;    // LED connected to digital pin 11
  int brightness = 0;    // how bright the LED is
  int redBrightness = 0;
  int greenBrightness = 255;  // 255 = 0 for common cathode RGB led
  int blueBrightness = 0;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  // set 3 pins as outputs for RGB LED - use 9, 10, 11 for PWM
  pinMode(greenLEDPin,OUTPUT);
  pinMode(redLEDPin,OUTPUT);
  pinMode(blueLEDPin,OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
Serial.print("Duration: ");
Serial.print(duration);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("\t Distance: ");
Serial.print(distance);
delay(10);

constrain(distance, 0, 200);
redBrightness = map(distance, 200, 0, 0, 255);
// set the brightness of RED - pin 9:
  analogWrite(redLEDPin, redBrightness);
  Serial.print("\t redBrightness: ");
  Serial.print(redBrightness);  

// set the brightness of Green - pin 10:
  analogWrite(greenLEDPin, greenBrightness); 
   // delay(30); 
   //Serial.print("\t greenBrightness - ");
   //Serial.print(greenBrightness);

blueBrightness = map(distance, 200, 0, 255, 0);
   // blueBrightness = distance/2;  // werks - something slightly different
// set the brightness of BLUE - pin 11:
  analogWrite(blueLEDPin, blueBrightness); 
    //delay(30); 
  Serial.print("\t blueBrightness: ");
  Serial.println(blueBrightness);

  


}
