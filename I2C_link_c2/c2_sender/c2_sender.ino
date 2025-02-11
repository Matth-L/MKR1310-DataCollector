/**
  * @file c2_sender.ino
  * @brief Envoie un message à un autre MKR
*/

String sendMessage;

void setup() {
  Serial.begin(115200);    
  Serial1.begin(115200);   
}

void loop() {
  if (Serial.available() > 0) {
    char inputChar = Serial.read();

    if (inputChar == '\n') 
    {
      // Affichage du message
      Serial1.print(sendMessage);  
      // Reset du message
      sendMessage = "";  
    } 
    else 
    {
      sendMessage += inputChar;  // ajout à la fin du message
    }
    
  }
}