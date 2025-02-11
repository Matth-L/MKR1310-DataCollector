/**
* @file receiver.ino
* @brief Recois les données de la carte 1
*/

void setup() {

  // Initialisation de la liaison série
  Serial.begin(9600);  
  Serial1.begin(115200);

  // Attente de la connexion à la liaison série )
  while (!Serial && !Serial1);     

  Serial.println("Prêt à recevoir les données ...");

}

void loop() {
  if (Serial1.available() > 0) {
    // Lire les données envoyées par la carte 1 jusqu'a '\n' (retour à la ligne)
    String data = Serial1.readStringUntil('\n');  
    
    Serial.println(data);
  }
}