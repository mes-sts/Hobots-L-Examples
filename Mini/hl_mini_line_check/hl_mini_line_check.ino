/*
 * hl_mini_line_check
 * 
 * Проверка датчика линии HL мини
 * 
 * Кнопка подключена в PORT3
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Выводы двух каналов датчика линии
const byte SENSOR1_PIN = A0;
const byte SENSOR2_PIN = A1;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

  // Настройка выводов датчика на вход
  pinMode(SENSOR1_PIN, INPUT);
  pinMode(SENSOR2_PIN, INPUT);
}

void loop() {
  // Получение значений каждого канала датчика линии
  word sensor_1 = analogRead(SENSOR1_PIN);
  word sensor_2 = analogRead(SENSOR2_PIN);

  // Вывод значений в монитор порта
  Serial.print("CH1 - ");
  Serial.print(sensor_1);
  Serial.print(", CH2 - ");
  Serial.println(sensor_2);
  
  delay(20);
}
