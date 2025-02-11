/**
 * @file c3_receiver.ino
 * @brief Recois 2 données de la carte MKR
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

    pinMode(0, INPUT);
}

void loop() {

    if (Serial1.available() > 0) 
    {
      lcd.clear();
      lcd.blink();

      // Lire les données envoyées par la carte 1
      String data = Serial1.readStringUntil('\n');  // Lire jusqu'à un retour à la ligne

      lcd.print(data);
    }

  // Changement de couleur en fonction de l'état du bouton
  if(digitalRead(0)==HIGH){
    lcd.setColor(RED);
  } else {
    lcd.setColor(GREEN);
  }

}