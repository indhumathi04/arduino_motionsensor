/*The Task 3 Project is to build an embedded system project where you build a Motion Sensor Alarm System using Arduino Uno and 
 (A.)If a motion is detected you need turn on alarm for 5 seconds
 (B.)turn ON the LED till the motion detected + 2 seconds. 
 Refer the headers of each comment in the code(A or B) and compare with Question given above*/

int sound=12; //The buzzer's positive pin
int light=13; //The LED's positive pin
int detect=2; //The IR Proximity Sensor's Vout pin
int f=0; //flag variable to avoid fluctuations
void setup() {
  // put your setup code here, to run once:
pinMode(detect, INPUT); 
pinMode(sound,OUTPUT);  
pinMode(light,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
while(digitalRead(detect)==LOW) //When Motion Starts
{
  while(f==0) //When Clear motion starts(without Fluctuations)
  {
  digitalWrite(sound,HIGH);//(A.)Alarm is ON
  delay(2000);
  if(digitalRead(detect)==HIGH)//If motion stops in 2s the Light should not even switch ON(the below code should not work)
  break; 
  digitalWrite(light,HIGH); //(B.)After 2 seconds lights switch ON
  delay(3000);    
  digitalWrite(sound,LOW); //(A.)After 5 seconds (2+3) Alarm is switched OFF
   f++;//So that slight fluctuations do not get considered as new movement and lead to prolonged periods of buzzer sound...(in multiples of 5)
  }
}
digitalWrite(light,LOW);//When no motion detected light and sound is expected to be OFF
digitalWrite(sound,LOW);
delay(500); //To prevent slight fluctuations due to minor movements considered as evident motion...
f=0; //So that motion detection can restart again
}
