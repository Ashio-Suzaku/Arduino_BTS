const int potPin = 0;
const int ledPin = 5;

void setup() {

  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);

}

void loop() {

  unsigned n = analogRead(potPin);

  byte rc = map(n, 0, 1024, 0, 255);

  float vmoy = 5.0 * rc / 255;

  Serial.print(n);Serial.print("  ");Serial.println(100*vmoy);  //On donne les valeurs respectivement donnée par le CAN (en bleu sur le Plotter) et la tension moyenne du signal PWM envoyé à la LED en cV (en rouge sur le Plotter)

  analogWrite(ledPin, rc);

  delay(100);

}