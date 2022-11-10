#include<SoftwareSerial.h>
#include<LiquidCrystal.h>
#include<String.h>

int a,b;
int index=1,fi=1;
String amount;
String arr[2]={"10004B23B7CF","10004A87F62B"};
int cost[2]={1000,1200};
int book1[2]={0,0};
int book2[2]={0,0};
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int i,flag=0;
int book=0;
int b1,b2,f=0;
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
       
        index=1;
        //displayaccess();
        int choice;
        Serial.println("enter 1-borrow,2-return");
        delay(3000);
        if(Serial.available()>0)
        {
          choice=Serial.read();
        }if(choice==1)
        {
          if(book==0)
        {
          Serial.print("enter book-id");
          if(Serial.available()>0)
        {
          b1=Serial.read();
          f=1;
        }

       
        book=b1;
       
       // b=convert(b1);
   
        Serial.print("Book id");
        Serial.println(book);
        lcd.clear();
        Serial.print("Book id");
        Serial.print(book);
       
        delay(2000);
        }
       
       else {
          Serial.print("MAX OF 2 BOOKS ONLY");
        }
        }
        else if(choice==2)
        {
          book=0;
          lcd.print("book returned");
          Serial.println("book returned");
        }
         else{
          Serial.println("error!");
         }
       
     
           }
     
 
   
  delay(2000);
}
void displayaccess()
{
    lcd.clear();
    flag=1;
    Serial.print("Balance=");
    Serial.print(cost[index]);
    Serial.println("Rs.  ");
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
  }
  Serial.println();
 
  for(int i=0;i<len;i++)
  {
    sum=sum*10+l[i];
  }
  return sum;

}


