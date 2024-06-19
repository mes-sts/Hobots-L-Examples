/*
 * hl_mini_rgb_led_check
 * 
 * Проверка модуля адресных RGB светодиодов HL Мини
 * 
 * Библиотека Adafruit_NeoPixel https://github.com/adafruit/Adafruit_NeoPixel
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Подключение библиотеки адресных светодиодов
#include <Adafruit_NeoPixel.h>

// Вывод с подключенными адресными светодиодами
const int PIXELS_PIN = 11;
// Количество адресных светодиодов
const int PIXELS_NUM = 4;

// Создание объекта для адресных светодиодов
Adafruit_NeoPixel Pixels(PIXELS_NUM, PIXELS_PIN, NEO_GRB + NEO_KHZ800);
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);
  // Инициализация объекта адресных светодиодов
  Pixels.begin();
  // Выключение всех адресных светодиодов
  Pixels.clear();
}

void loop() {
  // Настройка яркости всех адресных светодиодов на максимум
  Pixels.setBrightness(255);
  Serial.print("Color ");
  Serial.print("R ");
  for (int i = 0; i < PIXELS_NUM; i++) {
    Serial.print(i);
    Serial.print(", ");
    Pixels.setPixelColor(i, Pixels.Color(255, 0, 0)); // Красный
    Pixels.show();
    delay(500);
  }
  Serial.print("G ");
  for (int i = 0; i < PIXELS_NUM; i++) {
    Serial.print(i);
    Serial.print(", ");
    Pixels.setPixelColor(i, Pixels.Color(0, 255, 0)); // Зеленый
    Pixels.show();
    delay(500);
  }
  Serial.print("B ");
  for (int i = 0; i < PIXELS_NUM; i++) {
    Serial.print(i);
    Serial.print(", ");
    Pixels.setPixelColor(i, Pixels.Color(0, 0, 255)); // Синий
    Pixels.show();
    delay(500);
  }
  Serial.print("All ");
  for (int i = 0; i < PIXELS_NUM; i++) {
    Serial.print(i);
    Serial.print(", ");
    Pixels.setPixelColor(i, Pixels.Color(255, 255, 255)); // Все
    Pixels.show();
    delay(500);
  }
  Serial.println("");

  Serial.print("Brightness ");
  for (int i = 255; i > 0; i--) { // Понижение яркости
    Pixels.setBrightness(i);
    Pixels.show();
    delay(10);
  }  
  Serial.println("");
}
