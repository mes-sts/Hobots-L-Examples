/*
 * hl_beginer_atmega2560_wifi_module_check
 * 
 * Проверка работы модуля WiFi HL Начальный
 *
 * КОД ДЛЯ ATMEGA2560
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Выводы светодиодов
const byte LED_2_PIN = 2;
const byte LED_3_PIN = 3;

// Константы команд управления состояниями светодиодов контроллера
const char led_2_on_cmd = '1';
const char led_2_off_cmd = '2';
const char led_3_on_cmd = '3';
const char led_3_off_cmd = '4';

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка скорости порта для связи с модулем WiFi
  Serial2.begin(115200);

  // Настройка выводов светодиодов на выход
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);

  // Принудительное выключение светодиодов
  digitalWrite(LED_2_PIN, LOW);
  digitalWrite(LED_3_PIN, LOW);
}

void loop() {
  // Проверка на наличие данных от WiFi модуля
  if (Serial2.available()) {
    // Считывание принятого байта данных
    char read_char = Serial2.read();
    Serial.write(read_char);
    Serial.write(" ");

    // Проверка принятого байта данных на соответсвие одной из команд
    if (read_char == led_2_on_cmd) {
      digitalWrite(LED_2_PIN, HIGH); // Включение светодиода LED_2
      Serial.println("LED_2 ON");
    }
    if (read_char == led_2_off_cmd) {
      digitalWrite(LED_2_PIN, LOW); // Выключение светодиода LED_2
      Serial.println("LED_2 OFF");
    }
    if (read_char == led_3_on_cmd) {
      digitalWrite(LED_3_PIN, HIGH); // Включение светодиода LED_3
      Serial.println("LED_3 ON");
    }
    if (read_char == led_3_off_cmd) {
      digitalWrite(LED_3_PIN, LOW); // Выключение светодиода LED_3
      Serial.println("LED_3 OFF");
    }
  }
}
