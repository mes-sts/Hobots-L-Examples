/*
 * hl_mini_button_check
 * 
 * Проверка пользовательской кнопки HL Мини
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2024. v1.1 / MES
 */


// Вывод кнопки
const int BUTTON_PIN = A7;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

  // Настройка вывода кнопки на вход
  pinMode(BUTTON_PIN, INPUT);
}

bool checkUserButtonState() {
  // Получение аналогового значения с вывода кнопки и проверка на 0 (значение < 512 - кнопка нажата)
  if (analogRead(BUTTON_PIN) > 512) {
    return false; // Отпущена
  }
  else {
    return true; // Нажата
  }
}

void loop() {
  if (checkUserButtonState()) {
    Serial.println("Button PRESSED");
  }
  else {
    Serial.println("Button RELEASED");
  }
  delay(20);
}
