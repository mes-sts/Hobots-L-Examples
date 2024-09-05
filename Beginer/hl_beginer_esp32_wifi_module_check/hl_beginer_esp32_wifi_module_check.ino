/*
 * hl_beginer_esp32_wifi_module_check
 * 
 * Проверка работы модуля WiFi HL Начальный
 *
 * КОД ДЛЯ ESP32
 * 
 * Имя точки доступа - HL-Beginer
 * Пароль точки доступа - 0123456789
 * Адрес страницы в браузере - 192.168.4.1
 *
 * Ссылки на бибилиотеки:
 * https://github.com/me-no-dev/ESPAsyncWebServer
 * https://github.com/me-no-dev/AsyncTCP
 * 
 * Инструменты → Плата → ESP32 Dev Module
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Подключение файла с HTML страницей
#include "index_page.h"
// Подключение библиотек для работы с WiFi и web сервером
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Макросы номеров выводов UART2 ESP32
#define ESP32_RXD2_PIN 16
#define ESP32_TXD2_PIN 17

// Имя WiFi точки доступа
const char* ap_ssid = "HL-Beginer";
// Пароль WiFi точки доступа
const char* ap_password = "0123456789";

// Константы команд управления состояниями светодиодов контроллера
const char led_2_on_cmd = '1';
const char led_2_off_cmd = '2';
const char led_3_on_cmd = '3';
const char led_3_off_cmd = '4';

// Создание объекта асинхронного web сервера с портом 80
AsyncWebServer server(80);

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Настройка скорости порта для связи с контроллером
  Serial2.begin(115200, SERIAL_8N1, ESP32_RXD2_PIN, ESP32_TXD2_PIN);

  // Включение режима точки доступа
  WiFi.mode(WIFI_AP);

  // Устанока имени и пароля точки доступа
  WiFi.softAP(ap_ssid, ap_password);
  
  delay(500);

  // Обработчик корневой директории сервера
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  // Обработчик включения светодиода LED_2
  server.on("/led2on", HTTP_GET, [] (AsyncWebServerRequest *request) {
    Serial2.write(led_2_on_cmd); // Передача команды в контроллер
    Serial.println("LED_2 ON");
    request->send(200, "text/plain", "OK");
  });

  // Обработчик выключения светодиода LED_2
  server.on("/led2off", HTTP_GET, [] (AsyncWebServerRequest *request) {
    Serial2.write(led_2_off_cmd); // Передача команды в контроллер
    Serial.println("LED_2 OFF");
    request->send(200, "text/plain", "OK");
  });

  // Обработчик включения светодиода LED_3
  server.on("/led3on", HTTP_GET, [] (AsyncWebServerRequest *request) {
    Serial2.write(led_3_on_cmd); // Передача команды в контроллер
    Serial.println("LED_3 ON");
    request->send(200, "text/plain", "OK");
  });

  // Обработчик выключения светодиода LED_3
  server.on("/led3off", HTTP_GET, [] (AsyncWebServerRequest *request) {
    Serial2.write(led_3_off_cmd); // Передача команды в контроллер
    Serial.println("LED_3 OFF");
    request->send(200, "text/plain", "OK");
  });

  // Обработчик страницы 404
  server.onNotFound(notFound);
  
  // Запуск асинхронного web сервера
  server.begin();
}

void loop() {
  // Ничего, асинхронный web сервер
}

// Метод вывода сообщения о несеществующей директории
void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}
