byte eye = 14;
const int M11 = 2;
const int M12 = 3;
const int M21 = 4;
const int M22 = 5;
int pwm = 130;
unsigned long startTime;
unsigned long endTime;
unsigned long duration;
byte timerRunning;
int blinkcounter = 0; // current state of the button
int lastblink = 0;
int lastcount =0;
int i=0;
int a[200];
int j=2;
void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
pinMode(eye,INPUT);
pinMode(M11,OUTPUT);
pinMode(M12,OUTPUT);
pinMode(M21,OUTPUT);
pinMode(M22,OUTPUT);
pinMode(9,OUTPUT);
  digitalWrite(M11,LOW);
  digitalWrite(M12,LOW);
  digitalWrite(M21,LOW);
  digitalWrite(M22,LOW);
}
void loop() {
  int eyeblink = digitalRead(eye);
  if (timerRunning == 0 && eyeblink == LOW){
  startTime = millis();
  timerRunning = 1;
  }
  endTime = millis();
  if (eyeblink != lastblink) {
    // if the state has changed, increment the counter
    if (eyeblink == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      blinkcounter++;
      Serial.println("blink");
    }
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastblink = eyeblink;
  if (timerRunning == 1 && endTime - startTime > 3000 )
  {
  timerRunning = 0;
  Serial.println("Time reached");
  Serial.print("number of blinks: ");
  Serial.println(blinkcounter);
  if (blinkcounter == 2)
    {
       room_one();
       Serial.println("Room one");
    }
  else if (blinkcounter == 3)
   {
      room_two();
      Serial.println("Room two");}
  else if (blinkcounter == 4)
    {
      room_three();
      Serial.println("Room three");}
  else if (blinkcounter == 5)
    {
      room_four();
      Serial.println("Room four");}
    a[j]=blinkcounter;
    j++;
    lastcount = a[j-1];
  blinkcounter =0;
  }
}
int room_one()
{
  Serial.println(lastcount);
  if (lastcount == 0 || lastcount == 2)
  {
    stop1();
  }
  else if (lastcount == 3)
  {
    reverse();
    delay(5000);
    right();
    reverse();
    delay(10000);
    stop1();
  }
  else if (lastcount == 4)
  {
    reverse();
    delay(15000);
    right();
    reverse();
    delay(5000);
    left();
    stop1;
  }
  else if (lastcount == 5)
  {
    reverse();
    delay(5000);
    left();
    reverse();
    delay(10000);
    right();
    reverse();
    delay(5000);
    left();
    stop1;
  }
  i=0;
}
int room_two()
{
  Serial.println(lastcount);
  if (lastcount == 0 || lastcount == 3)
  {
    stop1();
  }
  else if (lastcount == 2)
  {
    forward();
    delay(10000);
    left();
    forward();
    delay(5000);
    stop1();
  }
  else if (lastcount == 4)
  {
    reverse();
    delay(5000);
    left();
    forward();
    delay(10000);
    stop1;
  }
  else if (lastcount == 5)
  {
    left();
    left();
    forward();
    delay(15000);
    stop1();
  }
  i=0;
}
int room_three()
{
  Serial.println(lastcount);
  if (lastcount == 0 || lastcount == 4)
  {
    stop1();
  }
  else if (lastcount == 2)
  {
    forward();
    delay(10000);
    right();
    forward();
    delay(5000);
    left();
    forward();
    delay(5000);
    stop1();
  }
  else if (lastcount == 3)
  {
    reverse();
    delay(10000);
    right();
    forward();
    delay(5000);
    stop1;
  }
  else if (lastcount == 5)
  {
    reverse();
    delay(5000);
    left();
    forward();
    delay(5000);
    stop1;
  }
  i=0;
}
int room_four ()
{
  Serial.println(lastcount);
  if (lastcount == 0 || lastcount == 5)
  {
    stop1();
  }
  else if (lastcount == 2)
  {
    forward();
    delay(10000);
    right();
    forward();
    delay(10000);
    stop1();
  }
  else if (lastcount == 3)
  {
    reverse();
    delay(15000);
    left();
    left();
    stop1;
  }
  else if (lastcount == 4)
  {
    reverse();
    delay(5000);
    right();
    forward();
    delay(5000);
    stop1;
  }
  i=0;
}
int forward()
{
  analogWrite(9,pwm);
  digitalWrite(M11,HIGH);
  digitalWrite(M12,LOW);
  digitalWrite(M21,HIGH);
  digitalWrite(M22,LOW);
}
int reverse()
{ analogWrite(9,pwm);
  digitalWrite(M11,LOW);
  digitalWrite(M12,HIGH);
  digitalWrite(M21,LOW);
  digitalWrite(M22,HIGH);
}
int left()
{analogWrite(9,pwm);
  digitalWrite(M11,HIGH);
  digitalWrite(M12,LOW);
  digitalWrite(M21,LOW);
  digitalWrite(M22,HIGH);
  delay(3000);
  digitalWrite(M11,LOW);
  digitalWrite(M12,LOW);
  digitalWrite(M21,LOW);
  digitalWrite(M22,LOW);
}
int right()
{analogWrite(9,pwm);
  digitalWrite(M11,LOW);
  digitalWrite(M12,HIGH);
  digitalWrite(M21,HIGH);
  digitalWrite(M22,LOW);
  delay(3000);
  digitalWrite(M11,LOW);
  digitalWrite(M12,LOW);
  digitalWrite(M21,LOW);
  digitalWrite(M22,LOW);
}
int stop1()
{analogWrite(9,pwm);
  digitalWrite(M11,LOW);
  digitalWrite(M12,LOW);
  digitalWrite(M21,LOW);
  digitalWrite(M22,LOW);
}
