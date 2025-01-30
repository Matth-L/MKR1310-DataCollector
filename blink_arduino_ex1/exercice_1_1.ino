void setup() {
  // put your setup code here, to run once:
   pinMode(LED_BUILTIN, OUTPUT);
}

void tempo(int duree)
{
  digitalWrite(LED_BUILTIN,HIGH);
  delay(duree);
  digitalWrite(LED_BUILTIN, LOW);
  delay(duree);
}

void exercice_1()
{

  /**
   * Allumer , éteindre pendant 1 seconde
   */

   /**
    * 1.1 avec delay()
    */

    digitalWrite(LED_BUILTIN,HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);

    /**
     * 1.2 avec une fonction faites soit même nommé tempo(int)
     */

    tempo(1000);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  exercice_1();
}
