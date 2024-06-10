/*
 * hl_hyper_servo_check
 * 
 * Проверка сервоприводов HL Гипер
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Подключение библиотеки для работы с сервоприводами
#include <Servo.h>

// Выводы управления сервоприводами
const int SERVO_0_PIN = 6;
const int SERVO_1_PIN = 7;
const int SERVO_2_PIN = 8;
const int SERVO_3_PIN = 9;

// Переменная для хранения текущего положения
int current_pos = 0;

// Создание объектов сервоприводов
Servo MyServo0;
Servo MyServo1;
Servo MyServo2;
Servo MyServo3;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Присвоение объектам сервоприводов выводов управления
  MyServo0.attach(SERVO_0_PIN);
  MyServo1.attach(SERVO_1_PIN);
  MyServo2.attach(SERVO_2_PIN);
  MyServo3.attach(SERVO_3_PIN);
}

void loop() {
  Serial.println("Direction 1");
  // Поворот вала каждого сервопривода в направлении 1
  for (current_pos = 0; current_pos <= 180; current_pos++) {
    MyServo0.write(current_pos);
    MyServo1.write(current_pos);
    MyServo2.write(current_pos);
    MyServo3.write(current_pos);
    Serial.print("Current Position "); Serial.println(current_pos);
    delay(15);
  }
  Serial.println();
  delay(500);
  
  Serial.println("Direction 2");
  // Поворот вала каждого сервопривода в направлении 2
  for (current_pos = 180; current_pos >= 0; current_pos--) {
    MyServo0.write(current_pos);
    MyServo1.write(current_pos);
    MyServo2.write(current_pos);
    MyServo3.write(current_pos);
    Serial.print("Current Position "); Serial.println(current_pos);
    delay(15);
  }
  Serial.println();
  delay(500);
}
