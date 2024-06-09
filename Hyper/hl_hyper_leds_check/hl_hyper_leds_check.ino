/*
 * hl_hyper_leds_check
 * 
 * Проверка кнопок HL Гипер
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Макросы выводов светодиодов
#define LED_0_PIN 22
#define LED_1_PIN 23
#define LED_2_PIN 24
#define LED_3_PIN 25
#define LED_4_PIN 26
#define LED_5_PIN 27
#define LED_6_PIN 28
#define LED_7_PIN 29

// Массив для удобства работы со светодиодами
const byte LED_PINS[8] = {
  LED_0_PIN,
  LED_1_PIN,
  LED_2_PIN,
  LED_3_PIN,
  LED_4_PIN,
  LED_5_PIN,
  LED_6_PIN,
  LED_7_PIN
};
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка выводов светодиодов на выход
  for (byte i = 0; i <= 7; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW); // Принудительное выключение светодиодов
    Serial.print("LED "); Serial.print(i); Serial.println(" Mode OUTPUT");
  }
  Serial.println();
}

void loop() {
  // Поочередное включение светодиодов
  for (byte i = 0; i <= 7; i++) {
    digitalWrite(LED_PINS[i], HIGH);
    Serial.print("LED "); Serial.print(i); Serial.println(" State HIGH");
    delay(200);
  }
  Serial.println();
  delay(1000);
  
  // Поочередное выключение светодиодов
  for (byte i = 0; i <= 7; i++) {
    digitalWrite(LED_PINS[i], LOW);
    Serial.print("LED "); Serial.print(i); Serial.println(" State LOW");
    delay(200);
  }
  Serial.println();
  delay(1000);
}
