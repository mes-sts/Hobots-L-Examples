/*
 * hl_x_module_line_d_check
 * 
 * Проверка модуля датчика линии D HL X
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
const uint8_t SENSOR_LINE_D_PIN = PC1;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка выводов датчика на вход
  pinMode(SENSOR_LINE_D_PIN, INPUT);
}

void loop() {
  // Получение значения от датчика линии
  bool line_d_value = digitalRead(SENSOR_LINE_D_PIN);

  // Вывод значения в Монитор порта
  Serial.print("Line D: "); Serial.print(line_d_value);

  if (line_d_value) {
    Serial.println(" , BLACK");
  }
  else {
    Serial.println(" , WHITE");
  }
  
  delay(20);
}
