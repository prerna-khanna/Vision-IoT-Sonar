String val;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {  
  Serial.begin(9600);  
  lcd.begin(16, 2);
 
}

void loop() {
  lcd.clear();
  val = Serial.readString(); 
  delay(1000);  
  Serial.println(val);
  delay(10);

  lcd.print(val);
  lcd.display();
 // delay(5000000);
}
