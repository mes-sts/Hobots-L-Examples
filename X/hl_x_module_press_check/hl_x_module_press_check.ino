/*
 * hl_x_module_press_check
 * 
 * Проверка модуля датчика нажатия HL X
 * 
 * Инструменты → Плата → STM32 Boards Groups → Generic STM32F1 series
 * Инструменты → Board part number → Generic F103RETx
 * Инструменты → U(S)ART support → Enable (generic 'Serial')
 * Инструменты → USB support (if available) → CDC (generic 'Serial' supersede U(S)ART)
 * Инструменты → Upload method → HID Bootloader 2.2
 * 
 * Copyright (C) 2025. v1.0 / MES
 */

// Вывод датчика нажатия
const uint8_t SENSOR_PRESS_PIN = PC2;
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка вывода датчика нажатия на вход
  pinMode(SENSOR_PRESS_PIN, INPUT);
}

void loop() {
  // Вывод информации о состоянии датчика нажатия
  Serial.print("Sensor State: "); Serial.println(digitalRead(SENSOR_PRESS_PIN));
  Serial.println();
  delay(50);
}
