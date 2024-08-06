/*
 * Interface LDR with NodeMCU
 * By TheCircuit
 */
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;
const int ldrPin = A0;

void setup() {

  lcd.begin();
  lcd.backlight();
Serial.begin(9600);

pinMode(ldrPin, INPUT);

servo.attach(2); //D4
servo.write(0);

delay(2000);
}

void loop() {
int ldrStatus = analogRead(ldrPin);

if (ldrStatus >= 200) {

servo.write(0);
delay(1000);

  lcd.begin();
  lcd.setCursor(0, 0); 
  lcd.print("Close"); 

}

else {

servo.write(90);
delay(1000);
  lcd.begin();
  lcd.setCursor(0, 0); 
  lcd.print(""); 
  lcd.print("open"); 


}

}
