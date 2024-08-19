/*
 * hl_ultra_serial_bus_servo_check
 * 
 * Проверка интеллектуальных сервоприводов HL Ультра
 *
 * Ссылка на библиотеку для интеллектуальных сервоприводов https://files.waveshare.com/upload/d/d8/ST_Servo.zip
 * 
 * Инструменты → Плата → STM32 Boards Groups → Generic STM32F1 series
 * Инструменты → Board part number → Generic F103RCTx
 * Инструменты → U(S)ART support → Enable (generic 'Serial')
 * Инструменты → USB support (if available) → CDC (generic 'Serial' supersede U(S)ART)
 * Инструменты → Upload method → HID Bootloader 2.2
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Подключение файла с библиотеки
#include <SCServo.h>

// Создание объекта для работы с сервоприводом. PA9 - вывод полудуплексмного UART
HardwareSerial Serial1(PA9);

const uint8_t SERVO_ID = 1;
const uint32_t BUS_BAUDRATE = 1000000;

// Создание объекта для работы с сервоприводом
SMS_STS sts3215;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);
  
  // Настройка интерфейса сервоприводов
  Serial1.begin(BUS_BAUDRATE);
  sts3215.pSerial = &Serial1;
  delay(1000);
}

void loop() {
  Serial.println("Move to 1st position: 4095");
  sts3215.WritePosEx(SERVO_ID, 4095, 5000, 100);// ID1=1，position=4095, speed=5000，acc=100.
  delay(3000);
  
  Serial.println("Move to 2st position: 0");
  sts3215.WritePosEx(SERVO_ID, 0, 5000, 100);// ID1=1，position=0, speed=5000，acc=100.
  delay(3000);
}