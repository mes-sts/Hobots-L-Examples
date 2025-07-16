/*
 * hl_x_demo
 * 
 * Демонстрационный пример
 * Движение по черной линии с одним аналоговым датчиком и двумя сервоприводами HL X
 * 
 * Инструменты → Плата → STM32 Boards Groups → Generic STM32F1 series
 * Инструменты → Board part number → Generic F103RETx
 * Инструменты → U(S)ART support → Enable (generic 'Serial')
 * Инструменты → USB support (if available) → CDC (generic 'Serial' supersede U(S)ART)
 * Инструменты → Upload method → HID Bootloader 2.2
 * 
 * Copyright (C) 2025. v1.0 / MES
 */

// Подключение библиотеки для работы с сервоприводами
#include <Servo.h>

// Вывод датчика линии
const uint8_t SENSOR_LINE_A_PIN = PA0;
// Выводы управления сервоприводами
const uint8_t SERVO_PIN = PB1;
const uint8_t SERVO_PIN_2 = PB0;

// Создание объектов сервоприводов
Servo myServo1;
Servo myServo2;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка вывода датчика линии на вход
  pinMode(SENSOR_LINE_A_PIN, INPUT);

  // Присвоение объектам сервоприводов выводов управления
  myServo1.attach(SERVO_PIN);
  myServo2.attach(SERVO_PIN_2); 
}

void loop() {
  // Получяение значения с датчика линии
  uint8_t sensor_value = analogRead(SENSOR_LINE_A_PIN);
  // Вывод значения датчика
  Serial.println(sensor_value);

  if (sensor_value > 200) {
    myServo1.write(130);
    myServo2.write(80);
  }
  else {
    myServo1.write(100);
    myServo2.write(60);
  }
  
  delay(5);
}
