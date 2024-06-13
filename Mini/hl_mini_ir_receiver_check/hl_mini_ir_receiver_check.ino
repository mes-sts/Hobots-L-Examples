/*
 * hl_mini_ir_receiver_check
 * 
 * Проверка встроенного инфракрасного приемника HL Мини
 * 
 * Ссылка на библиотеку https://github.com/Arduino-IRremote/Arduino-IRremote/tree/master
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Подключение библиотеки для работы с ИК пультами
#include <IRremote.hpp>

// Вывод ИК приемника
const int IR_SENSOR_PIN = 2;
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);
  // Инициализация приемника
  IrReceiver.begin(IR_SENSOR_PIN);
}

void loop() {
  if (IrReceiver.decode()) {
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) { // Приняты данные неизвестного протокола (возможно не указаного) или шум
      Serial.println("Received noise or an unknown (or not yet enabled) protocol");
      IrReceiver.resume();
    }
    else {
      IrReceiver.resume();
      Serial.print("Address ");
      Serial.println(IrReceiver.decodedIRData.address, HEX); // Значение адреса
      Serial.print("Command ");
      Serial.println(IrReceiver.decodedIRData.command, HEX); // Значение команды
      Serial.print("Raw ");
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Значение всей принятой информации
    }
    Serial.println();
  }
}
