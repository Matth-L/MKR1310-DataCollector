/**
  * @file c2_sender.ino
  * @brief Recois les donnees d'un autre MKR
*/

#include "DFRobot_RGBLCD1602.h"

//16 characters and 2 lines of show
DFRobot_RGBLCD1602 lcd(/*RGBAddr*/0x60 ,/*lcdCols*/16,/*lcdRows*/2);  

void setup() {
    Serial.begin(115200);
    Serial1.begin(115200);

    /**
     *  @brief initialize the LCD and master IIC
     */ 
    lcd.init();

    // Print a message to the LCD.
    lcd.print("Ready");
    lcd.setColor(WHITE);
}

void loop() {
    if (Serial1.available() > 0) {

        lcd.clear(); // Effacer l'écran
        lcd.blink(); // Clignotement 

        // Lecture des données envoyées par la carte 1
        String data = Serial1.readStringUntil('\n');

        lcd.print(data);
  }
}