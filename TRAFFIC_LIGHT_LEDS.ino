//CODE BY ItsJeanCoding on GitHub
//Made on January 11, 2021

//The code below executes a simple algorithm on how traffic lights work. Also, this is my first project in Arduino that's why it is pretty simple.
//Happy Coding! :)


//LIBRARIES
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int ctr = 7; //INITIALIZE THE COUNTER THAT WILL BE SEEN ON THE LCD SCREEN
LiquidCrystal_I2C lcd(0x27,16,2);  //SET THE LCD ADDRESS TO 0x27 FOR A 16 CHARS AND 2 LINE DISPLAY

void setup()
{
  lcd.init();  //INIIALIZE THE LCD      
  lcd.backlight(); 
  lcd.print("FOLLOW THE ");
  lcd.setCursor(0, 0);
  lcd.setCursor(0, 1);
  lcd.print("TRAFFIC RULES");
  delay(5000);
  Serial.begin(9600);

  pinMode(2, OUTPUT); //RIGHT LANE, GREEN LIGHT
  pinMode(3, OUTPUT); //RIGHT LANE, YELLOW LIGHT
  pinMode(4, OUTPUT); //RIGHT LANE, RED LIGHT
  
  pinMode(8, OUTPUT);//LEFT LANE, RED LIGHT
  pinMode(9, OUTPUT);//LEFT LANE, YELLOW LIGHT
  pinMode(10, OUTPUT);//LEFT LANE, GREEN LIGHT

}

void loop()
{
  
  // RIGHT LED GREEN (GO) ON FOR 8 SECONDS
  int ctr1 = 0; // THE COUNTER FOR LOOP
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("RIGHT LANE"); 
  lcd.setCursor(0,1);
  lcd.print("GO"); 
  ctr = 7; //THE COUNTER THAT WILL BE SEEN ON THE LCD
  while(ctr>=0){
    digitalWrite(2, HIGH);
    lcd.setCursor(3, 1);
    lcd.print(ctr);
    delay(1000);
    ctr = ctr-1;
    digitalWrite(2, LOW);
  }
  
  // RIGHT LED YELLOW (READY) ON FOR 6 SECONDS
  ctr1 = 0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("RIGHT LANE");
  lcd.setCursor(0,1);
  lcd.print("READY TO STOP");
  ctr = 5;
  while(ctr>=0){
    digitalWrite(3, HIGH);
    lcd.setCursor(14, 1);
    lcd.print(ctr);
    delay(1000);
    ctr = ctr-1;
    digitalWrite(3, LOW);
  }
  

  // RIGHT LED RED (STOP) ON FOR 5 SECONDS
  ctr1 = 0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("RIGHT LANE");
  lcd.setCursor(0,1);
  lcd.print("STOP");
  ctr = 4;
  while(ctr>=0){
    digitalWrite(4, HIGH);
    lcd.setCursor(5, 1);
    lcd.print(ctr);
    delay(1000);
    ctr = ctr-1;
    digitalWrite(4, LOW);
  }

  
  //LEFT GREEN LED
  ctr1 = 0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LEFT LANE");
  lcd.setCursor(0,1);
  lcd.print("GO");
  ctr = 7;
  while(ctr>=0){
    digitalWrite(10, HIGH);
    lcd.setCursor(3, 1);
    lcd.print(ctr);
    delay(1000);
    ctr = ctr-1;
    digitalWrite(10, LOW);
  }

  //LEFT YELLOW LED
  ctr1 = 0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LEFT LANE");
  lcd.setCursor(0,1);
  lcd.print("READY TO STOP");
  ctr = 5;
  while(ctr>=0){
    digitalWrite(9, HIGH);
    lcd.setCursor(14, 1);
    lcd.print(ctr);
    delay(1000);
    ctr = ctr-1;
    digitalWrite(9, LOW);
  }

  //LEFT RED LED
  ctr1 = 0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LEFT LANE");
  lcd.setCursor(0,1);
  lcd.print("STOP");
  ctr = 4;
  while(ctr>=0){
    digitalWrite(8, HIGH);
    lcd.setCursor(5, 1);
    lcd.print(ctr);
    delay(1000);
    ctr = ctr-1;
    digitalWrite(8, LOW);
  }
  
}
