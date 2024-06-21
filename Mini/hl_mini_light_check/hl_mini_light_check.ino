/*
 * hl_mini_light_check
 * 
 * Проверка встроенного датчика освещенности HL Мини
 * 
 * Фоторезистор GL5528 10кОм, установлен в верхнем плече делителя (R1).
 * В нижнее плечо делителя установлен резистор 47кОм (R2).
 * Входное сопротивление АЦП микроконтроллера 55МОм - 100МОм (R3).
 * Напряжение питания делителя 5В.
 * 
 * Формулы расчета напряжения на делителе
 * Формула в общем виде без учета сопротивления АЦП Vo = Vi * (R2 / (R1 + R2))
 * Формула в общем виде с учетом сопротивления АЦП Vo = Vi * ((1 / ((1 / R2) + (1 / R3))) / (R1 + (1 / ((1 / R2) + (1 / R3)))))
 * 
 * формула перевода значений АЦП в напряжение Vo = ADC * (Vref / 2^n)
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2024. v1.0 / MES
 */


// Вывод фоторезистора
const int LIGHT_SENSOR_PIN = A6;

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

  delay(50);
}
