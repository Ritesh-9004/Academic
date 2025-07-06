

#include <LiquidCrystal.h>
#include <stdio.h>

LiquidCrystal lcd(6, 7, 5, 4, 3, 2);
 unsigned char rcv,count,gchr,gchr1,robos='s';
 //char pastnumber[11]="";
 

int sti=0;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

const int trigPin = A4;
const int echoPin = A3;

int m1a   = 8;
int m1b   = 9;

int m2a   = 10;
int m2b   = 11;

int ir1  = A0;
int ir2  = A1;

int buzzer = A2;

int m3a = 12;
int m3b = 13;

int rtr1=0;
int dist1=0,dist2=0,dist3,sts1=0,sts2=0;
long duration;
int distanceCm, distanceInch;



unsigned int ultra_dist()
{int ud=0;
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   distanceCm= duration*0.034/2;
   ud = distanceCm;
   return ud;
}

void okcheck()
{
  unsigned char rcr;
  do{
      rcr = Serial.read();
    }while(rcr != 'K');
}


void setup() 
{
  Serial.begin(9600);serialEvent();

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input 

  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  
  pinMode(m1a, OUTPUT);pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);pinMode(m2b, OUTPUT);
  pinMode(m3a, OUTPUT);pinMode(m3b, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  digitalWrite(m1a, LOW);digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);digitalWrite(m2b, LOW);
  digitalWrite(m3a, LOW);digitalWrite(m3b, LOW);
  digitalWrite(buzzer, HIGH);
  
  lcd.begin(16, 2);
  lcd.print("   AGV");
  lcd.setCursor(0,1);
  lcd.print(" Forklift");
  delay(2000);

  lcd.clear();
  lcd.print("U:"); 
}

int dista=0;

void loop() 
{    
  dista=0;
  dist1=0;
  dist2=0;

for(rtr1=0;rtr1<5;rtr1++)
   {
    dista = ultra_dist();
    dist1 = (dist1 + dista);
      delay(10);
   }

 dist1 = (dist1/5);
 lcd.setCursor(3,0);convertl(dist1);


if(dist1 < 30)
  {
    digitalWrite(m1a, LOW);digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);digitalWrite(m2b, LOW);
    
    digitalWrite(buzzer, LOW);

    digitalWrite(m3a, HIGH);digitalWrite(m3b, LOW);
    delay(10000);      
    digitalWrite(m3a, LOW);digitalWrite(m3b, LOW);
   
    delay(1000);      

    digitalWrite(m3a, LOW);digitalWrite(m3b, HIGH);
    delay(10000);      
    digitalWrite(m3a, LOW);digitalWrite(m3b, LOW);
  }
else
  { 
    digitalWrite(buzzer, HIGH);
  if(digitalRead(ir1) == HIGH && digitalRead(ir2) == HIGH)
    {
          digitalWrite(m1a, HIGH);digitalWrite(m1b, LOW);
          digitalWrite(m2a, HIGH);digitalWrite(m2b, LOW);
    }      
  if(digitalRead(ir1) == HIGH && digitalRead(ir2) == LOW)
    {
          digitalWrite(m1a, HIGH);digitalWrite(m1b, LOW);
          digitalWrite(m2a, LOW);digitalWrite(m2b, HIGH);
    }      
  if(digitalRead(ir1) == LOW && digitalRead(ir2) == HIGH)
    {
          digitalWrite(m1a, LOW);digitalWrite(m1b, HIGH);
          digitalWrite(m2a, HIGH);digitalWrite(m2b, LOW);
    }      
  if(digitalRead(ir1) == LOW && digitalRead(ir2) == LOW)
    {delay(1500);
    if(digitalRead(ir1) == LOW && digitalRead(ir2) == LOW)
      {
          digitalWrite(m1a, LOW);digitalWrite(m1b, LOW);
          digitalWrite(m2a, LOW);digitalWrite(m2b, LOW);
      }
    }
  }
}    


void serialEvent() 
{
  while (Serial.available()) 
        {
         
         char inChar = (char)Serial.read();
           //sti++;
           //inputString += inChar;
          if(inChar == '*')
            {sti=1;
              inputString += inChar;
             //  stringComplete = true;
             // gchr = inputString[sti-1] 
            }
          if(sti == 1)
            {
                inputString += inChar;
            }
          if(inChar == '#')
            {sti=0;
              stringComplete = true;      
            }
        }
}




void converts(unsigned int value)
{
  unsigned int a,b,c,d,e,f,g,h;

      a=value/10000;
      b=value%10000;
      c=b/1000;
      d=b%1000;
      e=d/100;
      f=d%100;
      g=f/10;
      h=f%10;


      a=a|0x30;               
      c=c|0x30;
      e=e|0x30; 
      g=g|0x30;              
      h=h|0x30;
    
     
   Serial.write(a);
   Serial.write(c);
   Serial.write(e); 
   Serial.write(g);
   Serial.write(h);
}

void convertl(unsigned int value)
{
  unsigned int a,b,c,d,e,f,g,h;

      a=value/10000;
      b=value%10000;
      c=b/1000;
      d=b%1000;
      e=d/100;
      f=d%100;
      g=f/10;
      h=f%10;


      a=a|0x30;               
      c=c|0x30;
      e=e|0x30; 
      g=g|0x30;              
      h=h|0x30;
    
     
   lcd.write(a);
   lcd.write(c);
   lcd.write(e); 
   lcd.write(g);
   lcd.write(h);
}

/*
   sensorValue = analogRead(analogInPin);
   sensorValue = (sensorValue/9.31);
   lcd.setCursor(1,1); //rc
   lcd.print(sensorValue);
   Serial.print(sensorValue);
 */
