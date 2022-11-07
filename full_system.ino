const int dirPin1 = 2;
const int stepPin1 = 3;
const int dirPin2 = 5;
const int stepPin2 = 6;
const int laser_pin = 8;
const int speaker_pin = 9;
const int stepsPerRevolution = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(laser_pin, OUTPUT);
  digitalWrite(laser_pin,HIGH);
  pinMode(speaker_pin, OUTPUT);
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Set motor direction clockwise
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);
  
  // Spin motor slowly
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    // Speaker test
    //tone(speaker_pin, 10000);
    //delayMicroseconds(1000);
    //noTone(speaker_pin);

    // Motor 1
    digitalWrite(stepPin1, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin1, LOW);
    delayMicroseconds(2000);

    // Motor 2
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(2000);
  }
  delay(1000); // Wait a second
  
 
  
  
}
