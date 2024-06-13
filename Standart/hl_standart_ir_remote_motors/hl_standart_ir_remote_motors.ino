/*
 * hl_standart_ir_remote_motors
 * 
 * Управление моторами ИК пультом HL Стандарт
 * 
 * Приемник подключечен в разъем 6
 * Кнопки на пульте со стрелками ←, →, ↑, ↓ меняют направление движения, любая другая кнопка - останавливает движение
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
const int IR_SENSOR_PIN = 8;
// Выводы направления моторов
const int DIR_M1_PIN = 7;
const int DIR_M2_PIN = 4;
// Выводы скорости моторов
const int PWM_M1_PIN = 6;
const int PWM_M2_PIN = 5;
// Максимальнаяи минимальная скорость моторов 0 - 255
const byte MOTORS_MAX_SPEED = 150;
const byte MOTORS_MIN_SPEED = 0;
// Команды кнопок пульта для движения
const byte CMD_MOVE_FORWARD = 0x18;
const byte CMD_MOVE_BACKWARD = 0x52;
const byte CMD_MOVE_LEFT = 0x08;
const byte CMD_MOVE_RIGHT = 0x5A;
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);
  // Инициализация приемника
  IrReceiver.begin(IR_SENSOR_PIN);
  // Настройка всех выводов моторов на выход
  pinMode(DIR_M1_PIN,OUTPUT);
  pinMode(DIR_M2_PIN,OUTPUT);
  pinMode(PWM_M1_PIN,OUTPUT);
  pinMode(PWM_M2_PIN,OUTPUT);
  // Сброс скорости моторов
  analogWrite(PWM_M1_PIN, MOTORS_MIN_SPEED);
  analogWrite(PWM_M2_PIN, MOTORS_MIN_SPEED);
}

void loop() {
  if (IrReceiver.decode()) {
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) { // Приняты данные неизвестного протокола (возможно не указаного) или шум
      Serial.println("Received noise or an unknown (or not yet enabled) protocol");
      IrReceiver.resume();
      Serial.println();
    }
    else {
      IrReceiver.resume();
      byte received_command = IrReceiver.decodedIRData.command;
      Serial.print("Command 0x");
      Serial.println(received_command, HEX); // Значение команды

      if (received_command == CMD_MOVE_FORWARD) { // Движение вперед
        digitalWrite(DIR_M1_PIN, LOW);
        digitalWrite(DIR_M2_PIN, LOW);
        analogWrite(PWM_M1_PIN, MOTORS_MAX_SPEED);
        analogWrite(PWM_M2_PIN, MOTORS_MAX_SPEED);
        Serial.println("Move Forward");
      }
      else if (received_command == CMD_MOVE_BACKWARD) { // Движение назад
        digitalWrite(DIR_M1_PIN, HIGH);
        digitalWrite(DIR_M2_PIN, HIGH);
        analogWrite(PWM_M1_PIN, MOTORS_MAX_SPEED);
        analogWrite(PWM_M2_PIN, MOTORS_MAX_SPEED);
        Serial.println("Move Backward");
      }
      else if (received_command == CMD_MOVE_LEFT) { // Движение влево
        digitalWrite(DIR_M1_PIN, HIGH);
        digitalWrite(DIR_M2_PIN, LOW);
        analogWrite(PWM_M1_PIN, MOTORS_MAX_SPEED);
        analogWrite(PWM_M2_PIN, MOTORS_MAX_SPEED);
        Serial.println("Move Left");
      }
      else if (received_command == CMD_MOVE_RIGHT) { // Движение вправо
        digitalWrite(DIR_M1_PIN, LOW);
        digitalWrite(DIR_M2_PIN, HIGH);
        analogWrite(PWM_M1_PIN, MOTORS_MAX_SPEED);
        analogWrite(PWM_M2_PIN, MOTORS_MAX_SPEED);
        Serial.println("Move Right");
      }
      else { // Остановить движение по любой иной команде (кнопке)
        analogWrite(PWM_M1_PIN, MOTORS_MIN_SPEED);
        analogWrite(PWM_M2_PIN, MOTORS_MIN_SPEED);
        Serial.println("Move End");
      }

      Serial.println();
    }
  }
}
