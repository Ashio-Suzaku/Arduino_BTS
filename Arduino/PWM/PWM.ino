const int potPin = 0;
const int ledPin = 5;

void setup() {

  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);

}

void loop() {

  unsigned n = analogRead(potPin);

  byte rc = map(n, 0, 1024, 0, 255);  //"conversion" de la valeur renvoyée par le CAN, allant de 0 à 1024, en valeur sur un octet, allant de 0 à 255

  float vmoy = 5.0 * rc / 255;  //Calcul de la valeur moyenne de la tension

  Serial.print(n);
  Serial.print("  ");
  Serial.println(100*vmoy);  //On donne les valeurs respectivement donnée par le CAN (en bleu sur le Plotter) et la tension moyenne du signal PWM envoyé à la LED en cV (en rouge sur le Plotter)

  analogWrite(ledPin, rc);  //Ecriture de la valeur rc sur le pin de la LED

  delay(100);

}
