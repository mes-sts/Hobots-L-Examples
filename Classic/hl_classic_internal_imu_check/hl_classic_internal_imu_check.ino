/*
 * hl_classic_internal_imu_check
 * 
 * Проверка встроенного гироскопа / акселерометра ХЛ Классический
 * 
 * Ссылка на библиотеку гироскопа https://github.com/adafruit/Adafruit_MPU6050
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2025. v1.0 / MES
 */

// Подключение файла с библиотеки для гироскопа
#include <Adafruit_MPU6050.h>

// Создание объекта для работы с гироскопом
Adafruit_MPU6050 MPU;

// Адрес на шине i2c встроенного датчики
const uint8_t IMU_INTERNAL_I2C_ADDR = 0x69;
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

  // Попытка иницализации объекта с указанием адреса датчика
  if (!MPU.begin(IMU_INTERNAL_I2C_ADDR)) {
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

  delay(500);
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
