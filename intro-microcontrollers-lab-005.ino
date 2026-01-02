#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define POT_PIN_NUMBER A0

#define OLED_WIDTH_PIXELS  128
#define OLED_HEIGHT_PIXELS 64

#define OLED_I2C_ADDRESS 0x3C

Adafruit_SSD1306 oled;

void setup() {
  // put your setup code here, to run once:

  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(115200);

  oled = Adafruit_SSD1306(OLED_WIDTH_PIXELS, OLED_HEIGHT_PIXELS, &Wire, -1);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDRESS))
  {
    while (true)
    {
      Serial.println("ERROR: Unable to initialize OLED display");
      delay(1000);
    }
  }

  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(WHITE);
  oled.display();
}

void loop() {
  // put your main code here, to run repeatedly:

  uint16_t adcReading = analogRead(POT_PIN_NUMBER);

  Serial.println(adcReading);

  oled.clearDisplay();
  oled.setCursor(50, 20);
  oled.println(adcReading);
  oled.display();
}