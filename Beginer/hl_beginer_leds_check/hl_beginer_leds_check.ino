/*
 * hl_beginer_leds_check
 * 
 * Проверка светодиодов HL Начальный
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Макросы выводов светодиодов
#define LED_2_PIN 2
#define LED_3_PIN 3

// Массив для удобства работы со светодиодами
const byte LED_PINS[2] = {
  LED_2_PIN,
  LED_3_PIN
};
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка выводов светодиодов на выход
  for (byte i = 0; i <= 1; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW); // Принудительное выключение светодиодов
    Serial.print("LED "); Serial.print(i); Serial.println(" Mode OUTPUT");
  }
  Serial.println();
}

void loop() {
  // Поочередное включение светодиодов
  for (byte i = 0; i <= 1; i++) {
    digitalWrite(LED_PINS[i], HIGH);
    Serial.print("LED "); Serial.print(i); Serial.println(" State HIGH");
    delay(200);
  }
  Serial.println();
  delay(1000);
  
  // Поочередное выключение светодиодов
  for (byte i = 0; i <= 1; i++) {
    digitalWrite(LED_PINS[i], LOW);
    Serial.print("LED "); Serial.print(i); Serial.println(" State LOW");
    delay(200);
  }
  Serial.println();
  delay(1000);
}
