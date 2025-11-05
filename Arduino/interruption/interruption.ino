//interupt.ino

#define FMIN 0.5
#define FMAX 5
#define FOFFS 0.5

const byte bpLessPin = 2;
const byte bpMorePin = 3;
const byte ledPin = 4;

float freq = 1; //1Hz par défaut

bool freqChanged = true;

void setup() {
  
  pinMode(bpLessPin, INPUT);
  pinMode(bpMorePin, INPUT);
  pinMode(ledPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(bpLessPin), less, RISING);
  attachInterrupt(digitalPinToInterrupt(bpMorePin), more, RISING);

  Serial.begin(115200);
  delay(1000);

}

void loop() {
 
  if (freqChanged) {

    Serial.print(freq);
    Serial.write(" Hz\n");
    freqChanged = false;

  }

  digitalWrite(ledPin, 1);
  delay((1/freq)*500);
  digitalWrite(ledPin, 0);
  delay((1/freq)*500);

}

void less() {

  if (freq > FMIN) {

    freq -= FOFFS;
    freqChanged = true;

  }

}

void more() {

  if (freq < FMAX) {

    freq += FOFFS;
    freqChanged = true;

  }

}
