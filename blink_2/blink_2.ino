/**
* @file blink_2.ino
* @brief Exercice 1.2
* @details Allumer, éteindre avec un bouton
*/

const int buttonPin = 0;
const int led = LED_BUILTIN;

bool buttonPressed = false;
int counter = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(led, OUTPUT); // LED_BUILTIN
  pinMode(buttonPin, INPUT); // A0

}

void exercice_1_2() {
  if (digitalRead(buttonPin) == HIGH) {
    digitalWrite(led, HIGH);
    if (!buttonPressed) {
      counter++;
      // debounce
      delay(50);
      Serial.println(counter);
      buttonPressed = true;
    }
  } else {
    digitalWrite(led, LOW);
    buttonPressed = false;
  }
}

void loop() 
{
  exercice_1_2();
}