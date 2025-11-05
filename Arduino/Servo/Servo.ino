#include <rgb_lcd.h>
#include <Servo.h>


// Définitions pour les conversions
#define Kelvin(C) (C + 273.15)
#define Celsius(K) (K - 273.15)

// Configuration des broches et constantes
const byte potPin = A0;
rgb_lcd lcd;

Servo servo;

void setup() {

  lcd.begin(16, 2);  // Initialisation de l'écran LCD
  lcd.setRGB(0, 128, 255);  // Couleur de fond bleue

  servo.attach(8);  //Association du pin 8 au servomoteur

  Serial.begin(9600);

}

void loop() {
  int analogValue = analogRead(potPin);  // Lecture du capteur
  int consigne = analogValue * (180 / 1023.0);  // Conversion en ms de consigne

  if (consigne < 20) consigne = 20;


  // Affichage sur l'écran LCD
  //lcd.setRGB(random(0, 255), random(0, 255), random(0, 255));
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Angle =");
  lcd.print(consigne);
  lcd.print("°");
  lcd.setCursor(0, 1);
  lcd.print("Ton =");
  //lcd.print(temperatureC, 2);
  lcd.print(" ms");

  servo.write(consigne);

  Serial.println(consigne);

  delay(50);
}
