#include <IRremote.h>

int RECV_PIN = 5;
IRrecv irrecv(RECV_PIN);
decode_results results;

// Button code is different for each remote.You must take your remote of codes with IRremote library.
// 1-Download ZIP to IRremote library.
// 2-Sketch-->Include Library-->Add ZIP Library
// 3-file-->examples-->IRremote-->IRrecvDemo
// 4-You must upload of code before button codes take from serial monitor.
#define BUTTON0 0xFF9867  
#define BUTTON1 0xFFA25D
#define BUTTON2 0xFF629D
#define BUTTON3 0xFFE21D
#define BUTTON4 0xFF22DD
#define BUTTON5 0xFF02FD

int led1 = 9;
int led2 = 8;
int led3 = 7;
int led4 = 6;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void loop() {

  if (irrecv.decode(&results))
  {
    if (results.value == BUTTON1)
    {
      digitalWrite(led1, !digitalRead(led1));
      if (digitalRead(led1) == HIGH)
      {
        Serial.println("LED 1 ON");
      }
      else
      {
        Serial.println("LED 1 OFF");
      }
    }
    if (results.value == BUTTON2)
    {
      digitalWrite(led2, !digitalRead(led2));
      if (digitalRead(led2) == HIGH)
      {
        Serial.println("LED 2 ON");
      }
      else
      {
        Serial.println("LED 2 OFF");
      }
    }
    if (results.value == BUTTON3)
    {
      digitalWrite(led3, !digitalRead(led3));
      if (digitalRead(led3) == HIGH)
      {
        Serial.println("LED 3 ON");
      }
      else
      {
        Serial.println("LED 3 OFF");
      }
    }
    if (results.value == BUTTON4)
    {
      digitalWrite(led4, !digitalRead(led4));
      if (digitalRead(led4) == HIGH)
      {
        Serial.println("LED 4 ON");
      }
      else
      {
        Serial.println("LED 4 OFF");
      }
    }
    if (results.value == BUTTON0)
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      Serial.println("All leds OFF ");
    }
    if (results.value == BUTTON5)
    {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      Serial.println("All leds ON ");
    }
    irrecv.resume();

  }
}
