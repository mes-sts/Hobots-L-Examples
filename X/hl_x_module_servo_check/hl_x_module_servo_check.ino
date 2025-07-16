/*
 * hl_x_module_servo_check
 * 
 * Проверка модуля сервопривода HL X
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

// Вывод управления сервоприводом
const uint8_t SERVO_PIN = PC10;

// Переменная для хранения текущего положения
uint8_t current_pos = 0;

// Создание объекта сервоприводов
Servo myServo;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Присвоение объекту сервопривода вывода управления
  myServo.attach(SERVO_PIN);
}

void loop() {
  // Поворот вала в положение 0
  myServo.write(0);
  delay(1000);
  
  // Поворот вала в положение 180
  myServo.write(180);
  delay(1000);
}
