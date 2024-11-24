#include <ESP32Servo.h>

Servo myservo;

int pos;

void setup(){
  Serial.begin(9600);
  myservo.attach(5);
  myservo.write(90);
  Serial.println("connected");
}

void loop(){
  if((Serial.available()>0))
  {
    char com=Serial.read();

    if(com=='u'){
      up();
    }
    else if(com=='d'){
      down();
    }
    else if(com=='c'){
      center();
    }
  }
}

void up()
{
  for(pos=90; pos<=180;pos++);
  myservo.write(pos);
  delay(100);
}

void down()
{
  for(pos=90;pos>=0;pos--);
  myservo.write(pos);
  delay(100);
}


void center()
{
  if(pos>90)
  {
    myservo.write(90);
    delay(100);
    }
  else if(pos<90)
  {
    myservo.write(90);
    delay(100);
  }
}
