const int analogInPin = A0; // Analog input pin that the pH sensor is attached to
const int led1Pin = 2; // Digital output pin for LED1
const int led2Pin = 3; // Digital output pin for LED2
float sensorValue = 0; // Variable to store the sensor value
float pH = 0; // Variable to store the calculated pH value

void setup() {
  pinMode(led1Pin, OUTPUT); // Set LED1 pin as output
  pinMode(led2Pin, OUTPUT); // Set LED2 pin as output
  Serial.begin(9600); // Start serial communication at 9600 bps
}

void loop() {
  // Read the sensor value
  sensorValue = analogRead(analogInPin);

  // Convert the sensor value to pH using the formula for the pH sensor you're using
  // For example, if you're using a SEN0161 pH sensor, you would use the following formula:
  pH = 7 - (sensorValue * 5 / 1024.0);

  // Print the pH value to the serial monitor
  Serial.print("pH: ");
  Serial.println(pH);

  // Control the LEDs based on the pH value
  if (pH >= 5.5) {
    digitalWrite(led1Pin, HIGH); // Turn on LED1
    delay(100); // Wait for 0.1 second
    digitalWrite(led1Pin, LOW); // Turn off LED1
    delay(100); // Wait for 0.1 second
  } else {
    digitalWrite(led2Pin, HIGH); // Turn on LED2
    delay(100); // Wait for 0.1 second
    digitalWrite(led2Pin, LOW); // Turn off LED2
    delay(100); // Wait for 0.1 second
  }

  delay(1000); // Wait for 1 second before taking another reading
}
