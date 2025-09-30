/*
 * hl_classic_module_button_check
 * 
 * Проверка модуля концевого прерывателя (датчик нажатия) ХЛ Классический
 * 
 * Кнопка подключена в разъем 2
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2025. v1.0 / MES
 */


// Вывод кнопки
const int BUTTON_PIN = 7;

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
  delay(300);
}
