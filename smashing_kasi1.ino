int pinR = 9;
int pinG = 10;
int pinB = 11;

void setup() {
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
}

void loop() {
  for (int r = 0; r <= 255; r += 10) {
    for (int g = 0; g <= 255; g += 20) {
      for (int b = 0; b <= 255; b += 40) {
		analogWrite(pinR, r);
        analogWrite(pinG, g);
        analogWrite(pinB, b);
        delay(50);
      }
    }
  }
}
