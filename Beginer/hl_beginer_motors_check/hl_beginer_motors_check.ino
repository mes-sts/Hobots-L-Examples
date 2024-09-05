/*
 * hl_beginer_motors_check
 * 
 * Проверка моторов для контроллера HL Начальный
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Выводы направления моторов
const int DIR_1_M1_PIN = 41;
const int DIR_2_M1_PIN = 40;
const int DIR_1_M2_PIN = 44;  
const int DIR_2_M2_PIN = 43;
// Выводы скорости моторов
const int PWM_M1_PIN = 5;
const int PWM_M2_PIN = 45;
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);
  // Настройка всех выводов направления на выход
  pinMode(DIR_1_M1_PIN,OUTPUT);
  pinMode(DIR_2_M1_PIN,OUTPUT);
  pinMode(DIR_1_M2_PIN,OUTPUT);
  pinMode(DIR_2_M2_PIN,OUTPUT);
  // Настройка всех выводов скорости на выход
  pinMode(PWM_M1_PIN,OUTPUT);
  pinMode(PWM_M2_PIN,OUTPUT);
  // Сброс скорости моторов
  analogWrite(PWM_M1_PIN, 0);
  analogWrite(PWM_M2_PIN, 0);
}

void loop() {
  Serial.println("Motors Case 1/2");
  // Первое направление
  digitalWrite(DIR_1_M1_PIN, LOW);
  digitalWrite(DIR_2_M1_PIN, HIGH);
  digitalWrite(DIR_1_M2_PIN, LOW);
  digitalWrite(DIR_2_M2_PIN, HIGH);
  for (byte i = 0; i <= 255; i++) { // Увеличение скорости моторов
    Serial.print("Current PWM "); Serial.println(i);
    analogWrite(PWM_M1_PIN, i);
    analogWrite(PWM_M2_PIN, i);
    delay(10);
  }
  Serial.println("Motors Case 2/2");
  // Сброс скорости моторов
  analogWrite(PWM_M1_PIN, 0);
  analogWrite(PWM_M2_PIN, 0);
  delay(1000);
  for (byte i = 255; i >= 0; i--) { // Уменьшение скорости моторов
    Serial.print("Current PWM "); Serial.println(i);
    analogWrite(PWM_M1_PIN, i);
    analogWrite(PWM_M2_PIN, i);
    delay(10);
  }
  delay(1000);
  // Сброс скорости моторов
  analogWrite(PWM_M1_PIN, 0);
  analogWrite(PWM_M2_PIN, 0);
  delay(1000);
}
