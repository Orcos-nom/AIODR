// code is for using 2 dc motors 
// code for 1 MG995 servo motors 360deg


#include <BluetoothSerial.h>
#include <ESP32Servo.h>

//servo motor
Servo myservo;
int pos;

// Define motor control pins
const int motorA1 = 33; // IN1
const int motorA2 = 25; // IN2
const int motorB1 = 26; // IN3
const int motorB2 = 27; // IN4

// Define Bluetooth serial object
BluetoothSerial SerialBT;

void setup() {
  // Initialize motor control pins as output
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  myservo.attach(15);
  myservo.write(90);

  // Initialize Bluetooth serial
  SerialBT.begin("AIODR1"); // Set Bluetooth device name
  Serial.begin(115200);

  Serial.println("Bluetooth device started, waiting for connections...");
}

void loop() {
  // Check for incoming Bluetooth data
  if (SerialBT.available()>0) 
  {
    char command = SerialBT.read();
    Serial.println(command);

    // Move Forward
    if (command == 'F') 
    {
      moveForward();
    }
    // Move Backward
    else if (command == 'B') 
    {
      moveBackward();
    }
    // Turn Left
    else if (command == 'L') 
    {
      turnLeft();
    }
    // Turn Right
    else if (command == 'R') 
    {
      turnRight();
    }
    // Stop
    else if (command == 'S') 
    {
      stopMotors();
    }
    //up
    else if (command == 'u')
    {
      up();
    }
    //down
    else if (command == 'd'){
      down();
    }
    //center
    else if (command == 'c'){
      center();
    }
  }
}

void turnLeft() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void turnRight() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void moveBackward() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void moveForward() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void stopMotors() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}

void down()
{
 for(pos=90; pos<=135;pos++);
 myservo.write(pos);
 delay(1000);
}

void up()
{
 for(pos=90;pos>=45;pos--);
 myservo.write(pos);
 delay(1000);
}


void center()
{
 if(pos>90)
 {
  myservo.write(90);
  delay(100);
 }
 else if(pos<90)
 {
  myservo.write(90);
  delay(100);
 }
}
