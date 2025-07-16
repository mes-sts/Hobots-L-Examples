/*
 * hl_x_controller_buttons_check
 * 
 * Проверка кнопок контроллера HL X
 * 
 * Инструменты → Плата → STM32 Boards Groups → Generic STM32F1 series
 * Инструменты → Board part number → Generic F103RETx
 * Инструменты → U(S)ART support → Enable (generic 'Serial')
 * Инструменты → USB support (if available) → CDC (generic 'Serial' supersede U(S)ART)
 * Инструменты → Upload method → HID Bootloader 2.2
 * 
 * Copyright (C) 2025. v1.0 / MES
 */

// Выводы кнопок
const uint8_t BTN_UP_PIN = PA15;
const uint8_t BTN_DOWN_PIN = PB3;
const uint8_t BTN_CENTER_PIN = PD2;
const uint8_t BTN_LEFT_PIN = PC14;
const uint8_t BTN_RIGHT_PIN = PB4;
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка выводов кнопок на вход
  pinMode(BTN_UP_PIN, INPUT);
  pinMode(BTN_DOWN_PIN, INPUT);
  pinMode(BTN_CENTER_PIN, INPUT);
  pinMode(BTN_LEFT_PIN, INPUT);
  pinMode(BTN_RIGHT_PIN, INPUT);
}

void loop() {
  // Вывод информации о состоянии кнопок
  Serial.print("Button UP: "); Serial.println(digitalRead(BTN_UP_PIN));
  Serial.print("Button DOWN: "); Serial.println(digitalRead(BTN_DOWN_PIN));
  Serial.print("Button CENTER: "); Serial.println(digitalRead(BTN_CENTER_PIN));
  Serial.print("Button LEFT: "); Serial.println(digitalRead(BTN_LEFT_PIN));
  Serial.print("Button RIGHT: "); Serial.println(digitalRead(BTN_RIGHT_PIN));
  Serial.println();
  delay(100);
}
