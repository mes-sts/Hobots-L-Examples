/*
 * hl_standart_button_check
 * 
 * Проверка концевого прерывателя (кнопки) HL Стандарт
 * 
 * Кнопка подключена в разъем 2
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2024. v1.0 / MES
 */


// Вывод кнопки
const int BUTTON_PIN = 3;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

  // Настройка вывода кнопки на вход
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  if (digitalRead(BUTTON_PIN)) {
    Serial.println("Button PRESSED");
  }
  else {
    Serial.println("Button RELEASED");
  }
  delay(20);
}
