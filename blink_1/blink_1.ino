/**
* @file blink_1.ino
* @brief Exercice 1.1
* @details Allumer, éteindre pendant 1 seconde
* 1.1 : avec delay()
* 1.2 : avec tempo()
*/

const int buttonPin = 0;  
const int led = LED_BUILTIN; 

void setup() 
{
  Serial.begin(9600);
  pinMode(led, OUTPUT); // LED_BUILTIN
  pinMode(buttonPin, INPUT); // A0

}

/**
  @brief allume et éteint la LED pendant "x" ms
  @param duree : durée de l'allumage et de l'extinction
*/
void tempo(int duree)
{
  digitalWrite(LED_BUILTIN,HIGH);
  delay(duree);
  digitalWrite(LED_BUILTIN, LOW);
  delay(duree);
}

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


void loop() 
{
  exercice_1_1();
}
