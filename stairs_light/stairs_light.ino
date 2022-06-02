// Подключаем библиотеку Adafruit NeoPixel.
#include "Adafruit_NeoPixel.h"
 
// Указываем, какое количество пикселей у нашей ленты.
int COUNT = 1;
//int STEP_COUNT = map(analogRead(A0), 0, 1023, 0, 255);
int STEP_COUNT = 5;
int LED_COUNT = COUNT*STEP_COUNT;
// Указываем, к какому порту подключен вход ленты DIN.
#define LED_PIN 7
int del = 500;
//int del = map(analogRead(A1), 0, 1023, 0, 500);
bool up = false;
bool dn = false;
#define motionup 2
#define motiondn 3
// Создаем переменную strip для управления нашей лентой.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
 
void setup()
{
  // Инициализируем ленту.
  Serial.begin(9600);
  pinMode(motionup, INPUT);
  pinMode(motiondn, INPUT);
//  digitalWrite(motionup, LOW);
//  digitalWrite(motiondn, LOW);
  strip.begin();
}

void on_up(){
  del = map(analogRead(A0), 0, 1023, 100, 1000);
  for (int i = 0; i < STEP_COUNT; i++)
  {
    for (int b = 0; b < COUNT; b++){
    strip.setPixelColor(COUNT*i+b, strip.Color(255, 255, 255)); //
    }
    strip.show();
    delay(del);
  }
}

void off_up(){
 for (int i = 0; i < STEP_COUNT ; i++)
  {
    for (int b = 0; b < COUNT; b++){
    strip.setPixelColor(COUNT*i+b, strip.Color(0, 0, 0)); //
    }
    strip.show();
  delay(del);
  }
}

void on_dn(){
  for (int i = STEP_COUNT; i >=  0; i--)
  {
    for (int b = 0; b < COUNT; b++){
    strip.setPixelColor(COUNT*i+b, strip.Color(255, 255, 255)); // 
    }
    strip.show();
    delay(del);
  }
}

void off_dn(){
  for (int i = STEP_COUNT; i >= 0; i--)
  {
    for (int b = 0; b < COUNT; b++){
    strip.setPixelColor(COUNT*i+b, strip.Color(0, 0, 0)); // 
    }
  strip.show();
  delay(del);
  }
}

void loop()
{
//  Serial.print(digitalRead(motionup));
//  Serial.print(" , ");
//  Serial.println(digitalRead(motiondn));
  delay(10); 
  if(!digitalRead(motionup)&& dn == false){
     delay(10);
     if(!digitalRead(motionup) && dn == false){
      up = 1;
//      Serial.println("up1 = 1");
      on_up();
     }
     
  }
  if(!digitalRead(motiondn) && up == false){
     delay(10);
     if(!digitalRead(motiondn) && up == false){
      dn = 1;
//      Serial.println("dn1 = 1");
      on_dn();
    
     }
     
  }
  if(!digitalRead(motionup)&& dn == true){
     delay(10);
     if(!digitalRead(motionup) && dn == true){
      up = 0;
//      Serial.println("up2 = 1");
      off_dn();
        dn = 0;
     }
     
  }
  if(!digitalRead(motiondn) && up == true){
     delay(10);
     if(!digitalRead(motiondn) && up == true){
      dn = 0;
//      Serial.println("dn2 = 1");
      off_up();
      up = 0;
     }
     
  }
  
  
//  on_up();
//  off_up();
//  on_dn();
//  off_dn();
}
