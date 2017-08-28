/*
Date: 27/08/2017
Author: D3M
Has support for L298 Motor Driver Module (Speed_Pin - PWM)
Tested and Working at 5V input
*/

int left_wheel_F = 13;                   //Forward Pin - Motor1(Left) 
int right_wheel_F = 12;                  //Forward Pin - Motor2(Right)
int left_wheel_R = 11;                   //Reverse Pin - Motor1(Left)
int right_wheel_R = 10;                  //Reverse Pin - Motor2(Right)
int speed_pin = 9;                       //PWM Pin - To set speed of Motor
int Data;                                //Variable to store data coming from Bluetooth
int Speed;                               //Variable to set speed of motors (Set between 0 and 255)

void setup() {
Serial.begin(38400);
pinMode(left_wheel_F,OUTPUT);
pinMode(right_wheel_F,OUTPUT);
pinMode(left_wheel_R,OUTPUT);
pinMode(right_wheel_R,OUTPUT);
pinMode(speed_pin,OUTPUT);
Speed = 255;							 //Set speed here
}

void loop() {
if(Serial.available())
{ 
  Data = Serial.read();
  if(Data == '0')                           //STOP VEHICLE
  {
    digitalWrite(left_wheel_F,LOW);
    digitalWrite(right_wheel_F,LOW);
    digitalWrite(left_wheel_R,LOW);
    digitalWrite(right_wheel_R,LOW);
    analogWrite(speed_pin,0);
    Serial.println("Stop");
  }
  if(Data == '1')                           //MOVE VEHICLE FRONT
  {
    digitalWrite(left_wheel_F,HIGH);
    digitalWrite(right_wheel_F,HIGH);
    digitalWrite(left_wheel_R,LOW);
    digitalWrite(right_wheel_R,LOW);
    analogWrite(speed_pin,Speed);
    Serial.println("Forward");
  }
  if(Data == '2')                           //TURN VEHICLE LEFT
  {
    digitalWrite(left_wheel_F,LOW);
    digitalWrite(right_wheel_F,HIGH);
    digitalWrite(left_wheel_R,HIGH);
    digitalWrite(right_wheel_R,LOW);
    analogWrite(speed_pin,Speed);
    Serial.println("Left");
  }
  if(Data == '3')                           //TURN VEHICLE RIGHT
  {
    digitalWrite(left_wheel_F,HIGH);
    digitalWrite(right_wheel_F,LOW);
    digitalWrite(left_wheel_R,LOW);
    digitalWrite(right_wheel_R,HIGH);
    analogWrite(speed_pin,Speed);
    Serial.println("Right");
  }
  if(Data == '4')                           //TAKE REVERSE
  {
    digitalWrite(left_wheel_F,LOW);
    digitalWrite(right_wheel_F,LOW);
    digitalWrite(left_wheel_R,HIGH);
    digitalWrite(right_wheel_R,HIGH);
    analogWrite(speed_pin,Speed);
    Serial.println("Reverse");
  }
}

}
