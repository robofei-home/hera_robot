#include <Encoder.h>

#define ENCODER_PIN_A 50
#define ENCODER_PIN_B 51

Encoder encoder(ENCODER_PIN_A, ENCODER_PIN_B);

void setup() {
  Serial.begin(9600);
  
  encoder.write(0);
}

void loop() {
  Serial.print("Encoder ticks: ");
  Serial.print(encoder.read());
  Serial.print("\t");

  Serial.print("Encoder channel A: ");
  Serial.print(digitalRead(ENCODER_PIN_A));
  Serial.print("\t");

  Serial.print("Encoder channel B: ");
  Serial.print(digitalRead(ENCODER_PIN_B));
  
  Serial.println("");
  delay(100);
}
