/*
 * hl_mini_joystick_ps2_check
 * 
 * Проверка джойстика DualShock PS2 HL Мини
 * 
 * Модуль приёмопередатчика джойстика подключен в разъем WIRELLESS MODULE
 * 
 * Ссылка на библиотеку для работы с джойстиком https://github.com/simondlevy/PS2X_lib/tree/master
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Подключение библиотеки для работы с джойстиком
#include <PS2X_lib.h>

// Выводы связи с модулем приёмопередатчика
const byte ATTENTION_PIN = 10;
const byte COMMAND_PIN = 11;
const byte DATA_PIN = 12;
const byte CLOCK_PIN = 13;

// Хранит значение ошибки
int error = 0; 
// Хранит тип найденного джойстика
byte controller_type = 0;
// Хранит значение оборотов мотора вибрации
byte vibrate_value = 0;

// Создание объекта для работы с джойстиком
PS2X ps2x;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

  // Инициализация джойстика с получением кода ошибки
  error = ps2x.config_gamepad(CLOCK_PIN, COMMAND_PIN, ATTENTION_PIN, DATA_PIN, true, true);

  // Проверка кода ошибки
  if(error == 0 || error == 3) {
    Serial.println("Found controller, configured successful");
  }
  else {
   Serial.println("No controller found or not accepting commands");
  }

  // Получение кода типа контроллера
  controller_type = ps2x.readType();

  // Проверка кода типа контроллера
  if(controller_type == 1) {
    Serial.println("Controller type is DualShock");
  }
  else {
   Serial.println("Another controller");
   while(1); // Остановка дальнейших действий, если иной контроллер
  }
}

void loop() {
  ps2x.read_gamepad(false, vibrate_value);
  
  if(ps2x.Button(PSB_START)) {
    Serial.println("START is being held");
  }
  
  if(ps2x.Button(PSB_SELECT)) {
    Serial.println("SELECT is being held");
  }
  
  if(ps2x.Button(PSB_PAD_UP)) {
    Serial.print("UP held this hard: ");
    Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);
  }
  
  if(ps2x.Button(PSB_PAD_RIGHT)) {
    Serial.print("RIGHT held this hard: ");
    Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
  }
  
  if(ps2x.Button(PSB_PAD_LEFT)) {
    Serial.print("LEFT held this hard: ");
    Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
  }
  
  if(ps2x.Button(PSB_PAD_DOWN)) {
    Serial.print("DOWN held this hard: ");
    Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);
  }

  // Изменение вибрации в зависимости от силы нажатия на кнопку (X)
  vibrate_value = ps2x.Analog(PSAB_BLUE);

  // Срабатывает при изменении состояния любой кнопки (Нажата\Отпущена, Отпущена\Нажата)
  if(ps2x.NewButtonState()) {
    if(ps2x.Button(PSB_L3)) {
      Serial.println("L3 pressed");
    }
    
    if(ps2x.Button(PSB_R3)) {
      Serial.println("R3 pressed");
    }
    
    if(ps2x.Button(PSB_L2)) {
      Serial.println("L2 pressed");
    }
    
    if(ps2x.Button(PSB_R2)) {
      Serial.println("R2 pressed");
    }
    
    if(ps2x.Button(PSB_GREEN)) {
      Serial.println("TRIANGLE pressed");
    }
  }   
       
  // Если кнопка просто нажата
  if(ps2x.ButtonPressed(PSB_RED)) {
    Serial.println("CIRCLE just pressed");
  }

  // Если кнопка просто отпущена
  if(ps2x.ButtonReleased(PSB_PINK)) {
    Serial.println("SQUARE just released"); 
  }

  // Если просто изменилось состояние кнопки
  if(ps2x.NewButtonState(PSB_BLUE)) {
    Serial.println("X just changed");
  }

  // Если любая из этих кнопок нажата, то выводятся значения стиков
  if(ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) {
    Serial.print("Stick Values: ");
    // Левый стик
    Serial.print(ps2x.Analog(PSS_LY), DEC); // Ось Y
    Serial.print(", ");
    Serial.print(ps2x.Analog(PSS_LX), DEC); // Ось X
    Serial.print(", ");
    // Правый стик
    Serial.print(ps2x.Analog(PSS_RY), DEC); // Ось Y
    Serial.print(", ");
    Serial.println(ps2x.Analog(PSS_RX), DEC); // Ось X
  }

  delay(50);
}
