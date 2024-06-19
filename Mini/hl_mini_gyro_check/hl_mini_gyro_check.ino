/*
 * hl_mini_gyro_check
 * 
 * Проверка модуля гироскопа HL Мини
 * 
 * Ссылка на библиотеку гироскопа https://github.com/adafruit/Adafruit_MPU6050
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Подключение файла с библиотеки для гироскопа
#include <Adafruit_MPU6050.h>

// Создание объекта для работы с гироскопом
Adafruit_MPU6050 MPU;
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

  // Попытка иницализации объекта
  if (!MPU.begin()) {
    Serial.println("MPU6050 Not Found!\n");
    while (1);
  }
  Serial.println("MPU6050 Found!\n");
  
  // Настройка диапазона акселерометра
  MPU.setAccelerometerRange(MPU6050_RANGE_8_G);
  // Настройка диапазона гироскопа
  MPU.setGyroRange(MPU6050_RANGE_500_DEG);
  // Настройка полосы пропускания
  MPU.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(100);
}

void loop() {
  // Создание перменных для хранения событий
  sensors_event_t acc, gy, temp;
  // Получение событий
  MPU.getEvent(&acc, &gy, &temp);

  Serial.print("Acceleration X: ");
  Serial.print(acc.acceleration.x); // Ускорение по оси X
  Serial.print(", Y: ");
  Serial.print(acc.acceleration.y); // Ускорение по оси Y
  Serial.print(", Z: ");
  Serial.print(acc.acceleration.z); // Ускорение по оси Z
  Serial.println(" m/s^2");

  Serial.print("Rotation X: ");
  Serial.print(gy.gyro.x); // Вращение по оси X
  Serial.print(", Y: ");
  Serial.print(gy.gyro.y); // Вращение по оси Y
  Serial.print(", Z: ");
  Serial.print(gy.gyro.z); // Вращение по оси Z
  Serial.println(" rad/s");

  Serial.print("Temperature: ");
  Serial.print(temp.temperature); // Температура в градусах Цельсия
  Serial.println(" degC");

  Serial.println("");
  delay(500);
}
