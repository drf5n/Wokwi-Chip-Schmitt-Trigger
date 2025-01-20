// Schmitt Trigger demonstration
// 
// https://wokwi.com/projects/411421086186465281
// 
// Built from https://wokwi.com/projects/411407134995176449
//
// Using https://github.com/drf5n/Wokwi-Chip-Schmitt-Trigger

const byte analogPin = A0;
const byte digitalPin = 3;
const byte digitalPinUnfiltered = 7;
const double Vcc = 5.0;

#include <Wire.h>
#include <hd44780.h> // #include <hd44780ioClass/hd44780_I2Cexp.h> // i2c LCD i/o class header
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2c LCD i/o class header
hd44780_I2Cexp lcd;

void setup()
{
  Serial.begin(115200);
  lcd.begin(20, 4);
  lcd.setCursor(0, 0);
  lcd.print("Schmitt Trigger Test");
  pinMode(analogPin, INPUT);
  pinMode(digitalPin, INPUT);
  pinMode(digitalPinUnfiltered, INPUT);
}

void loop()
{
  int pot = analogRead(analogPin);
  int trigger = digitalRead(digitalPin);
  int unfiltered = digitalRead(digitalPinUnfiltered);
  static int lastPot = -1, lastTrigger = -1;
  static float highvolts, lowvolts;

  if (pot != lastPot) {
    lcd.setCursor(0, 1);
    lcd.print("");
    lcd.print(unfiltered);
    lcd.print("->");
    lcd.print(trigger);
    lcd.print(" ");
    lcd.print(pot);
    lcd.print(" ");
    lastPot = pot;
  }

  if (trigger != lastTrigger) {
    if (trigger == LOW) {
      highvolts = volts(pot);
      lcd.setCursor(0, 3);
      lcd.print("Low:  ");
      lcd.print(pot);
      lcd.print("cnt:");
      lcd.print(highvolts, 3);
      lcd.print("V ");
    } else {
      lowvolts = volts(pot);
      lcd.setCursor(0, 2);
      lcd.print("High: ");
      lcd.print(pot);
      lcd.print("cnt:");
      lcd.print(lowvolts, 3);
      lcd.print("V ");
    }
    lcd.setCursor(13, 1);
    lcd.print((highvolts + lowvolts) / 2, 3);
    lcd.print("V ");
    lastTrigger = trigger;
  }
}

double volts(int pot) {
  return Vcc * (pot + 0.5) / 1024;
}
