/*
 * hl_beginer_servo_check
 * 
 * Проверка сервопривода HL Начальный
 * 
 * Сервопривод подключен в P12
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Подключение библиотеки для работы с сервоприводами
#include <Servo.h>

// Вывод управления сервоприводом
const byte SERVO_PIN = 7;

// Переменная для хранения текущего положения
int current_pos = 0;

// Создание объекта сервопривода
Servo MyServo;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Присвоение объекту сервопривода вывода управления
  MyServo.attach(SERVO_PIN);
}

void loop() {
  Serial.println("Direction 1");
  // Поворот вала сервопривода в направлении 1
  for (current_pos = 0; current_pos <= 180; current_pos++) {
    MyServo.write(current_pos);
    Serial.print("Current Position "); Serial.println(current_pos);
    delay(15);
  }
  Serial.println();
  delay(500);
  
  Serial.println("Direction 2");
  // Поворот вала сервопривода в направлении 2
  for (current_pos = 180; current_pos >= 0; current_pos--) {
    MyServo.write(current_pos);
    Serial.print("Current Position "); Serial.println(current_pos);
    delay(15);
  }
  Serial.println();
  delay(500);
}
