/*
 * hl_x_module_color_check
 * 
 * Проверка модуля датчика цвета HL X
 *
 * Ссылка на библиотеку микросхемы датчика цвета https://github.com/adafruit/Adafruit_TCS34725
 * 
 * Инструменты → Плата → STM32 Boards Groups → Generic STM32F1 series
 * Инструменты → Board part number → Generic F103RETx
 * Инструменты → U(S)ART support → Enable (generic 'Serial')
 * Инструменты → USB support (if available) → CDC (generic 'Serial' supersede U(S)ART)
 * Инструменты → Upload method → HID Bootloader 2.2
 * 
 * Copyright (C) 2025. v1.0 / MES
 */

// Подключение библиотеки для работы с датчиком цвета
#include "Adafruit_TCS34725.h"

// Содание объекта датчика с временем интегрирования 614мс
Adafruit_TCS34725 TCS = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS);

// Вывод управления яркостью светодиода
const uint8_t PWM_LED_PIN = PC12;
// Вывод получения сигнала прерывания от датчика
const uint8_t INT_TCS_PIN = PC13;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

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
    // Переменные для хранения значений цветов и цветовой температуры
    uint16_t red_value, green_value, blue_value, clear_value, colour_temperature;
    
    // Получение данных от датчика
    TCS.getRawData(&red_value, &green_value, &blue_value, &clear_value);
    
    // Вычисление цветовой температуры на основе данных
    colour_temperature = TCS.calculateColorTemperature(red_value, green_value, blue_value);
    
    // Вывод полученной информации в Монитор порта
    Serial.print("Red: "); Serial.print(red_value, DEC); Serial.print(" ");
    Serial.print("Green: "); Serial.print(green_value, DEC); Serial.print(" ");
    Serial.print("Blue: "); Serial.print(blue_value, DEC); Serial.print(" ");
    Serial.print("Clear: "); Serial.print(clear_value, DEC); Serial.print(" ");
    Serial.print("Temperature: "); Serial.print(colour_temperature, DEC); Serial.println("K");
  }
}
