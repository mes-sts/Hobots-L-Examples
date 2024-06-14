/*
 * hl_standart_bluetooth_check
 * 
 * Проверка Bluetooth HL Стандарт
 * 
 * Модуль Bluetooth подключен в разъем 1
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Подключение библиотеки программного порта Serial
#include <SoftwareSerial.h>

// Выводы RX и TX альтернативного порта
const byte ALT_RX_PIN = 10;
const byte ALT_TX_PIN = 11;

// Создание и настройка объекта программного порта
SoftwareSerial BTSerial(ALT_RX_PIN, ALT_TX_PIN);

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);
  
  // Настройка выводов порта
  pinMode(ALT_RX_PIN, INPUT);
  pinMode(ALT_TX_PIN, OUTPUT);
    
  // Настройка скорости порта bluetooth
  BTSerial.begin(9600);
}

void loop() {
  if (BTSerial.available() > 0) { // Проверка на наличие данных в буфере для чтения
    // Считывание данных из буфера программного порта
    byte get_data = BTSerial.read();
    // Передача считанных данных в отладочный порт
    Serial.write(get_data);
  }
}
