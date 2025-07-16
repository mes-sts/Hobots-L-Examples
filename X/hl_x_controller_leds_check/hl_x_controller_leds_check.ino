/*
 * hl_x_controller_leds_check
 * 
 * Проверка светодиодов контроллера HL X
 * 
 * Инструменты → Плата → STM32 Boards Groups → Generic STM32F1 series
 * Инструменты → Board part number → Generic F103RETx
 * Инструменты → U(S)ART support → Enable (generic 'Serial')
 * Инструменты → USB support (if available) → CDC (generic 'Serial' supersede U(S)ART)
 * Инструменты → Upload method → HID Bootloader 2.2
 * 
 * Copyright (C) 2025. v1.0 / MES
 */

// Макросы выводов светодиодов
#define LED_1_PIN PC15
#define LED_2_PIN PA8
#define LED_3_PIN PB5

// Массив для удобства работы со светодиодами
const uint8_t LEDS[3] = {
  LED_1_PIN,
  LED_2_PIN,
  LED_3_PIN,
};
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка выводов светодиодов на выход
  for (byte i = 0; i <= 2; i++) {
    pinMode(LEDS[i], OUTPUT);
    digitalWrite(LEDS[i], LOW); // Принудительное выключение светодиодов
  }
}

void loop() {
  // Поочередное включение светодиодов
  for (byte i = 0; i <= 2; i++) {
    digitalWrite(LEDS[i], HIGH);
    Serial.print("LED "); Serial.print(i); Serial.println(" is HIGH");
    delay(200);
  }
  Serial.println();
  delay(1000);
  
  // Поочередное выключение светодиодов
  for (byte i = 0; i <= 2; i++) {
    digitalWrite(LEDS[i], LOW);
    Serial.print("LED "); Serial.print(i); Serial.println(" is LOW");
    delay(200);
  }
  Serial.println();
  delay(1000);
}
