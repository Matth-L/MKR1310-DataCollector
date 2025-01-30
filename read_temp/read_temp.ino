void setup() {
  Serial.begin(9600);
}

void loop() {
  
    // Déclaration des variables
    uint16_t val;
    double dat;

    // Lecture de la valeur analogique sur la broche A0
    val = analogRead(A0);

    // Conversion de la valeur lue en température (plage de 0 à 3.3V)
    dat = (double) val * (3.3 / 10.24);

    Serial.print(dat);
    Serial.println("C");
    delay(500);
}
