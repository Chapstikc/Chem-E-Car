// NOTE: This code was tested using an Arduino UNO with a 12v motor running on 6v. Changes to integer inputs may be necessary for different boards and voltages.

// Define constants for pins
const int lightSensorPin = A0;
const int motorPin = 9;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set motor pin as an output
  pinMode(motorPin, OUTPUT);

    // Run the motor at full speed for 0.1 seconds. This gives the motor a nice boost in case you're running it at a low voltage and your tourqe is low.
    // Comment out the code 4 lines of code bellow if the boost is not necessary.
  digitalWrite(motorPin, HIGH);
  analogWrite(motorPin, 1023); // The value adjusts the speed of the motor, max 1023
  delay(100);
  digitalWrite(motorPin, HIGH);
}

void loop() {
  // Read the value from the light sensor
  int lightValue = analogRead(lightSensorPin);
  
  // Print the light value to the serial monitor
  Serial.print("Light value: ");
  Serial.println(lightValue);
  
  // Check if light is detected
  if (lightValue < 500) { // Adjust this threshold according to your sensor and environment.
    // If light is detected, turn on the motor
    digitalWrite(motorPin, HIGH);
    analogWrite(motorPin, 400); // The value adjusts the speed of the motor, max 1023, 90 was used previously. 350 also works great.
    Serial.println("Light detected! Motor turned on."); 
  } else {
    // If light is not detected, turn off the motor
    digitalWrite(motorPin, LOW);
    Serial.println("No light detected. Motor turned off.");
  }
  
  // Delay for a short duration to avoid rapid readings
  delay(100); // Adjust this delay as needed
}
