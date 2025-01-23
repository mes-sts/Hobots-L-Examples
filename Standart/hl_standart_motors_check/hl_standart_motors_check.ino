/*
 * hl_standart_motors_check
 * 
 * Проверка моторов для контроллера HL Стандарт
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2025. v1.1 / MES
 */

// Выводы направления моторов
const int DIR_M1_PIN = 7;
const int DIR_M2_PIN = 4;
// Выводы скорости моторов
const int PWM_M1_PIN = 6;
const int PWM_M2_PIN = 5;
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);
  // Настройка всех выводов на выход
  pinMode(DIR_M1_PIN, OUTPUT);
  pinMode(DIR_M2_PIN, OUTPUT);
  pinMode(PWM_M1_PIN, OUTPUT);
  pinMode(PWM_M2_PIN, OUTPUT);
  // Сброс скорости моторов
  analogWrite(PWM_M1_PIN, 0);
  analogWrite(PWM_M2_PIN, 0);
}

void loop() {
  Serial.println("Motors Case 1/4");
  // Первое направление
  digitalWrite(DIR_M1_PIN, LOW);
  digitalWrite(DIR_M2_PIN, HIGH);
  for (byte i = 0; i < 255; i++) { // Увеличение скорости моторов
    Serial.print("Current PWM "); Serial.println(i);
    analogWrite(PWM_M1_PIN, i);
    analogWrite(PWM_M2_PIN, i);
    delay(10);
  }
  delay(300);
  Serial.println("Motors Case 2/4");
  for (byte i = 255; i > 0; i--) { // Уменьшение скорости моторов
    Serial.print("Current PWM "); Serial.println(i);
    analogWrite(PWM_M1_PIN, i);
    analogWrite(PWM_M2_PIN, i);
    delay(10);
  }
  delay(1000);
  // Сброс скорости моторов
  analogWrite(PWM_M1_PIN, 0);
  analogWrite(PWM_M2_PIN, 0);
  
  Serial.println("Motors Case 3/4");
  // Второе направление
  digitalWrite(DIR_M1_PIN, HIGH);
  digitalWrite(DIR_M2_PIN, LOW);
  for (byte i = 0; i < 255; i++) { // Увеличение скорости моторов
    Serial.print("Current PWM "); Serial.println(i);
    analogWrite(PWM_M1_PIN, i);
    analogWrite(PWM_M2_PIN, i);
    delay(10);
  }
  delay(300);
  Serial.println("Motors Case 4/4");
  for (byte i = 255; i > 0; i--) { // Уменьшение скорости моторов
    Serial.print("Current PWM "); Serial.println(i);
    analogWrite(PWM_M1_PIN, i);
    analogWrite(PWM_M2_PIN, i);
    delay(10);
  }
  delay(1000);
  // Сброс скорости моторов
  analogWrite(PWM_M1_PIN, 0);
  analogWrite(PWM_M2_PIN, 0);
}
