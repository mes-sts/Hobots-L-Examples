/*
 * hl_x_module_beeper_check
 * 
 * Проверка модуля ультразвукового датчика расстояния HL X
 * 
 * Инструменты → Плата → STM32 Boards Groups → Generic STM32F1 series
 * Инструменты → Board part number → Generic F103RETx
 * Инструменты → U(S)ART support → Enable (generic 'Serial')
 * Инструменты → USB support (if available) → CDC (generic 'Serial' supersede U(S)ART)
 * Инструменты → Upload method → HID Bootloader 2.2
 * 
 * Copyright (C) 2025. v1.0 / MES
 */

// Вывод приема данных и управления датчиком
const uint8_t TRIG_PIN = PA0;
const uint8_t ECHO_PIN = 4;

// Коэффициент (степень) фильтрации 0.0 - 1.0
const float k_filt = 0.2;

// Скорость звука при +20°С составляет 343м/с → 1 / 343м/с = 0,002915с → 0,002915с * 1000 = 2.915мс
const float t_sound_ms = 2.915;

// Переменная для хранения отфильтрованного значения длительности
float duration_filtred = 0;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка выводов сонара
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Переменные для хранения длительности и расстояния
  long duration, distance_mm;
  float distance_cm, distance_m;

  // Генерация импульса 10 микросекунд
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(4);

  // Получение длительности отраженного импульса
  duration = pulseIn(ECHO_PIN, HIGH);

  // Фильтрация длительности при помощи экспоненциального фильтра (скользящее среднее, moving average)
  duration_filtred += (duration - duration_filtred) * k_filt;

  // Пересчет длительности в растояние (мм, см, м)
  distance_mm = (duration_filtred / 2) / t_sound_ms;
  distance_cm = distance_mm / 10.0;
  distance_m = distance_cm / 100.0;
  
  Serial.print("Distance: ");
  Serial.print(distance_mm);
  Serial.print(" mm, ");
  Serial.print(distance_cm);
  Serial.print(" cm, ");
  Serial.print(distance_m);
  Serial.println(" m");
  
  delay(100); // >30 для подавления эффекта эхо
}
