/*
 * hl_beginer_bord_display_buttons_check
 * 
 * Проверка платы расширения с кнопоками и дисплеем HL Начальный
 * 
 * Ссылка на библиотеку для работы с дисплеем https://github.com/adafruit/Adafruit-ST7735-Library
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Подключение библиотек для работы с дисплеем и графикой
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

// Выводы кнопок
const byte BTN_LEFT_PIN = 35;
const byte BTN_RIGHT_PIN = 32;
const byte BTN_UP_PIN = 33;
const byte BTN_DOWN_PIN = 34;

// Выводы дисплея
const byte TFT_CS_PIN = 53;
const byte TFT_DC_PIN = 30; // Может называться RS
const byte TFT_RST_PIN = 31;

// Переменные для хранения состояния кнопок
bool btn_left_state = false;
bool btn_right_state = false;
bool btn_up_state = false;
bool btn_down_state = false;

// Создание объекта для работы с дисплеем
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS_PIN, TFT_DC_PIN, TFT_RST_PIN);
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка выводов кнопок на вход
  pinMode(BTN_LEFT_PIN, INPUT);
  pinMode(BTN_RIGHT_PIN, INPUT);
  pinMode(BTN_UP_PIN, INPUT);
  pinMode(BTN_DOWN_PIN, INPUT);

  // Настройка дисплея
  tft.initR(INITR_BLACKTAB);
  // Отриовка на экране тестовых линий
  testlines(ST77XX_MAGENTA);
}

void loop() {
  // Обработка кнопки ЛЕВО
  if (!digitalRead(BTN_LEFT_PIN) && !btn_left_state) {
    btn_left_state = true;
    Serial.println("Button LEFT PRESS");
    testdrawtext("Button LEFT", ST77XX_BLACK);
  }
  if (digitalRead(BTN_LEFT_PIN) && btn_left_state) {
    btn_left_state = false;
    Serial.println("Button LEFT RELEASE");
    tft.fillScreen(ST77XX_WHITE);
  }

  // Обработка кнопки ПРАВО
  if (!digitalRead(BTN_RIGHT_PIN) && !btn_right_state) {
    btn_right_state = true;
    Serial.println("Button RIGHT PRESS");
    testdrawtext("Button RIGHT", ST77XX_BLUE);
  }
  if (digitalRead(BTN_RIGHT_PIN) && btn_right_state) {
    btn_right_state = false;
    Serial.println("Button RIGHT RELEASE");
    tft.fillScreen(ST77XX_WHITE);
  }

  // Обработка кнопки ВЕРХ
  if (!digitalRead(BTN_UP_PIN) && !btn_up_state) {
    btn_up_state = true;
    Serial.println("Button UP PRESS");
    testdrawtext("Button UP", ST77XX_GREEN);
  }
  if (digitalRead(BTN_UP_PIN) && btn_up_state) {
    btn_up_state = false;
    Serial.println("Button UP RELEASE");
    tft.fillScreen(ST77XX_WHITE);
  }

  // Обработка кнопки НИЗ
  if (!digitalRead(BTN_DOWN_PIN) && !btn_down_state) {
    btn_down_state = true;
    Serial.println("Button DOWN PRESS");
    testdrawtext("Button DOWN", ST77XX_RED);
  }
  if (digitalRead(BTN_DOWN_PIN) && btn_down_state) {
    btn_down_state = false;
    Serial.println("Button DOWN RELEASE");
    tft.fillScreen(ST77XX_WHITE);
  }
}

// Метод отрисовки произвольного текста с заданным цветом
void testdrawtext(char *text, uint16_t color) {
  tft.setTextWrap(true);
  tft.fillScreen(ST77XX_WHITE);
  tft.setCursor(50, (tft.height() / 2));
  tft.setTextColor(color);
  tft.setTextSize(2);
  tft.print(text);
}

// Метод отрисовки линий с заданным цветом
void testlines(uint16_t color) {
  tft.fillScreen(ST77XX_WHITE);
  for (int16_t x = 0; x < tft.width(); x += 6) {
    tft.drawLine(0, 0, x, tft.height() - 1, color);
    delay(50);
  }
  for (int16_t y = 0; y < tft.height(); y += 6) {
    tft.drawLine(0, 0, tft.width() - 1, y, color);
    delay(50);
  }

  tft.fillScreen(ST77XX_WHITE);
  for (int16_t x = 0; x < tft.width(); x += 6) {
    tft.drawLine(tft.width() - 1, 0, x, tft.height() - 1, color);
    delay(50);
  }
  for (int16_t y = 0; y < tft.height(); y += 6) {
    tft.drawLine(tft.width() - 1, 0, 0, y, color);
    delay(50);
  }

  tft.fillScreen(ST77XX_WHITE);
  for (int16_t x = 0; x < tft.width(); x += 6) {
    tft.drawLine(0, tft.height() - 1, x, 0, color);
    delay(50);
  }
  for (int16_t y = 0; y < tft.height(); y += 6) {
    tft.drawLine(0, tft.height() - 1, tft.width() - 1, y, color);
    delay(50);
  }

  tft.fillScreen(ST77XX_WHITE);
  for (int16_t x = 0; x < tft.width(); x += 6) {
    tft.drawLine(tft.width() - 1, tft.height() - 1, x, 0, color);
    delay(50);
  }
  for (int16_t y = 0; y < tft.height(); y += 6) {
    tft.drawLine(tft.width() - 1, tft.height() - 1, 0, y, color);
    delay(50);
  }
  tft.fillScreen(ST77XX_WHITE);
}
