# ArduBrushlessMotorStarter

#include <Servo.h> 

Servo myservo;
int val;
int i = 50;



void setup() 
{ 
 Serial.begin(9600) ; 
 myservo.attach(9);
} 
void start()
{
 
   myservo.write(20);
   delay(4000);
    Serial.println( " engine started " ) ;  
   
}
void run(int x)
{
 
   myservo.write(x);
   
}
void runFromXToY(int x, int y)
{   
  
    if (val == 0 || x >= y)
    {
      Serial.println( "cannot go more than SPEED LIMIT  ");
      return;
    }
   x; 
   myservo.write(x);
   Serial.print( "speed is  ");
   Serial.println( x ) ;    
   
   
  }

void loop() 
{ 
 val = Serial.read() - '0' ;
 if (val == 1)
 {
 Serial.println( " engine starting " ) ;  
 start();
 }
 if (val == 2)
 {
 Serial.println( " Running " ) ;
 run(60);
 }
 if (val == 0)
 {
 Serial.println( " Stopped " ) ;  
 run(50);
 i = 50;
 }
 if(val == 3)
 {
   
   i+=10;
   runFromXToY( i, 80);
 }

}
