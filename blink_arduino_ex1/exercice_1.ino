const int buttonPin = 0;  
const int led = LED_BUILTIN;  

int counter = 0;
bool buttonPressed = false;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void tempo(int duree)
{
  digitalWrite(LED_BUILTIN,HIGH);
  delay(duree);
  digitalWrite(LED_BUILTIN, LOW);
  delay(duree);
}

/**
 * Allumer , éteindre pendant 1 seconde
*/
void exercice_1_1()
{
    //1.1 : avec delay()
    digitalWrite(LED_BUILTIN,HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
    //1.2 : avec tempo()
    tempo(1000);
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
  // exercice_1_1();
  // exercice_1_2();
}
