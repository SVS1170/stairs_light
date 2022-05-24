// Подключаем библиотеку Adafruit NeoPixel.
#include "Adafruit_NeoPixel.h"
 
// Указываем, какое количество пикселей у нашей ленты.
int COUNT = 1;
int STEP_COUNT = 5;
int LED_COUNT = COUNT*STEP_COUNT;
// Указываем, к какому порту подключен вход ленты DIN.
#define LED_PIN 2
int del = 100;
 
// Создаем переменную strip для управления нашей лентой.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
 
void setup()
{
  // Инициализируем ленту.
  strip.begin();
}

void on_up(){
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
  on_up();
  off_up();
  on_dn();
  off_dn();
  
  
}
