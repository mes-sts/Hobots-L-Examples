/*
 * hl_mini_external_light_check
 * 
 * Проверка внешнего датчика освещенности (Модуля) HL Мини
 * 
 * Модуль датчика освещенности подключен в PORT4
 * Датчик основан на фототранзисторе
 * 
 * формула перевода значений АЦП в напряжение Vo = ADC * (Vref / 2^n)
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2024. v1.0 / MES
 */


// Вывод датчика
const int LIGHT_SENSOR_PIN = A2;

// Напряжение питания микроконтроллера и АЦП
const float POWER_SUPPLY_V = 5.0;

// Разрядность АЦП
const int BIT_DEPTH_ADC = 1024; // 2^10

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

  // Настройка вывода датчика освещености на вход
  pinMode(LIGHT_SENSOR_PIN, INPUT);
}

void loop() {
  // Получение оцифрованного значения на датчике освещенности
  word light_sensor_value = analogRead(LIGHT_SENSOR_PIN);
  // Перевод оцифрованного значения в напряжение
  float light_sensor_voltage = light_sensor_value * (POWER_SUPPLY_V / BIT_DEPTH_ADC);
  
  Serial.print("Light ADC ");
  Serial.println(light_sensor_value);
  Serial.print("Light V ");
  Serial.println(light_sensor_voltage);
  Serial.println();

  delay(100);
}
