const int buttonPin = 0;  
const int led = LED_BUILTIN;  

int counter = 0;
bool buttonPressed = false;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    digitalWrite(led, HIGH);
    if (!buttonPressed) {
      counter++;
      //debounce
      delay(10);
      Serial.println(counter);
      buttonPressed = true;
    }
  } else {
    digitalWrite(led, LOW);
    buttonPressed = false;
  }
}