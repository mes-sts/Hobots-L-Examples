/*
 * hl_standart_double_line_check
 * 
 * Проверка двойного датчика линии HL Стандарт
 * 
 * Двойной датчик линии подключен в разъем 1
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2025. v1.1 / MES
 */


// Выводы двух каналов датчика линии
const int SENSOR1_PIN = 11;
const int SENSOR2_PIN = 10;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

  // Настройка выводов датчика на вход
  pinMode(SENSOR1_PIN, INPUT);
  pinMode(SENSOR2_PIN, INPUT);
}

void loop() {
  // Получение состояний каждого канала датчика линии
  bool sensor_1 = digitalRead(SENSOR1_PIN);
  bool sensor_2 = digitalRead(SENSOR2_PIN);

  // Вывод состояний в монитор порта
  Serial.print("Sensor 1 - ");
  Serial.print(sensor_1);
  Serial.print(", Sensor 2 - ");
  Serial.println(sensor_2);
  
  delay(20);
}
