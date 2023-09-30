int soilMoisturePin = A0; // Analog pin for soil moisture sensor

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int soilMoistureValue = analogRead(soilMoisturePin); // Read analog value from sensor
  float soilMoisturePercent = map(soilMoistureValue, 0, 1023, 0, 100); // Convert analog value to percentage
  Serial.print("Soil Moisture: ");
  Serial.print(soilMoisturePercent);
  Serial.println("%");
  delay(1000); // Delay for one second before taking next reading
}
