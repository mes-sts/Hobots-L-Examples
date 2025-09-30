/*
 * hl_classic_module_color_check
 * 
 * Проверка модуля датчика цвета ХЛ Классический
 * 
 * Датчик цвета подключен в разъем 1
 * 
 * Библиотека для работы с датчиком цвета https://github.com/adafruit/Adafruit_TCS34725
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2025. v1.0 / MES
 */

// Подключение библиотеки для работы с датчиком цвета
#include "Adafruit_TCS34725.h"

// Содание объекта датчика с временем интегрирования 614мс
Adafruit_TCS34725 TCS = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS);

// Вывод управления яркостью светодиода
const byte PWM_LED_PIN = 4;
// Вывод получения сигнала прерывания от датчика
const byte INT_TCS_PIN = 9;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

  // Настройка вывода яркости на выход
  pinMode(PWM_LED_PIN, OUTPUT);
  // Настройка вывода прерывания на вход
  pinMode(INT_TCS_PIN, INPUT);

  // Проверка на наличие датчика
  if (TCS.begin()) {
    Serial.println("Found sensor");
  }
  else {
    Serial.println("Sensor not found");
    while(true);
  }

  // Включение прерывания по завершению вычислений
  TCS.setInterrupt(true);
  
  // Включение светодиода на полную яркость
  digitalWrite(PWM_LED_PIN, HIGH);
}

void loop() {
  // Если датчик сообщил о завершении вычислений (прерывание)
  if (!digitalRead(INT_TCS_PIN)) {
    // Переменные для хранения цветов и цветовой температуры
    word red_value, green_value, blue_value, clear_value, color_temperature;
    
    // Получение данных от датчика
    TCS.getRawData(&red_value, &green_value, &blue_value, &clear_value);
    
    // Вычисление цветовой температуры на основе данных
    color_temperature = TCS.calculateColorTemperature(red_value, green_value, blue_value);
    
    // Вывод полученной информации в порт
    Serial.print("Red: "); Serial.print(red_value, DEC); Serial.print(" ");
    Serial.print("Green: "); Serial.print(green_value, DEC); Serial.print(" ");
    Serial.print("Blue: "); Serial.print(blue_value, DEC); Serial.print(" ");
    Serial.print("Clear: "); Serial.print(clear_value, DEC); Serial.print(" ");
    Serial.print("Temperature: "); Serial.print(color_temperature, DEC); Serial.println("K");
  }
}
