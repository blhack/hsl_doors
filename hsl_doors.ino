/*
 This sketch is heavily based on one by Cristian Maglie.
*/

#include <Process.h>
#include <LiquidCrystal.h>
#include <String>
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);


int switchpin = 2;
int old_switchstate = 0;
int switchstate = 0;

void setup() {
  Bridge.begin();	// Initialize the Bridge
  Serial.begin(9600);	// Initialize the Serial
    lcd.begin(16, 2);
  lcd.print("SHIT I FUCKED UP");


  // Wait until a Serial Monitor is connected.
  //while(!Serial);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  switchstate = digitalRead(switchpin);
  old_switchstate = switchstate;
  Serial.println("Waking up");
}

void strobe() {
  Serial.println("Strobing for 5 sec");
  for (int i = 0; i<=20; i++) {
    digitalWrite(3, HIGH);
    delay(100);
    digitalWrite(3, LOW);
    delay(100);
  }
  for (int i = 255; i>=0; i--) {
    analogWrite(3, i);
    delay(3);
  }
}
    

void loop() {
    
  switchstate = digitalRead(2);
  if (switchstate != old_switchstate) {
    if (switchstate == 0) {
      Serial.println("Open!");
      
      Process p;
      p.runShellCommand("/usr/sbin/awesome");
      while(p.running());
      strobe();
      lcd.begin(16,2);
      lcd.print("Open 4 Hax");
      
    }
    if (switchstate == 1) {
      Serial.println("Closed!");
      Process p;
      p.runShellCommand("/usr/sbin/notsome");
      while(p.running());
      strobe();
      lcd.begin(16,2);
      lcd.print("CLOSED 4 RELAX");
    }
    old_switchstate = switchstate;
   }
   Serial.println(digitalRead(2));
   delay(100);
}



