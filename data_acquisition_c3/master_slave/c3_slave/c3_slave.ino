/**
* @file c3_slave.ino
* @brief Envoie les données au MKR après réception d'un signal
*/
void setup() {
  Serial.begin(115200);    
  Serial1.begin(115200);   
}

uint16_t val_temp;
double val_temp_double;
uint16_t val_rot;
double val_rot_double;

void loop() {
  // attente du signal
    while(Serial1.available()>0)
    {
        
        char msgReceived= Serial1.read(); // lecture du signal
        
        // le message a été reçu, on transmet les données
        if(msgReceived)
        {
            // Récupération des valeurs analogiques
            val_temp = analogRead(1);
            val_rot = analogRead(2);
        
            // Conversion des valeurs
            val_temp_double = (double)val_temp * 3.3 / 10.24;
            val_rot_double = (double)val_rot * 3.3 / 1024;
          
            // Affichage sur le terminal et sur la liaison série
            Serial.print(val_temp_double);Serial.print(",");Serial.println(val_rot_double); 
            Serial1.print(val_temp_double);Serial1.print(",");Serial1.println(val_rot_double);     
            msgReceived=NULL;
        }
        
    }
}