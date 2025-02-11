/**
 @file sender.ino
 @brief Envoie la température sur le port série
*/

void setup() {
  Serial.begin(9600);    
  Serial1.begin(115200);   
}

uint16_t val; // Valeur de la température
double dat; // cast en double

void loop() {

  // Lecture et Conversion 
  val = analogRead(1);
  dat = (double)val * 3.3 / 10.24;

  Serial.println(dat); // terminal
  Serial1.println(dat); // envoie sur le port série

  delay(500);
}