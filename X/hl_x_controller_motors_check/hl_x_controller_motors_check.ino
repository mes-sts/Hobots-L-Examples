/*
 * hl_x_controller_motors_check
 * 
 * Проверка моторов контроллера HL X
 * 
 * Инструменты → Плата → STM32 Boards Groups → Generic STM32F1 series
 * Инструменты → Board part number → Generic F103RETx
 * Инструменты → U(S)ART support → Enable (generic 'Serial')
 * Инструменты → USB support (if available) → CDC (generic 'Serial' supersede U(S)ART)
 * Инструменты → Upload method → HID Bootloader 2.2
 * 
 * Copyright (C) 2025. v1.0 / MES
 */

// Выводы мотора M1
const uint8_t INA_M1_PIN = PC6;
const uint8_t INB_M1_PIN = PC7;
// Выводы мотора M2
const uint8_t INC_M2_PIN = PC8;
const uint8_t IND_M2_PIN = PC9;
// Выводы мотора M3
const uint8_t INC_M3_PIN = PB8;
const uint8_t IND_M3_PIN = PB9;
// Выводы мотора M4
const uint8_t INA_M4_PIN = PB6;
const uint8_t INB_M4_PIN = PB7;

const uint8_t PWM_VAL_MIN = 0;
const uint8_t PWM_VAL_MID = 150;
const uint8_t PWM_VAL_MAX = 255;
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);
  // Настройка всех выводов на выход
  pinMode(INA_M1_PIN, OUTPUT);
  pinMode(INB_M1_PIN, OUTPUT);
  pinMode(INC_M2_PIN, OUTPUT);
  pinMode(IND_M2_PIN, OUTPUT);
  pinMode(INC_M3_PIN, OUTPUT);
  pinMode(IND_M3_PIN, OUTPUT);
  pinMode(INA_M4_PIN, OUTPUT);
  pinMode(INB_M4_PIN, OUTPUT);
  // Остановка и отпускаиние валов моторов
  analogWrite(INA_M1_PIN, PWM_VAL_MIN);
  analogWrite(INB_M1_PIN, PWM_VAL_MIN);
  analogWrite(INC_M2_PIN, PWM_VAL_MIN);
  analogWrite(IND_M2_PIN, PWM_VAL_MIN);
  analogWrite(INC_M3_PIN, PWM_VAL_MIN);
  analogWrite(IND_M3_PIN, PWM_VAL_MIN);
  analogWrite(INA_M4_PIN, PWM_VAL_MIN);
  analogWrite(INB_M4_PIN, PWM_VAL_MIN);
}

void loop() {
  Serial.println("Motors Case 1");
  // Первое направление
  analogWrite(INA_M1_PIN, PWM_VAL_MIN);
  analogWrite(INB_M1_PIN, PWM_VAL_MAX);
  analogWrite(INC_M2_PIN, PWM_VAL_MIN);
  analogWrite(IND_M2_PIN, PWM_VAL_MAX);
  analogWrite(INC_M3_PIN, PWM_VAL_MIN);
  analogWrite(IND_M3_PIN, PWM_VAL_MAX);
  analogWrite(INA_M4_PIN, PWM_VAL_MIN);
  analogWrite(INB_M4_PIN, PWM_VAL_MAX);
  delay(1000);

  // Второе направление
  Serial.println("Motors Case 2");
  analogWrite(INA_M1_PIN, PWM_VAL_MAX);
  analogWrite(INB_M1_PIN, PWM_VAL_MIN);
  analogWrite(INC_M2_PIN, PWM_VAL_MAX);
  analogWrite(IND_M2_PIN, PWM_VAL_MIN);
  analogWrite(INC_M3_PIN, PWM_VAL_MAX);
  analogWrite(IND_M3_PIN, PWM_VAL_MIN);
  analogWrite(INA_M4_PIN, PWM_VAL_MAX);
  analogWrite(INB_M4_PIN, PWM_VAL_MIN);
  delay(1000);
}
