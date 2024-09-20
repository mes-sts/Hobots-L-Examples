/*
 * hl_beginer_esp32_wifi_upload_ota_p2_check
 * 
 * Проверка загрузки прошивок по беспроводному каналу связи
 * с использованием WiFi OTA - ЧАСТЬ2
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
 * EN версия https://github.com/ayushsharma82/AsyncElegantOTA
 * RU версия https://github.com/S-LABc/AsyncElegantOTA-ru
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
// Подключение библиотеки сервиса загрузки прошивок по WiFi
#include <AsyncElegantOTA_RU.h> // RU
//#include <AsyncElegantOTA.h> // EN

// Имя WiFi точки доступа
const char* ap_ssid = "HL-Beginer-OTA-P2";
// Пароль WiFi точки доступа
const char* ap_password = "0123456789";

AsyncWebServer server(80);

void setup(void) {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Включение режима точки доступа
  WiFi.mode(WIFI_AP);
  
  // Устанока имени и пароля точки доступа
  WiFi.softAP(ap_ssid, ap_password);
  delay(500);

  // Обработчик корневой директории сервера
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", index_html);
  });

  // Обработчик страницы 404
  server.onNotFound(notFound);

  // Запуск сервиса загрузки прошивок по WiFi
  AsyncElegantOTAru.begin(&server);

  // Запуск асинхронного web сервера
  server.begin();
}

void loop(void) {
}

// Метод вывода сообщения о несеществующей директории
void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}
