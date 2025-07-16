/*
 * hl_x_module_line_a_check
 * 
 * Проверка модуля датчика линии А HL X
 * 
 * Инструменты → Плата → STM32 Boards Groups → Generic STM32F1 series
 * Инструменты → Board part number → Generic F103RETx
 * Инструменты → U(S)ART support → Enable (generic 'Serial')
 * Инструменты → USB support (if available) → CDC (generic 'Serial' supersede U(S)ART)
 * Инструменты → Upload method → HID Bootloader 2.2
 * 
 * Copyright (C) 2025. v1.0 / MES
 */

// Вывод датчика линии
const uint8_t SENSOR_LINE_A_PIN = PA5;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Включение 12-ти битного разрешения АЦП (по умолчанию 8 бит)
  analogReadResolution(12);

  // Настройка вывода датчика на вход
  pinMode(SENSOR_LINE_A_PIN, INPUT);
}

void loop() {
  // Получение значения от датчика линии
  uint16_t line_a_value = analogRead(SENSOR_LINE_A_PIN);

  // Вывод значения в Монитор порта
  Serial.print("Line A: "); Serial.println(line_a_value);
  
  delay(20);
}
