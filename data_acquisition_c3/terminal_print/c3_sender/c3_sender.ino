/**
 * @file c3_sender.ino
 * @brief Envoie 2 données à la carte MKR
*/
void setup() {
  Serial.begin(9600);    
  Serial1.begin(115200);   
}

uint16_t val_temp; // Valeur de la température
double val_temp_double; // cast en double
uint16_t val_rot; // Valeur de la rotation
double val_rot_double; // cast en double

void loop() {
  
  // Récupération des valeurs analogiques
  val_temp = analogRead(1);
  val_rot = analogRead(2);

  // Conversion des valeurs
  val_temp_double = (double)val_temp * 3.3 / 10.24;
  val_rot_double = (double)val_rot * 3.3 / 1024;

  // Affichage sur le terminal et sur la liaison série
  Serial.print(val_temp_double);Serial.print(",");Serial.println(val_rot_double); 
  Serial1.print(val_temp_double);Serial1.print(",");Serial1.println(val_rot_double); 

  delay(500);
}