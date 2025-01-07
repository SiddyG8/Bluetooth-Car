#include <Arduino.h>
#include <Dabble.h>

// Motor A connections
const int ENA = 5; // L293D Enable Pin A
const int IN1 = 6; // L293D IN1 Pin
const int IN2 = 7; // L293D IN2 Pin

// Motor B connections
const int ENB = 9; // L293D Enable Pin B
const int IN3 = 10; // L293D IN3 Pin
const int IN4 = 11; // L293D IN4 Pin

// Forward declarations
void moveForward();
void moveBackward();
void rotateClockwise();
void rotateCounterClockwise();
void stopMoving();

void setup()
{
    // Initialize Serial Monitor and HM-10 communication
    Serial.begin(9600);
    Dabble.begin(9600);

    Serial.println("Comms begin");

    // Outputs
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    // Start pins in LOW state
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, LOW);
    analogWrite(ENB, LOW);
}

void loop()
{
    // Process incoming data from Dabble
    Dabble.processInput();

    // GamePad controls
    if (GamePad.isUpPressed())
    {
        moveForward();
    }
    else if (GamePad.isDownPressed())
    {
        moveBackward();
    }
    else if (GamePad.isLeftPressed())
    {
        rotateCounterClockwise();
    }
    else if (GamePad.isRightPressed())
    {
        rotateClockwise();
    }
    else
    {
        stopMoving();
    }
}

void rotateClockwise()
{
    // Rotate motor A clockwise
    analogWrite(ENA, 255);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    // Rotate motor B counter-clockwise
    analogWrite(ENB, 255);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void rotateCounterClockwise()
{
    // Rotate motor A counter-clockwise
    analogWrite(ENA, 255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    // Rotate motor B clockwise
    analogWrite(ENB, 255);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void moveForward()
{
    // Rotate motor A clockwise
    analogWrite(ENA, 255);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    // Rotate motor B clockwise
    analogWrite(ENB, 255);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void moveBackward()
{
    // Rotate motor A counter-clockwise
    analogWrite(ENA, 255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    // Rotate motor B counter-clockwise
    analogWrite(ENB, 255);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void stopMoving()
{
    // Stop Rotating the Motors
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}
