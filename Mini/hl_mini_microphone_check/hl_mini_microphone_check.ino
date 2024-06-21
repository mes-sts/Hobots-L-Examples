/*
 * hl_mini_microphone_check
 * 
 * Проверка датчика звука (Модуля) HL Мини
 * 
 * Модуль датчика звука подключен в PORT3
 * Датчик основан на капсульном микрофоне
 * 
 * формула перевода значений АЦП в напряжение Vo = ADC * (Vref / 2^n)
 * 
 * Удобно смотреть через Инструменты → Плоттер по последовательному соединению
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Раскоментировать строку #define USING_PLOTTER, для использования с Плоттером по последовательному соединению
//#define USING_PLOTTER

// Вывод датчика звука
const int SOUND_SENSOR_PIN = A0;

// Напряжение питания микроконтроллера и АЦП
const float POWER_SUPPLY_V = 5.0;

// Разрядность АЦП
const int BIT_DEPTH_ADC = 1024; // 2^10

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

  // Настройка вывода датчика звука на вход
  pinMode(SOUND_SENSOR_PIN, INPUT);

#ifdef USING_PLOTTER
  // Имена графиков в плоттере
  Serial.println("Sound_ADC, Sound_V");
#endif
}

void loop() {
  // Получение оцифрованного значения на датчике звука
  word sound_sensor_value = analogRead(SOUND_SENSOR_PIN);
  // Перевод оцифрованного значения в напряжение
  float sound_sensor_voltage = sound_sensor_value * (POWER_SUPPLY_V / BIT_DEPTH_ADC);

#ifdef USING_PLOTTER
// Вывод если используется Плоттер
  Serial.print(sound_sensor_value);
  Serial.print(',');
  Serial.println(sound_sensor_voltage);
  Serial.println();
  delay(10);
#else 
  // Вывод если НЕ используется Плоттер
  Serial.print("Sound ADC ");
  Serial.println(sound_sensor_value);
  Serial.print("Sound V ");
  Serial.println(sound_sensor_voltage);
  Serial.println();
  delay(100);
#endif
}
