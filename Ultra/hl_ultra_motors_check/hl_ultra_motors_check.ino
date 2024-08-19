/*
 * hl_ultra_motors_check
 * 
 * Проверка Моторов HL Ультра
 * 
 * Инструменты → Плата → STM32 Boards Groups → Generic STM32F1 series
 * Инструменты → Board part number → Generic F103RCTx
 * Инструменты → U(S)ART support → Enable (generic 'Serial')
 * Инструменты → USB support (if available) → CDC (generic 'Serial' supersede U(S)ART)
 * Инструменты → Upload method → HID Bootloader 2.2
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Выводы направления моторов
const int DIR_M1_PIN = PC0;
const int DIR_M2_PIN = PC1;
const int DIR_M3_PIN = PC3;
const int DIR_M4_PIN = PC2;
// Выводы скорости моторов
const int PWM_M1_PIN = PA8;
const int PWM_M2_PIN = PA10;
const int PWM_M3_PIN = PB1;
const int PWM_M4_PIN = PB0;
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);
  // Настройка всех выводов на выход
  pinMode(DIR_M1_PIN,OUTPUT);
  pinMode(DIR_M2_PIN,OUTPUT);
  pinMode(DIR_M3_PIN,OUTPUT);
  pinMode(DIR_M4_PIN,OUTPUT);
  pinMode(PWM_M1_PIN,OUTPUT);
  pinMode(PWM_M2_PIN,OUTPUT);
  pinMode(PWM_M3_PIN,OUTPUT);
  pinMode(PWM_M4_PIN,OUTPUT);
  // Сброс скорости моторов
  analogWrite(PWM_M1_PIN, 0);
  analogWrite(PWM_M2_PIN, 0);
  analogWrite(PWM_M3_PIN, 0);
  analogWrite(PWM_M4_PIN, 0);
}

void loop() {
  Serial.println("Motors Case 1/2");
  digitalWrite(DIR_M1_PIN, LOW);
  digitalWrite(DIR_M2_PIN, HIGH);
  digitalWrite(DIR_M3_PIN, LOW);
  digitalWrite(DIR_M4_PIN, HIGH);
  analogWrite(PWM_M1_PIN, 255);
  analogWrite(PWM_M2_PIN, 255);
  analogWrite(PWM_M3_PIN, 255);
  analogWrite(PWM_M4_PIN, 255);
  delay(1000);
  analogWrite(PWM_M1_PIN, 0);
  analogWrite(PWM_M2_PIN, 0);
  analogWrite(PWM_M3_PIN, 0);
  analogWrite(PWM_M4_PIN, 0);
  delay(1000);

  Serial.println("Motors Case 2/2");
  digitalWrite(DIR_M1_PIN, HIGH);
  digitalWrite(DIR_M2_PIN, LOW);
  digitalWrite(DIR_M3_PIN, HIGH);
  digitalWrite(DIR_M4_PIN, LOW);
  analogWrite(PWM_M1_PIN, 255);
  analogWrite(PWM_M2_PIN, 255);
  analogWrite(PWM_M3_PIN, 255);
  analogWrite(PWM_M4_PIN, 255);
  delay(1000);
  analogWrite(PWM_M1_PIN, 0);
  analogWrite(PWM_M2_PIN, 0);
  analogWrite(PWM_M3_PIN, 0);
  analogWrite(PWM_M4_PIN, 0);
  delay(1000);
}
