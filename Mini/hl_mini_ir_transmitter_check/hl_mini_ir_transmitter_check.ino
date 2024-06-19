/*
 * hl_mini_ir_transmitter_check
 * 
 * Проверка встроенного инфракрасного передатчика HL Мини
 * 
 * Смотреть на ИК передатчик через приложение камеры на смартфоне
 * 
 * Ссылка на библиотеку https://github.com/Arduino-IRremote/Arduino-IRremote/tree/master
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Вывод управления ИК светодиодом (передатчиком)
#define IR_SEND_PIN 3

// Подключение библиотеки для работы с ИК пультами
#include <IRremote.hpp>

// Начальные значения команды, адреса, количества повторов
byte send_address = 0x00;
byte send_command = 0x34;
byte send_repeats = 0;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

  // Инициализация объекта библиотеки для режима передатчика
  IrSender.begin();
  // Отлючение светодиода обратной связи
  disableLEDFeedback();
}

void loop() {
  Serial.print("Send: address = 0x");
  Serial.print(send_address, HEX);
  Serial.print(", command = 0x");
  Serial.print(send_command, HEX);
  Serial.print(", repeats = ");
  Serial.print(send_repeats);
  Serial.println();

  // Передача пакета данных
  IrSender.sendNEC(send_address, send_command, send_repeats);
  // Изменение значение команды
  send_command += 0x11;
  // Инкремент повторений
  send_repeats++;
    
  // Ограничение количество повторений
  if(send_repeats > 4) {
    send_repeats = 0;
  }
  
  delay(1000); 
}
