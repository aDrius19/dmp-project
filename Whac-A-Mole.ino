#include <LiquidCrystal.h>
#include <TimerOne.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
volatile int myVar;
unsigned long light;
int score = 0;
int minn = 1, sec = 0, s = 7;

void setup()
{ //init Timer
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(timee);

  lcd.begin(16, 2);
  
  randomSeed(analogRead(A0)); //for the random number to be truly random

  pinMode(6, INPUT); //buttons
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);

  pinMode(22, OUTPUT); //LEDs
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);

  pinMode(13, OUTPUT); //buzzer
}

void timerCountdown()
{
  lcd.setCursor(0, 1);
  lcd.print("Time: ");

  if (myVar <= 7)
  {
    sec = s - myVar;
  }

  if (myVar == 8) 
  {
    minn--;
  }

  if (myVar > 7 && myVar <= 67)
  {
    sec = (59 - myVar) + 8;
  }

  if (minn < 10)
  {
    lcd.print("0" + String(minn) + ":");
  }
  else
  {
    lcd.print(String(minn) + ":");
  }

  if (sec < 10)
  {
    lcd.print("0" + String(sec));
  }
  else
  {
    lcd.print(String(sec));
  }
}

void whacAMole()
{
  unsigned long current;
  unsigned long end;
  current = millis();
  end = millis() + 700;

  while (millis() < end)
  {
    if (myVar >= 0 && myVar < 20)
    {
      if (myVar % 5 == 0)
      {
        light = random(23, 27); 

        digitalWrite(light, HIGH);
        delay(500);
        digitalWrite(light, LOW);

        if (digitalRead(6) == HIGH)
        {
          if (light != 25)
          {
            digitalWrite(22, HIGH);
            delay(300);
            digitalWrite(22, LOW);
          }
          else {
            score += 10;
          }
        }

        if (digitalRead(7) == HIGH)
        {
          if (light != 23)
          {
            digitalWrite(22, HIGH);
            delay(300);
            digitalWrite(22, LOW);
          }
          else {
            score += 10;
          }
        }

        if (digitalRead(8) == HIGH)
        {
          if (light != 26)
          {
            digitalWrite(22, HIGH);
            delay(300);
            digitalWrite(22, LOW);
          }
          else {
            score += 10;
          }
        }

        if (digitalRead(9) == HIGH)
        {
          if (light != 24)
          {
            digitalWrite(22, HIGH);
            delay(300);
            digitalWrite(22, LOW);
          }
          else {
            score += 10;
          }
        }
      }
      else
      {
        digitalWrite(23, LOW);
        digitalWrite(24, LOW);
        digitalWrite(25, LOW);
        digitalWrite(26, LOW);
      }
    }

    if (myVar >= 20 && myVar < 22)
    {
      digitalWrite(23, LOW);
      digitalWrite(24, LOW);
      digitalWrite(25, LOW);
      digitalWrite(26, LOW);
      digitalWrite(22, LOW);
      tone(13, 196);
    }

    if (myVar >= 22 && myVar < 42)
    {
      noTone(13);

      if (myVar % 4 == 0)
      {
        light = random(23, 27);

        digitalWrite(light, HIGH);
        delay(500);
        digitalWrite(light, LOW);

        if (digitalRead(6) == HIGH)
        {
          if (light != 25)
          {
            digitalWrite(22, HIGH);
            delay(300);
            digitalWrite(22, LOW);
          }
          else {
            score += 10;
          }
        }

        if (digitalRead(7) == HIGH)
        {
          if (light != 23)
          {
            digitalWrite(22, HIGH);
            delay(300);
            digitalWrite(22, LOW);
          }
          else {
            score += 10;
          }
        }

        if (digitalRead(8) == HIGH)
        {
          if (light != 26)
          {
            digitalWrite(22, HIGH);
            delay(300);
            digitalWrite(22, LOW);
          }
          else {
            score += 10;
          }
        }

        if (digitalRead(9) == HIGH)
        {
          if (light != 24)
          {
            digitalWrite(22, HIGH);
            delay(300);
            digitalWrite(22, LOW);
          }
          else {
            score += 10;
          }
        }
      }
      else
      {
        digitalWrite(23, LOW);
        digitalWrite(24, LOW);
        digitalWrite(25, LOW);
        digitalWrite(26, LOW);
      }
    }

    if (myVar >= 42 && myVar < 44)
    {
      digitalWrite(23, LOW);
      digitalWrite(24, LOW);
      digitalWrite(25, LOW);
      digitalWrite(26, LOW);
      digitalWrite(22, LOW);
      tone(13, 196);
    }

    if (myVar >= 44 && myVar < 64)
    {
      noTone(13);

      if (myVar % 3 == 0)
      {
        light = random(23, 27);
        digitalWrite(light, HIGH);
        delay(500);
        digitalWrite(light, LOW);

        if (digitalRead(6) == HIGH)
        {
          if (light != 25)
          {
            digitalWrite(22, HIGH);
            delay(300);
            digitalWrite(22, LOW);
          }
          else {
            score += 10;
          }
        }

        if (digitalRead(7) == HIGH)
        {
          if (light != 23)
          {
            digitalWrite(22, HIGH);
            delay(300);
            digitalWrite(22, LOW);
          }
          else {
            score += 10;
          }
        }

        if (digitalRead(8) == HIGH)
        {
          if (light != 26)
          {
            digitalWrite(22, HIGH);
            delay(300);
            digitalWrite(22, LOW);
          }
          else {
            score += 10;
          }
        }

        if (digitalRead(9) == HIGH)
        {
          if (light != 24)
          {
            digitalWrite(22, HIGH);
            delay(300);
            digitalWrite(22, LOW);
          }
          else {
            score += 10;
          }
        }
      }
      else
      {
        digitalWrite(23, LOW);
        digitalWrite(24, LOW);
        digitalWrite(25, LOW);
        digitalWrite(26, LOW);
      }
    }
    
    if (myVar >= 64 && myVar < 67)
    {
      digitalWrite(23, LOW);
      digitalWrite(24, LOW);
      digitalWrite(25, LOW);
      digitalWrite(26, LOW);
      digitalWrite(22, LOW);
      tone(13, 196);
      delay(1000);
      noTone(13);
    }

    lcd.setCursor(0, 0);
    lcd.print("Score: ");
    lcd.print(score);
  }
}

void loop()
{
  timerCountdown();
  whacAMole();
}

void timee()
{
  myVar++;
}