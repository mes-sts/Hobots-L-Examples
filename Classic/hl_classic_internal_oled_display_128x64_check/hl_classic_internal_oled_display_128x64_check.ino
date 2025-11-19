/*
 * hl_classic_internal_oled_display_128x64_check
 * 
 * Проверка встроенного OLED дисплея ХЛ Классический
 * 
 * Ссылка на библиотеку дисплея https://github.com/adafruit/Adafruit_SSD1306/
 * 
 * Инструменты → Плата → Arduino Uno
 * 
 * Copyright (C) 2025. v1.0 / MES
 */

// Подключение файла с библиотекой графических приметивов
#include <Adafruit_GFX.h>
// Подключение файла с библиотекой для дисплея
#include <Adafruit_SSD1306.h>

// Количество пикселей по ширине дисплея
const uint8_t SCREEN_WIDTH = 128;
// Количество пикселей по высоте дисплея
const uint8_t SCREEN_HEIGHT = 64;

// Адрес дисплея на шине I2C
const uint8_t SCREEN_ADDRESS = 0x3C;

// Создание объекта для работы с дисплеем
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); // -1 чтобы не использовать контакт RESET у дисплея

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(9600);

  // Попытка иницализации объекта дисплея
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    while(1); // ничего не делать если дисплей не инициализирован
  }
}

void loop() {
  // Генерация координат второго текста
  uint8_t x = random(0, 73); // от 0 до 73 пикселей
  uint8_t y = random(17, 43); // от 17 до 43 пикселей

  // Очистка дисплея
  display.clearDisplay();

  // Включение инвертированного тектста
  display.setTextColor(SSD1306_INVERSE);

  // Формирование прямоугольника в верхней части дисплея
  display.fillRect(0, 0, 128, 16, SSD1306_INVERSE);

  // Формирование первого текста поверх прямоугольника
  display.setTextSize(2); // Размер шрифта
  display.setCursor(17, 1); // Координаты текста
  display.println(F("HOBOTS L")); // Выводимый текст

  // Формирование второго текста в случайных координатах
  display.setTextSize(3); // Размер шрифта
  display.setCursor(x, y); // Координаты текста
  display.println(F("MES")); // Выводимый текст

  // Отображение информации на дисплее
  display.display();

  // Вывод координат второго текста в монитор порта
  Serial.print(F("X, Y : "));
  Serial.print(x);
  Serial.print(F(", "));
  Serial.println(y);

  // Удержане иформации на экране
  delay(random(300, 500)); // от 300 до 500 мс
}
