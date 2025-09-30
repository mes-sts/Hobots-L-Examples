/*
 * hl_classic_module_rgb_leds_check
 * 
 * Проверка модуля многоцветного светодиода ХЛ Классический
 *
 * Ссылка на библиотеку https://github.com/adafruit/Adafruit_NeoPixel
 * 
 * Модуль светодиода подключен в разъем 1
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2025. v1.0 / MES
 */


// Подключение библиотеки для работы с адресными светодиодами
#include <Adafruit_NeoPixel.h>

// Вывод светодиода
const int WS2812_PIN = 9;

// Количество светодиодов у модуля
const int WS2812_NUM = 4;

// Создание объекта для управления светодиодами
Adafruit_NeoPixel pixels(WS2812_NUM, WS2812_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

  // Запуск светодиодов
  pixels.begin();
  // Выключение всех светодиодов
  pixels.clear();
  pixels.show();
  // Настройка яркости светодиодов от 0 до 255
  pixels.setBrightness(255);
  pixels.show();
}

void loop() {
  // Выключение всех светодиодов
  pixels.clear();
  pixels.show();

  delay(1000);

  // Проход по каждому светодиоду модуля
  for(int i = 0; i < WS2812_NUM; i++) {

    // Установка цвета светодиода
    // Значения каналов цвета метода pixels.Color() от 0 до 255
    // Порядок цветов: красный, синий, зеленый
    pixels.setPixelColor(i, pixels.Color(100, 150, 200));
    // Отображение цвета у светодиода
    pixels.show();
    // Пауза между включениями светодиодов
    delay(500);
  }
}
