/*
 * hl_ultra_gyro_check
 * 
 * Проверка встроенного гироскопа HL Ультра
 * 
 * Ссылка на библиотеку гироскопа https://github.com/hideakitai/MPU9250
 * 
 * Инструменты → Плата → STM32 Boards Groups → Generic STM32F1 series
 * Инструменты → Board part number → Generic F103RCTx
 * Инструменты → U(S)ART support → Enable (generic 'Serial')
 * Инструменты → USB support (if available) → CDC (generic 'Serial' supersede U(S)ART)
 * Инструменты → Upload method → HID Bootloader 2.2
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Подключение файла с библиотеки для гироскопа
#include <MPU9250.h>

// Создание объекта для работы с гироскопом
MPU9250 mpu;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка выводов I2C интерфейса
  Wire.setSDA(PB7);
  Wire.setSCL(PB6);
  // Запуск шины I2C
  Wire.begin();
  delay(2000);

  // Указание адреса на шине I2C
  mpu.setup(0x68);
  delay(5000);

  // Калибровка гироскопа и акселерометра
  mpu.calibrateAccelGyro();
}

void loop() {
  // Проверка на наличие данных
  if (mpu.update()) {
    static uint32_t prev_ms = millis();
    if (millis() > prev_ms + 25) {
      get_and_print_roll_pitch_yaw();
      prev_ms = millis();
    }
  }
}

// Метод получения данных от датчика и вывод их в "Монитор порта"
void get_and_print_roll_pitch_yaw() {
  Serial.print("Yaw, Pitch, Roll: ");
  Serial.print(mpu.getYaw(), 2);
  Serial.print(", ");
  Serial.print(mpu.getPitch(), 2);
  Serial.print(", ");
  Serial.println(mpu.getRoll(), 2);
}
