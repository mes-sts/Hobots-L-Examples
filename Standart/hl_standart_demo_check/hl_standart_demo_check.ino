/*
 * hl_standart_demo_check
 * 
 * Демонстрационнный скетч HL Стандарт
 * 
 * После нажатия на концевой прерыватель, начинается удержание
 * желаемого растояния до препятствия. После нажатия на
 * кнопку сброс, все начинается сначала
 * 
 * Ультразвуковой датчик расстояния подключен в разъем 5
 * Концевой прерыватель (кнопка) подключен в разъем 2
 * Мотры подключены в разъемы М1 и М2
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Вывод приема данных и управления датчиком
const int TRIG_PIN = 12;
const int ECHO_PIN = 13;
// Выводы направления моторов
const int DIR_M1_PIN = 7;
const int DIR_M2_PIN = 4;
// Выводы скорости моторов
const int PWM_M1_PIN = 6;
const int PWM_M2_PIN = 5;
// Вывод кнопки
const int BTN_PIN = 3;

// Желаемое расстояние удержания на месте
const int GOAL_DISTANCE_CM = 10;
// Интервал удержания на месте +- см
const int DELTA_CM = 2;

// Скорость звука при +20°С составляет 343м/с → 1 / 343м/с = 0,002915с → 0,002915с * 1000 = 2.915мс
const float t_sound_ms = 2.915;

// флаг клика по кнопке
bool btn_flag = true;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

  // Настройка выводов сонара
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  // Настройка выводов моторов
  pinMode(DIR_M1_PIN,OUTPUT);
  pinMode(DIR_M2_PIN,OUTPUT);
  pinMode(PWM_M1_PIN,OUTPUT);
  pinMode(PWM_M2_PIN,OUTPUT);
  // Настройка вывода кнопки
  pinMode(BTN_PIN, INPUT);
  // Сброс скорости моторов
  analogWrite(PWM_M1_PIN, 0);
  analogWrite(PWM_M2_PIN, 0);
}

void loop() {
  // Смена флага кликом по кнопке
  if (digitalRead(BTN_PIN) && btn_flag) {
    btn_flag = false;
  }

  // После клика по кнопке, выполняется код удержания дистанции
  if (!btn_flag) {
    // Переменные для хранения длительности импульса от сонара и расстояния
    long duration;
    float distance_cm;
  
    // Генерация импульса 10 микросекунд
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, HIGH);
  
    // Получение длительности отраженного импульса
    duration = pulseIn(ECHO_PIN, HIGH);
  
    // Пересчет длительности в растояние (см)
    distance_cm = ((duration / 2) / t_sound_ms) / 10.0;
    
    Serial.print("Distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");
  
    if (distance_cm > GOAL_DISTANCE_CM + DELTA_CM) { // Движение на припятствие когда расстояние больше заданного
      digitalWrite(DIR_M1_PIN, LOW);
      digitalWrite(DIR_M2_PIN, LOW);
      analogWrite(PWM_M1_PIN, 150);
      analogWrite(PWM_M2_PIN, 150);
      Serial.println("Moving Forward");
    }
    else if (distance_cm < GOAL_DISTANCE_CM - DELTA_CM) { // Движение от препятствия когда расстояние меньше заданного
      digitalWrite(DIR_M1_PIN, HIGH);
      digitalWrite(DIR_M2_PIN, HIGH);
      analogWrite(PWM_M1_PIN, 150);
      analogWrite(PWM_M2_PIN, 150);
      Serial.println("Moving Backwards");
    }
    else { // Остановка моторов если попали в желаемый диапазон
      analogWrite(PWM_M1_PIN, 0);
      analogWrite(PWM_M2_PIN, 0);
      Serial.println("Moving Stop");
    }
    
    delay(50); // >30 для подавления эффекта эхо сонара
  }
  
}
