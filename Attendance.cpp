#include<SoftwareSerial.h>
#include<LiquidCrystal.h>

String arr[4]={"$0003499630","$0001967382","$0007944631"};
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
SoftwareSerial myserial(8,9);
int LED = 13; // Use the onboard Uno LED
int isObstaclePin = 11;  // This is our input pin
int isObstacle = HIGH;  
int isObstaclePin2 = 7;  // This is our input pin
int isObstacle2 = LOW;
char inp[10];
int flag=0;
int seated=0;
int entered=0;
void setup()
{
 
  Serial.begin(9600);
  myserial.begin(9600);
  lcd.begin(16,2);
  pinMode(LED, OUTPUT);
  pinMode(isObstaclePin, INPUT);
  Serial.begin(9600);
 
 
 
}


void loop()
{
  isObstacle = HIGH;
  isObstacle2 = HIGH;
  entered=0;seated=0;
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("WELCOME TO");
  lcd.setCursor(5,1);
  lcd.print("BNMIT");
  int count=0;
  isObstacle = digitalRead(isObstaclePin);
  if (isObstacle == LOW)
  {
    isObstacle = HIGH;
    Serial.println("SCAN CARD");
    digitalWrite(LED, HIGH);
    entered=1;
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("SCAN CARD");
    delay(3000);              
    // lcd.print("ACCESS");
    if(myserial.available()){
    while(myserial.available() && count<=12)          
    {
         inp[count] = myserial.read();
         count++;
      }
      String input(inp);
      Serial.print(input);
      // delay(2000);  
      /*for(int i=0;i<4;i++)
      {
        if(input.equalsIgnoreCase(arr[i]) || (input=="0001967382"))
         {
             lcd.clear();
             Serial.println("ACCESS GRANTED");
             //delay(2000);
             lcd.clear();
             lcd.setCursor(0,1);
             lcd.print("Successful");
             flag=1;
             break;
          }
       }
       if(flag!=1) {
              /*lcd.clear();
                  Serial.println("UNAUTHORIZED ACCESS");
                  lcd.print("UNAUTHORIZED");
                   lcd.setCursor(0,1);
                  lcd.print("ACCESS");
                   
                   
                   from here*/
          lcd.clear();  
          Serial.println("ACCESS GRANTED");
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("Authentication");
          lcd.setCursor(0,1);
          lcd.print("Successful");
          flag=1;
          Serial.flush();

                   /*till here*/
                   
          }
          delay(2000);
      isObstacle2 = digitalRead(isObstaclePin2);
      //delay(2000);
      if (isObstacle2 == HIGH)
      {
        Serial.println("SUCCESSFUL");
        digitalWrite(LED, HIGH);
        seated=1;
        Serial.println("STUDENT ENTERED");
        lcd.clear();
       lcd.setCursor(1,0);
          lcd.print("STUDENT");
          lcd.setCursor(0,1);
          lcd.print("ENTERED");
             flag=1;
             
             delay(3000);
 
  }
  else
  {
    Serial.println("SUCCESSFUL");
        digitalWrite(LED, HIGH);
        seated=1;
        Serial.println("STUDENT ENTERED");
        lcd.clear();
       lcd.setCursor(1,0);
          lcd.print("STUDENT");
          lcd.setCursor(0,1);
          lcd.print(" HASNT ENTERED");
             flag=1;
             
             delay(3000);
  }
  isObstacle = HIGH;
  Serial.flush();
  }
 
 
 
 
  /*------------------------------------------------------------------------------------------------------------*/

   count=0;
  isObstacle2 = digitalRead(isObstaclePin2);
  if (isObstacle2 == HIGH)
  {
    isObstacle2 = LOW;
    Serial.println("SCAN CARD");
    digitalWrite(LED, HIGH);
   
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("SCAN CARD");
    delay(3000);              
    // lcd.print("ACCESS");
    if(myserial.available()){
    while(myserial.available() && count<=12)          
    {
         inp[count] = myserial.read();
         count++;
      }
      String input(inp);
      Serial.print(input);
      // delay(2000);  
      /*for(int i=0;i<4;i++)
      {
        if(input.equalsIgnoreCase(arr[i]) || (input=="0001967382"))
         {
             lcd.clear();
             Serial.println("ACCESS GRANTED");
             //delay(2000);
             lcd.clear();
             lcd.setCursor(0,1);
             lcd.print("Successful");
             flag=1;
             break;
          }
       }
       if(flag!=1) {
              /*lcd.clear();
                  Serial.println("UNAUTHORIZED ACCESS");
                  lcd.print("UNAUTHORIZED");
                   lcd.setCursor(0,1);
                  lcd.print("ACCESS");
                   
                   
                   from here*/
          lcd.clear();  
          Serial.println("ACCESS GRANTED");
          lcd.clear();
          lcd.setCursor(1,0);
          lcd.print("Authentication");
          lcd.setCursor(0,1);
          lcd.print("Successful");
          flag=1;
          Serial.flush();

                   /*till here*/
                   
          }
          delay(2000);
      isObstacle= digitalRead(isObstaclePin);
      //delay(2000);
      if (isObstacle == LOW)
      {
        Serial.println("SUCCESSFUL");
        digitalWrite(LED, HIGH);
        seated=1;
        Serial.println("EXIT SUCCESSFUL");
        lcd.clear();
       lcd.setCursor(1,0);
          lcd.print("EXIT");
          lcd.setCursor(0,1);
          lcd.print("SUCCESSFUL");
             flag=1;
             
             delay(3000);
 
  }
  else
  {
    Serial.println("SUCCESSFUL");
        digitalWrite(LED, HIGH);
        seated=1;
        Serial.println("STUDENT ENTERED");
        lcd.clear();
       lcd.setCursor(1,0);
          lcd.print("STUDENT");
          lcd.setCursor(0,1);
          lcd.print(" HASNT EXITED");
             flag=1;
             
             delay(3000);
  }
  isObstacle2 = LOW;
  Serial.flush();
  }
 
}


