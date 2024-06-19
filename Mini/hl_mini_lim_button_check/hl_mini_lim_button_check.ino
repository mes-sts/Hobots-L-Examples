/*
 * hl_mini_lim_button_check
 * 
 * Проверка концевого прерывателя HL Мини
 * 
 * Кнопка подключена в PORT1
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2024. v1.0 / MES
 */


// Вывод концевого прерывателя
const int LIM_BUTTON_PIN = 8;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

  // Настройка вывода концевого прерывателя на вход
  pinMode(LIM_BUTTON_PIN, INPUT);
}

void loop() {
  if (digitalRead(LIM_BUTTON_PIN)) {
    Serial.println("Lim Button PRESSED");
  }
  else {
    Serial.println("Lim Button RELEASED");
  }
  delay(20);
}
