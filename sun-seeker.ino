//--------------------------Sun-Seeker---------------------------//
//---------------------------------------------------------------//

//assigning analog pin to the sensor input 
int pinin1=A0,pinin2=A1;

//store analog value
int sensorValue1=0,sensorValue2=0;

//digital out comparing sensor values 
int stpin1,stpin2;

//these digital output for driving three motors 
const int m1=2,m2=3,m3=4,m4=5,m5=8,m6=9;

//counter parameters
int interval_to_read_sensor_value=0,loop_count=0;


//robot's basic functions
void stop_right_there();
void move_forward_searching_light();
void rotate_in_dir_of_light();


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
    stop_right_there();
  }
  //2nd condition both sensor doesnot detect light
  else if(stpin1==LOW && stpin2== LOW)
  {
    move_forward_searching_light();
  }
  //3rd condition one of the sensor detect light
  else
  {
    rotate_in_dir_of_light();
  }
  if(interval_to_read_sensor_value==500)
  {
    digitalWrite(m1,LOW);
    digitalWrite(m2,HIGH);
    digitalWrite(m3,LOW);
    digitalWrite(m4,LOW);
    delay(4300);
    interval_to_read_sensor_value=0;
    loop_count++;
    stop_right_there();
  }
  if(loop_count==4)
    exit(0);
}

void stop_right_there()
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

void move_forward_searching_light()
{
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,LOW);
  digitalWrite(m4,HIGH);
  delay(20);
  interval_to_read_sensor_value++;
  stop_right_there();
  return;
}

void rotate_in_dir_of_light()
{
  if(stpin1==HIGH && stpin2==LOW)
  {
    digitalWrite(m5,HIGH);
    digitalWrite(m6,LOW);  
    delay(50);
    stop_right_there();
    return;
  }
  else
  {
    digitalWrite(m5,LOW);
    digitalWrite(m6,HIGH);
    delay(50);
    stop_right_there();
    return;
  } 
}



