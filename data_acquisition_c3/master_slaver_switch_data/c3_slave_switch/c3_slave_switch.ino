/**
* @file c3_slave_switch.ino
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
int count=0;

void loop() {
    while(Serial1.available()>0){ 

        char msgReceived= Serial1.read();
            
        if(msgReceived){

            // en fonction de la parité de count,
            // on envoie soit la température soit la rotation
            count = (count +1) %2 ;

            if(count){

                // lecture et conversion de la température
                val_temp = analogRead(1);
                val_temp_double = (double)val_temp * 3.3 / 10.24;

                // envoi de la température
                Serial1.print(val_temp_double);
                Serial.print(val_temp_double);
            }
            else{

                // lecture et conversion de la rotation
                val_rot = analogRead(2);
                val_rot_double = (double)val_rot * 3.3 / 1024;

                // envoi de la rotation
                Serial1.print(val_rot_double);
                Serial.print(val_rot_double);
            }
            msgReceived=NULL; // on remet le message à NULL
        }
        
      
    }
}