#include <Servo.h>
Servo sr, sl;
void setup() {
  Serial.begin(9600);
  sr.attach(12);
  sl.attach(13);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);
}
void loop() {
  if (Serial.available()) {
    char b[3];
    int p, r, engine;

    Serial.readBytes(b, 3);
    p = b[0] * 3;
    r = b[1];
    engine = b[2];

    if(engine == 1) {
      onStart();
      if(p == 0 && r == 0) 
        onStop();
    }
    sr.write(1500 + p - r);
    sl.write(1500 - p - r);

    Serial.write('1');
  }
}

void onStart(){
  tone(2, 262, 500);
}

void onStop(){
  digitalWrite(4, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(10, HIGH);
  tone(2, 523, 1000);
  delay(500);
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  digitalWrite(10, LOW);
  tone(2, 262, 1000);
  delay(500);
}
