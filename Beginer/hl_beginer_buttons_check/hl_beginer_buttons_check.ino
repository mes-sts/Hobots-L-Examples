/*
 * hl_beginer_buttons_check
 * 
 * Проверка кнопок HL Начальный
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Выводы кнопок
const int BTN_36_PIN = 36;
const int BTN_37_PIN = 37;
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка выводов кнопок на вход c подтяжкой к питанию
  pinMode(BTN_36_PIN, INPUT_PULLUP);
  pinMode(BTN_37_PIN, INPUT_PULLUP);
}

void loop() {
  // Вывод информации о состоянии кнопок
  Serial.print("Button 36 State = "); Serial.println(digitalRead(BTN_36_PIN));
  Serial.print("Button 37 State = "); Serial.println(digitalRead(BTN_37_PIN));
  Serial.println();
  delay(50);
}
