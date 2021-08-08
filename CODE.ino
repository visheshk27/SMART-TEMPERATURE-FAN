#include <IRremote.h>
int receiver = 12;
IRrecv irrcev(receiver);
decode_results results;
void setup()
{
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  irrcev.enableIRIn();
}

void loop()
{
 if(irrcev.decode(&results))
 {
   irrcev.resume();
 }
  if(results.value == 16613503)
  {
    move_forward();
  }
  if(irrcev.decode(&results))
 {
   irrcev.resume();
 }
 if(results.value == 16621663)
  {
    stop();
  }
  if(irrcev.decode(&results))
 {
   irrcev.resume();
 }
   if(results.value == 16617583)
  {
    move_back();
  }
 if(irrcev.decode(&results))
 {
   irrcev.resume();
 }
 if(results.value == 16589023)
  {
    turn_left();
  }
  if(irrcev.decode(&results))
 {
   irrcev.resume();
 }
 if(results.value == 16605343)
  {
    turn_right();
  }
}
void move_forward()
{
  digitalWrite(5, LOW);
  digitalWrite(2, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(3, HIGH);
}
void turn_right()
{
  digitalWrite(5, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
  digitalWrite(6, HIGH);
}
void turn_left()
{
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
}
void move_back()
{
  digitalWrite(6, LOW);
  digitalWrite(3, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(2, HIGH);
}
void stop()
{
  digitalWrite(5, LOW);
  digitalWrite(2, LOW);
  digitalWrite(6, LOW);
  digitalWrite(3, LOW);
}
