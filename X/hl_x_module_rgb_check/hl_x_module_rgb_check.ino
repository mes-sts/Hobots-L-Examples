/*
 * hl_x_module_rgb_check
 * 
 * Проверка модуля светотдиода RGB HL X
 * 
 * Инструменты → Плата → STM32 Boards Groups → Generic STM32F1 series
 * Инструменты → Board part number → Generic F103RETx
 * Инструменты → U(S)ART support → Enable (generic 'Serial')
 * Инструменты → USB support (if available) → CDC (generic 'Serial' supersede U(S)ART)
 * Инструменты → Upload method → HID Bootloader 2.2
 * 
 * Copyright (C) 2025. v1.0 / MES
 */

// Выводы управления цветовыми каналами
const uint8_t CH_RED_PIN = PC2;
const uint8_t CH_GREEN_PIN = PC1;
const uint8_t CH_BLUE_PIN = PC0;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка выводов цветовых каналов на выход
  pinMode(CH_RED_PIN, OUTPUT);
  pinMode(CH_GREEN_PIN, OUTPUT);
  pinMode(CH_BLUE_PIN, OUTPUT);

  // Принудительное выключение яркости
  setColorRGB(0, 0, 0);
}

void loop() {
  // Перключение цветов светодиода
  setColorRGB(255, 0, 0); // Красный
  Serial.println("RED");
  delay(500);
  setColorRGB(0,  255, 0); // Зеленый
  Serial.println("GREEN");
  delay(500);
  setColorRGB(0, 0, 255); // Синий
  Serial.println("BLUE");
  delay(500);
  setColorRGB(255, 255, 255); // Белый
  Serial.println("WHITE");
  delay(500);
  setColorRGB(170, 0, 255); // Фиолетовый
  Serial.println("PURPLE");
  delay(500);
}

void setColorRGB(uint8_t ch_red_value, uint8_t ch_green_value,  uint8_t ch_blue_value) {
  analogWrite(CH_RED_PIN, ch_red_value);
  analogWrite(CH_GREEN_PIN, ch_green_value);
  analogWrite(CH_BLUE_PIN, ch_blue_value);
}
