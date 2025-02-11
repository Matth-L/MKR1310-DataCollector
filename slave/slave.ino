void setup() {
  Serial.begin(115200);    // Initialize the Serial monitor for debugging
  Serial1.begin(115200);   // Initialize Serial1 for sending data
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
          // count c'est soit 0 ou 1, vrai ou faux, si c'est vrai, 
          // alors on donne le temperature, sinon on donne la rotation
          count = (count +1) %2 ; 
          val_temp = analogRead(1);
          val_rot = analogRead(2);
        
          val_temp_double = (double)val_temp * 3.3 / 10.24;
          val_rot_double = (double)val_rot * 3.3 / 1024;

          if(count){
            Serial1.print(val_temp_double);
            Serial.print(val_temp_double);
          }
          else{
            Serial1.print(val_rot_double);
            Serial.print(val_rot_double);
          }
          msgReceived=NULL;
        }
        
      
    }
  }
