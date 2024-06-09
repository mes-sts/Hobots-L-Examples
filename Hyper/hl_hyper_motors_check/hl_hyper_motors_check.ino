/*
 * hl_hyper_motors_check
 * 
 * Проверка моторов для контроллера HL Гипер
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Выводы направления моторов
const int DIR_1_M1_PIN = 41;
const int DIR_2_M1_PIN = 40;
const int DIR_1_M2_PIN = 48;
const int DIR_2_M2_PIN = 47;
const int DIR_1_M3_PIN = 43;
const int DIR_2_M3_PIN = 42;
const int DIR_1_M4_PIN = 15;
const int DIR_2_M4_PIN = 14;
const int DIR_1_M5_PIN = 17;
const int DIR_2_M5_PIN = 16;
const int DIR_1_M6_PIN = 62;
const int DIR_2_M6_PIN = 63;
// Выводы скорости моторов
const int PWM_M1_PIN = 5;
const int PWM_M2_PIN = 2;
const int PWM_M3_PIN = 3;
const int PWM_M4_PIN = 11;
const int PWM_M5_PIN = 12;
const int PWM_M6_PIN = 13;
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);
  // Настройка всех выводов направления на выход
  pinMode(DIR_1_M1_PIN,OUTPUT);
  pinMode(DIR_2_M1_PIN,OUTPUT);
  pinMode(DIR_1_M2_PIN,OUTPUT);
  pinMode(DIR_2_M2_PIN,OUTPUT);
  pinMode(DIR_1_M3_PIN,OUTPUT);
  pinMode(DIR_2_M3_PIN,OUTPUT);
  pinMode(DIR_1_M4_PIN,OUTPUT);
  pinMode(DIR_2_M4_PIN,OUTPUT);
  pinMode(DIR_1_M5_PIN,OUTPUT);
  pinMode(DIR_2_M5_PIN,OUTPUT);
  pinMode(DIR_1_M6_PIN,OUTPUT);
  pinMode(DIR_2_M6_PIN,OUTPUT);
  // Настройка всех выводов скорости на выход
  pinMode(PWM_M1_PIN,OUTPUT);
  pinMode(PWM_M2_PIN,OUTPUT);
  pinMode(PWM_M3_PIN,OUTPUT);
  pinMode(PWM_M4_PIN,OUTPUT);
  pinMode(PWM_M5_PIN,OUTPUT);
  pinMode(PWM_M6_PIN,OUTPUT);
  // Сброс скорости моторов
  analogWrite(PWM_M1_PIN, 0);
  analogWrite(PWM_M2_PIN, 0);
  analogWrite(PWM_M3_PIN, 0);
  analogWrite(PWM_M4_PIN, 0);
  analogWrite(PWM_M5_PIN, 0);
  analogWrite(PWM_M6_PIN, 0);
}

void loop() {
  Serial.println("Motors Case 1/4");
  // Первое направление
  digitalWrite(DIR_1_M1_PIN, LOW);
  digitalWrite(DIR_2_M1_PIN, HIGH);
  digitalWrite(DIR_1_M2_PIN, LOW);
  digitalWrite(DIR_2_M2_PIN, HIGH);
  digitalWrite(DIR_1_M3_PIN, LOW);
  digitalWrite(DIR_2_M3_PIN, HIGH);
  digitalWrite(DIR_1_M4_PIN, LOW);
  digitalWrite(DIR_2_M4_PIN, HIGH);
  digitalWrite(DIR_1_M5_PIN, LOW);
  digitalWrite(DIR_2_M5_PIN, HIGH);
  digitalWrite(DIR_1_M6_PIN, LOW);
  digitalWrite(DIR_2_M6_PIN, HIGH);
  for (byte i = 0; i <= 255; i++) { // Увеличение скорости моторов
    Serial.print("Current PWM "); Serial.println(i);
    analogWrite(PWM_M1_PIN, i);
    analogWrite(PWM_M2_PIN, i);
    analogWrite(PWM_M3_PIN, i);
    analogWrite(PWM_M4_PIN, i);
    analogWrite(PWM_M5_PIN, i);
    analogWrite(PWM_M6_PIN, i);
    delay(10);
  }
  Serial.println("Motors Case 2/4");
  // Сброс скорости моторов
  analogWrite(PWM_M1_PIN, 0);
  analogWrite(PWM_M2_PIN, 0);
  analogWrite(PWM_M3_PIN, 0);
  analogWrite(PWM_M4_PIN, 0);
  analogWrite(PWM_M5_PIN, 0);
  analogWrite(PWM_M6_PIN, 0);
  delay(300);
  for (byte i = 255; i >= 0; i--) { // Уменьшение скорости моторов
    Serial.print("Current PWM "); Serial.println(i);
    analogWrite(PWM_M1_PIN, i);
    analogWrite(PWM_M2_PIN, i);
    analogWrite(PWM_M3_PIN, i);
    analogWrite(PWM_M4_PIN, i);
    analogWrite(PWM_M5_PIN, i);
    analogWrite(PWM_M6_PIN, i);
    delay(10);
  }
  delay(1000);
  
  Serial.println("Motors Case 3/4");
  // Второе направление
  digitalWrite(DIR_1_M1_PIN, HIGH);
  digitalWrite(DIR_2_M1_PIN, LOW);
  digitalWrite(DIR_1_M2_PIN, HIGH);
  digitalWrite(DIR_2_M2_PIN, LOW);
  digitalWrite(DIR_1_M3_PIN, HIGH);
  digitalWrite(DIR_2_M3_PIN, LOW);
  digitalWrite(DIR_1_M4_PIN, HIGH);
  digitalWrite(DIR_2_M4_PIN, LOW);
  digitalWrite(DIR_1_M5_PIN, HIGH);
  digitalWrite(DIR_2_M5_PIN, LOW);
  digitalWrite(DIR_1_M6_PIN, HIGH);
  digitalWrite(DIR_2_M6_PIN, LOW);
  for (byte i = 0; i <= 255; i++) { // Увеличение скорости моторов
    Serial.print("Current PWM "); Serial.println(i);
    analogWrite(PWM_M1_PIN, i);
    analogWrite(PWM_M2_PIN, i);
    analogWrite(PWM_M3_PIN, i);
    analogWrite(PWM_M4_PIN, i);
    analogWrite(PWM_M5_PIN, i);
    analogWrite(PWM_M6_PIN, i);
    delay(10);
  }
  Serial.println("Motors Case 4/4");
  // Сброс скорости моторов
  analogWrite(PWM_M1_PIN, 0);
  analogWrite(PWM_M2_PIN, 0);
  analogWrite(PWM_M3_PIN, 0);
  analogWrite(PWM_M4_PIN, 0);
  analogWrite(PWM_M5_PIN, 0);
  analogWrite(PWM_M6_PIN, 0);
  delay(300);
  for (byte i = 255; i >= 0; i--) { // Уменьшение скорости моторов
    Serial.print("Current PWM "); Serial.println(i);
    analogWrite(PWM_M1_PIN, i);
    analogWrite(PWM_M2_PIN, i);
    analogWrite(PWM_M3_PIN, i);
    analogWrite(PWM_M4_PIN, i);
    analogWrite(PWM_M5_PIN, i);
    analogWrite(PWM_M6_PIN, i);
    delay(10);
  }
  delay(1000);
}
