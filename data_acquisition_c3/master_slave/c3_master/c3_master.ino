/**
* @file c3_master.ino
* @brief Demande les données à la carte
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

int press = 0;
bool pressed = false;
String temperature;
String tension;

void loop() {

    while(!pressed){
        if(digitalRead(0)==HIGH){ // si on détecte un appui
            pressed = true;

            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Asking...");
            delay(3000);

            Serial1.print(1); // envoie un signal a l'esclave
        }
    }

    if (Serial1.available() > 0) { // si on reçoit des données

        lcd.clear();
        
        // Lecture de la temperature
        temperature = Serial1.readStringUntil(',');
        
        //Affichage temperature
        lcd.setCursor(0,0);
        lcd.print("Temp. :" + temperature + "C");
        Serial.print(temperature.toFloat());Serial.print(",");
        lcd.setCursor(0,1);

        // Lecture de la tension
        tension = Serial1.readStringUntil('\n');
        tension.trim();

        //Affichage tension
        lcd.print("Tension :"+tension+"V");
        Serial.println(tension.toFloat());

        delay(5000);

        // envoie un signal a l'esclave pour refresh les données 
        Serial1.print(1); 
        Serial.println("Asking...");
  }


  // Changement de couleur
  if(digitalRead(0)==HIGH){
    lcd.setColor(RED);
  } else {
    lcd.setColor(GREEN);
  }

}