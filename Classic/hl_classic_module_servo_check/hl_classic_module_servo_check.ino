/*
 * hl_classic_module_servo_check
 * 
 * Проверка модуля сервопривода ХЛ Классический
 * 
 * Сервопривод подключен в разъем 3
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2025. v1.0 / MES
 */

// Подключение библиотеки для работы с сервоприводами
#include <Servo.h>

// Вывод управления сервоприводом
const int SERVO_PIN = A2;

// Переменная для хранения текущего положения
int current_pos = 0;

// Создание объекта сервоприводов
Servo MyServo;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

  // Присвоение объекту сервопривода вывода управления
  MyServo.attach(SERVO_PIN);
}

void loop() {
  Serial.println("Direction 1");
  // Поворот вала сервопривода в направлении 1
  for (current_pos = 0; current_pos <= 180; current_pos += 15) {
    MyServo.write(current_pos);
    Serial.print("Current Position "); Serial.println(current_pos);
    delay(30);
  }
  Serial.println();
  delay(500);
  
  Serial.println("Direction 2");
  // Поворот вала сервопривода в направлении 2
  for (current_pos = 180; current_pos >= 0; current_pos -= 15) {
    MyServo.write(current_pos);
    Serial.print("Current Position "); Serial.println(current_pos);
    delay(30);
  }
  Serial.println();
  delay(500);
}
