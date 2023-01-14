#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 26
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors (&oneWire);
const float trigPin = 5;
const float echoPin = 18;
long duration; // variable for the duration of sound wave travel
float distance; // variable for the distance measurement from the ultrasonic to water surface
float temp; //varaible for the temperature
float level; // variable for water level 
void setup() {
 Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  sensors.begin();
  }
void loop() {
 sensors.requestTemperatures();  //send command for readings
  temp = sensors.getTempCByIndex(0);  //we put the valus into the variable defined on the setup
  Serial.print("Temperature: ");
  Serial.println(temp); //print the temperature value on serial monitor
  Serial.println(" C");
  digitalWrite(trigPin, LOW);   // Sets the trigPin low for 10 microseconds
  delayMicroseconds(1500);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1500);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  //calculate the water level by substracting the distance between water and ultrasonic from the total box's height
  level = 25 - distance;
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" cm");
    // Displays the water level on the Serial Monitor
  Serial.print("Height: ");
  Serial.print(level);
  Serial.println(" cm");
  delay(10000);
 
}

