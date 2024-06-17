/*
 * hl_mini_button_check
 * 
 * Проверка пользовательской кнопки HL Мини
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2024. v1.0 / MES
 */


// Вывод кнопки
const int BUTTON_PIN = A7;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

  // Настройка вывода кнопки на вход
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  // Получение аналогового значения с вывода кнопки и проверка на 0 (0 - кнопка нажата)
  if (!analogRead(BUTTON_PIN)) {
    Serial.println("Button PRESSED");
  }
  else {
    Serial.println("Button RELEASED");
  }
  delay(20);
}
