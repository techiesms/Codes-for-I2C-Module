#include <LiquidCrystal_I2C.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


int lcdColumns = 16;
int lcdRows = 2;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  delay(2000);


  lcd.init();
  // turn on LCD backlight
  lcd.backlight();
}

void loop()
{
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Hello, ");
  lcd.setCursor(0, 1);
   lcd.print("From LCD ");
  delay(1000);
  // clears the display to print new message
  lcd.clear();

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Hello,From OLED");
  display.display();
  delay(1000);
  display.clearDisplay();
  display.display();
}
