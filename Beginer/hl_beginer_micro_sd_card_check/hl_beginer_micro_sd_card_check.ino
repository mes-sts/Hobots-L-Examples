/*
 * hl_beginer_micro_sd_card_check
 * 
 * Проверка micro SD карты HL Начальный
 *
 * Необходимо предварительно вставить карту памяти в слот
 * 
 * Инструменты → Плата → Arduino Mega or Mega2560
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

 // Подключение библиотеки для работы с SD картами
#include <SD.h>

const byte SD_CARD_CD_SS = 4;

// Создание объекта для текстовых данных
File myFile;

void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);

  // Ожидание открытия отладочного порта
  while (!Serial);

  Serial.println("Initializing SD card...");

  if (!SD.begin(SD_CARD_CD_SS)) {
    Serial.println("Initialization failed");
    while (true);
  }

  Serial.println("Initialization done");

  // Открытие (или создание и открытие) текстового файла
  myFile = SD.open("test.txt", FILE_WRITE);

  // Запись текста в файл
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("MES GROUP");
    myFile.close();
    Serial.println("done.");
  }
  else {
    // Если не удалось открыть файл
    Serial.println("error opening test.txt");
  }

  // Открытие файла повторно
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    // Чтение данных из файла
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  }
  else {
    // Если не удалось открыть файл
    Serial.println("error opening test.txt");
  }
}

void loop() {
  // Ничего
}
