/*
 * hl_mini_sonar_check
 * 
 * Проверка ультразвокового датчика расстояния (сонара) HL Мини
 * 
 * Ультразвуковой датчик расстояния подключен в PORT2
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Вывод приема данных и управления датчиком
const int TRIG_PIN = 12;
const int ECHO_PIN = 11;

// Коэффициент (степень) фильтрации 0.0 - 1.0
const float k_filt = 0.2;

// Скорость звука при +20°С составляет 343м/с → 1 / 343м/с = 0,002915с → 0,002915с * 1000 = 2.915мс
const float t_sound_ms = 2.915;

// Переменная для хранения отфильтрованного значения длительности
float duration_filtred = 0;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

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
