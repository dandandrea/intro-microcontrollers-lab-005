#define LED_PIN_NUMBER 8
#define POT_PIN_NUMBER A0

void setup() {
  // put your setup code here, to run once:

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_PIN_NUMBER, OUTPUT);

  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LED_PIN_NUMBER, LOW);

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  uint16_t adcReading = analogRead(POT_PIN_NUMBER);

  Serial.println(adcReading);

  digitalWrite(LED_PIN_NUMBER, HIGH);
  delay(100);

  digitalWrite(LED_PIN_NUMBER, LOW);
  delay(100 + (1023 - adcReading));
}
