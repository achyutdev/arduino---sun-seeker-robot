//#include <Stepper.h>

int pinin1=A0;
int pinin2=A1;
int stpin1,stpin2;
const int m1=2;
const int m2=3;
const int m3=4;
const int m4=5;
const int m5=8;
const int m6=9;
int a=0,s=0;
int sensorValue1=0;
int sensorValue2=0;
//const int stepsPerRevolution = 200;
//Stepper myStepper(stepsPerRevolution, 8,9,10,11); 
void stop_M();
void forward_M();
void stepper_M();

void setup()
  {
    pinMode(m1,OUTPUT);
    pinMode(m2,OUTPUT);
    pinMode(m3,OUTPUT);
    pinMode(m4,OUTPUT);
    pinMode(m5,OUTPUT);
    pinMode(m6,OUTPUT);
 }
void loop()
{

    sensorValue1 = analogRead(pinin1);    
    if(sensorValue1<=150)
         stpin1=HIGH;
    else
         stpin1=LOW;
    sensorValue2 = analogRead(pinin2);    
    if(sensorValue2<=150)
         stpin2=HIGH; 
    else
         stpin2=LOW;

// 1st condition both sensor detect light
   if (stpin1==HIGH && stpin2==HIGH) 
   {
     stop_M();
   }
//2nd condition both sensor doesnot detect light
   else if(stpin1==LOW && stpin2== LOW)
   {
     forward_M();
    }
//3rd condition one of the sensor detect light
   else
      {
          stepper_M();
      }
if(a==500)
{
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
  delay(4300);
  a=0;
  s++;
  stop_M();
}
if(s==4)
exit(0);

}
void stop_M()
{
  digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
  digitalWrite(m5,LOW);
  digitalWrite(m6,LOW);
  // delay(50);
  return;
  
}
void forward_M()
{
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,LOW);
  digitalWrite(m4,HIGH);
  delay(20);
  a++;
  stop_M();
  return;
}
void stepper_M()
{
  if(stpin1==HIGH && stpin2==LOW)
  {
    digitalWrite(m5,HIGH);
    digitalWrite(m6,LOW);  
    delay(50);
    stop_M();
    return;
  }
  else
  {
    digitalWrite(m5,LOW);
    digitalWrite(m6,HIGH);
    delay(50);
    stop_M();
    return;
  } 
}

 
