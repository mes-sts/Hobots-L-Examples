/*
 * hl_classic_module_motors_check
 * 
 * Проверка моторов для контроллера ХЛ Классический
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2025. v1.0 / MES
 */

// Выводы направления и скорости моторов
const int M1_INA_PIN = 3;
const int M1_INB_PIN = 5;
const int M2_INC_PIN = 11;
const int M2_IND_PIN = 6;
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);
  // Настройка всех выводов на выход
  pinMode(M1_INA_PIN, OUTPUT);
  pinMode(M1_INB_PIN, OUTPUT);
  pinMode(M2_INC_PIN, OUTPUT);
  pinMode(M2_IND_PIN, OUTPUT);
  // Остановка и отпускание нагрузки моторов
  digitalWrite(M1_INA_PIN, LOW);
  digitalWrite(M1_INB_PIN, LOW);
  digitalWrite(M2_INC_PIN, LOW);
  digitalWrite(M2_IND_PIN, LOW);
}

void loop() {
  Serial.println("Motors Forward");
  // Первое направление
  analogWrite(M1_INA_PIN, 255);
  analogWrite(M1_INB_PIN, 0);
  analogWrite(M2_INC_PIN, 0);
  analogWrite(M2_IND_PIN, 255);
  delay(1000);

  // Остановить моторы перед сменой направления
  digitalWrite(M1_INA_PIN, LOW);
  digitalWrite(M1_INB_PIN, LOW);
  digitalWrite(M2_INC_PIN, LOW);
  digitalWrite(M2_IND_PIN, LOW);
  delay(100);

  Serial.println("Motors Backward");
  // Второе направление
  analogWrite(M1_INA_PIN, 0);
  analogWrite(M1_INB_PIN, 255);
  analogWrite(M2_INC_PIN, 255);
  analogWrite(M2_IND_PIN, 0);
  delay(1000);

  // Остановить моторы перед сменой направления
  digitalWrite(M1_INA_PIN, LOW);
  digitalWrite(M1_INB_PIN, LOW);
  digitalWrite(M2_INC_PIN, LOW);
  digitalWrite(M2_IND_PIN, LOW);
  delay(100);
}
