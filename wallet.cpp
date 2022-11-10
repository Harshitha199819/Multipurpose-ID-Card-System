#include<SoftwareSerial.h>
#include<LiquidCrystal.h>
#include<String.h>

int a,b;
int index,fi;
String amount;
//String arr[2]={"10004B23B7CF","10004A87F62B"};
int cost=1000;
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int i,flag=0;
SoftwareSerial myserial(8,9);
unsigned char count=0;
String input,abc;
//char tag[]="10004B23B7CF";


void setup()
{
 
  Serial.begin(9600);
  myserial.begin(9600);
  lcd.begin(16,2);
 
 
}


void loop()
{
    a=0;
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("WELCOME TO");
  lcd.setCursor(5,1);
  lcd.print("BNMIT");
 if(myserial.available())
 {
    input=myserial.readString();
    //Serial.print(input);
    a=1;
   
   
 
   
       
        //index=i;
        displayaccess();
        Serial.print("Enter cost:");
        delay(5000);
       
          amount=Serial.readString();
       
       // b=(int)amount;
        b=amount.toInt();
     Serial.println(b);
        cost=cost-b;
        Serial.print("Balance amount=");
        Serial.println(cost);
        lcd.clear();
        lcd.print("Balance=");
        lcd.print(cost);
        lcd.println("Rs.  ");
        delay(2000);
        }
     
         
     
   
  delay(2000);
}
void displayaccess()
{
    lcd.clear();
    flag=1;
    lcd.print("Balance=");
    lcd.print(cost);
    lcd.println("Rs.  ");
    a=0;
}
void displaynoaccess()
{
  lcd.clear();
      Serial.println("UNAUTHORIZED ACCESS");
      lcd.print("UNAUTHORIZED");
      lcd.setCursor(0,1);
      lcd.print("ACCESS");
       a=0;
}
int convert(String k)
{
  Serial.print(k);
  char ch;
  int l[100];
  int j=0;
  int sum=0;
  int len=k.length();
  for(int i=0;i<len;i++)
  {
    ch=k[i];
    l[i]=(int)ch-48;
    Serial.println(l[i]);
  }
  Serial.println();
 
  for(int i=0;i<len;i++)
  {
    sum=sum*10+l[i];
  }
  return sum;

}



