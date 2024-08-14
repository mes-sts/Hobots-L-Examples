/*
 * hl_ultra_buttons_check
 * 
 * Проверка Кнопок HL Ультра
 * 
 * Инструменты → Плата → STM32 Boards Groups → Generic STM32F1 series
 * Инструменты → Board part number → Generic F103RCTx
 * Инструменты → U(S)ART support → Enable (generic 'Serial')
 * Инструменты → USB support (if available) → CDC (generic 'Serial' supersede U(S)ART)
 * Инструменты → Upload method → HID Bootloader 2.2
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Выводы кнопок
const int BTN1_PIN = PC4;
const int BTN2_PIN = PC5;
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка выводов кнопок на вход c подтяжкой к питанию
  pinMode(BTN1_PIN, INPUT);
  pinMode(BTN2_PIN, INPUT);
}

void loop() {
  // Вывод информации о состоянии кнопок
  Serial.print("Button 1 State = "); Serial.println(digitalRead(BTN1_PIN));
  Serial.print("Button 2 State = "); Serial.println(digitalRead(BTN2_PIN));
  Serial.println();
  delay(50);
}
