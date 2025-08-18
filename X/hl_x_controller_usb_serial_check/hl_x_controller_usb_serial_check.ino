/*
 * hl_x_controller_usb_serial_check
 * 
 * Проверка USB Serial контроллера HL X
 * 
 * Инструменты → Плата → STM32 Boards Groups → Generic STM32F1 series
 * Инструменты → Board part number → Generic F103RETx
 * Инструменты → U(S)ART support → Enable (generic 'Serial')
 * Инструменты → USB support (if available) → CDC (generic 'Serial' supersede U(S)ART)
 * Инструменты → Upload method → HID Bootloader 2.2
 * 
 * Copyright (C) 2025. v1.0 / MES
 */
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);
}

void loop() {
  // Вывод информации
  Serial.println("Hello HL X");
  delay(500);
}
