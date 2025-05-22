#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Constants
//required variables
int prev = 0, stepCount = 0;
unsigned long previousMillis = 0;
const long interval = 1000;
unsigned long currentMillis;
float v, vout, vin; //variabls for calculating voltage
// Initialize the LCD, set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
// Initialize serial communication
Serial.begin(9600);
pinMode(8,OUTPUT);//led indication
// Initialize the LCD
lcd.init();
lcd.backlight();
// Print a message to the LCD
lcd.print( FOOT STEP POWER );
lcd.setCursor(0, 1);
lcd.print( GENERATOR );
delay(2000);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print( STEP COUNT: );
lcd.setCursor(0, 1);
lcd.print( VOLTAGE: );
}
void loop() {
v = analogRead(A0);
currentMillis = millis(); //calculating time
if (v != 0 and (prev == 0)) {
stepCount += 1; // calculating steps
digitalWrite(8, HIGH); //led indication
lcd.setCursor(12, 0);
lcd.print(stepCount);
} else {
if (currentMillis - previousMillis >= 100) {
previousMillis = currentMillis; //time in milliseconds
digitalWrite(8, LOW);
}
}
prev = v;
lcd.setCursor(9, 1);
//calculation of voltage
vout = (v * 5.00) / 1024.00;
vin = (vout / 0.040909)*100;
lcd.print(vin);
lcd.print( mV );
delay(200);
}
