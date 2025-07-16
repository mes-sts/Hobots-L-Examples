/*
 * hl_x_module_imu_check
 * 
 * Проверка модуля гироскопа и акселерометра HL X
 * 
 * Ссылка на библиотеку микросхемы гироскопа/акселерометра https://github.com/adafruit/Adafruit_MPU6050
 * 
 * Инструменты → Плата → STM32 Boards Groups → Generic STM32F1 series
 * Инструменты → Board part number → Generic F103RETx
 * Инструменты → U(S)ART support → Enable (generic 'Serial')
 * Инструменты → USB support (if available) → CDC (generic 'Serial' supersede U(S)ART)
 * Инструменты → Upload method → HID Bootloader 2.2
 * 
 * Copyright (C) 2025. v1.1 / MES
 */

// Подключение файла библиотеки IMU
#include <Adafruit_MPU6050.h>
#include <Wire.h>
// Определение выводов второго I2C порта
#define I2C_2_SDA_PIN PB11
#define I2C_2_SCL_PIN PB10

// Создание объекта для работы со вторым I2C
TwoWire Wire2(I2C_2_SDA_PIN, I2C_2_SCL_PIN);

// Создание объекта для работы с IMU
Adafruit_MPU6050 mpu6050;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);
  Wire2.begin();
  // Попытка иницализации IMU с адресом 0x69 на втором I2C
  if (!mpu6050.begin(0x69, &Wire2, 0)) {
    Serial.println("MPU6050 Not Found!\n");
    while (1);
  }
  Serial.println("MPU6050 Found!\n");

  // Настройка диапазона акселерометра
  mpu6050.setAccelerometerRange(MPU6050_RANGE_8_G);
  // Настройка диапазона гироскопа
  mpu6050.setGyroRange(MPU6050_RANGE_500_DEG);
  // Настройка полосы пропускания IMU
  mpu6050.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  get_and_print_roll_pitch_yaw();
}

// Метод получения данных от датчика и вывод их в "Монитор порта"
void get_and_print_roll_pitch_yaw() {
  // Создание перменных для хранения значений
  sensors_event_t acc, gy, temp;
  // Получение значений
  mpu6050.getEvent(&acc, &gy, &temp);

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

  Serial.println();
}
