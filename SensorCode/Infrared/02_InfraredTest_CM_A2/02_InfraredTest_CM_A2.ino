/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A2);

  // do maths to convert the raw sensor value into a distance in centimeters
  float distance = 12343.85 * pow(analogRead(sensorValue),-1.15);
  
      // print out the value you read:
      Serial.print("sensorValue: ");
      Serial.print(sensorValue);
      Serial.print("\t distance: ");
      Serial.print(distance);
      Serial.println("centimeters");

  delay(10);        // delay in between reads for stability
}
