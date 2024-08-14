/*
 * hl_ultra_leds_check
 * 
 * Проверка светодиодов HL Ультра
 * 
 * Инструменты → Плата → STM32 Boards Groups → Generic STM32F1 series
 * Инструменты → Board part number → Generic F103RCTx
 * Инструменты → U(S)ART support → Enable (generic 'Serial')
 * Инструменты → USB support (if available) → CDC (generic 'Serial' supersede U(S)ART)
 * Инструменты → Upload method → HID Bootloader 2.2
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Макросы выводов светодиодов
#define L1_PIN PB4
#define L2_PIN PB5
#define L3_PIN PB3

// Массив для удобства работы со светодиодами
const byte LEDS[3] = {
  L1_PIN,
  L2_PIN,
  L3_PIN,
};
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка выводов светодиодов на выход
  for (byte i = 0; i <= 2; i++) {
    pinMode(LEDS[i], OUTPUT);
    digitalWrite(LEDS[i], LOW); // Принудительное выключение светодиодов
    Serial.print("LED "); Serial.print(i); Serial.println(" Mode OUTPUT");
  }
  Serial.println();
}

void loop() {
  // Поочередное включение светодиодов
  for (byte i = 0; i <= 2; i++) {
    digitalWrite(LEDS[i], HIGH);
    Serial.print("LED "); Serial.print(i); Serial.println(" State HIGH");
    delay(200);
  }
  Serial.println();
  delay(1000);
  
  // Поочередное выключение светодиодов
  for (byte i = 0; i <= 2; i++) {
    digitalWrite(LEDS[i], LOW);
    Serial.print("LED "); Serial.print(i); Serial.println(" State LOW");
    delay(200);
  }
  Serial.println();
  delay(1000);
}
