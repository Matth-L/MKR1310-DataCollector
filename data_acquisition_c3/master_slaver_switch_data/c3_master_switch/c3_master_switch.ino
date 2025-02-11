/**
* @file c3_master_switch.ino
* @brief Demande les données à la carte, demande soit la température soit la tension
*/

#include "DFRobot_RGBLCD1602.h"


//16 characters and 2 lines of show
DFRobot_RGBLCD1602 lcd(/*RGBAddr*/0x60 ,/*lcdCols*/16,/*lcdRows*/2);  

/**
 * @brief Affiche "Ready" sur l'écran LCD
 */
void ready()
{
    lcd.print("Ready");
    lcd.blink();
    lcd.setColor(WHITE);
}

/**
 * @brief Affiche "Press button when ready." sur l'écran LCD
 */
void press_when_ready()
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Press button");
    lcd.setCursor(0,1);
    lcd.print("when ready.");
}
void setup() {
    Serial.begin(9600);
    Serial1.begin(115200);

    /**
     *  @brief initialize the LCD and master IIC
     */ 
    lcd.init();

    ready();

    pinMode(0, INPUT);
    delay(5000);

    press_when_ready();
}

bool pressed = false;
int value = 0;
String valeurlue;

void loop() {
  while(!pressed){
    if(digitalRead(0)==HIGH)
    {
      pressed = true;

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Asking...");
      delay(3000);

      Serial1.print(1); // envoie un signal à l'esclave

      // a chaque fois que l'on appui sur le bouton 
      // on incrémente value
      value++; 
    }
  }

  if (Serial1.available() > 0) {

    lcd.clear();

    // Lire les données envoyées par la carte 1
    lcd.setCursor(0,0);
    valeurlue = Serial1.readStringUntil('\n');

    // Affichage de la température ou de la tension en fonction de la valeur 
    // value est incrémenter a chaque appui
    if(value%2==1){
      lcd.print("Temp. :"+valeurlue+"C");
      Serial.println("Temperature :"+valeurlue+"C");
    } else {
      lcd.print("Tension :"+valeurlue+"V");
      Serial.println("Tension :"+valeurlue+"V");
    }

    delay(5000);
    Serial1.print(1);
    Serial.println("Asking...");
  }

  // Changement de couleur
  if(digitalRead(0)==HIGH){
    lcd.setColor(RED);
    value++;
    lcd.clear();
    lcd.print(Switching...);
    delay(200);
  } else {
    lcd.setColor(GREEN);
  }

}