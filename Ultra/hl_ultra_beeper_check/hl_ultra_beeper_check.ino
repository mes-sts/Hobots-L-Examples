/*
 * hl_ultra_beeper_check
 * 
 * Проверка звукового излучателя HL Ультра
 * 
 * Инструменты → Плата → STM32 Boards Groups → Generic STM32F1 series
 * Инструменты → Board part number → Generic F103RCTx
 * Инструменты → U(S)ART support → Enable (generic 'Serial')
 * Инструменты → USB support (if available) → CDC (generic 'Serial' supersede U(S)ART)
 * Инструменты → Upload method → HID Bootloader 2.2
 * 
 * Copyright (C) 2024. v1.0 / MES
 */

// Подключение файла с нотами
#include "pitches.h"

// Вывод звукового излучателя
const uint8_t BEEPER_PIN = PA0;

// Порядок нот в мелодии
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// Длительность нот. 4 - четвертные, 8 - восьмые, и тд.
int note_durations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
 
void setup() {
  // Настройка скорости отладочного порта
  Serial.begin(115200);
}

void loop() {
  // Проход по всем нотам мелодии
  for (int current_note = 0; current_note < 8; current_note++) {
    // Вычисление продолжительности ноты через длительность
    int note_duration = 1000 / note_durations[current_note];
    // Звучание текущей ноты
    tone(BEEPER_PIN, melody[current_note], note_duration);

    Serial.print("Note Hz "); Serial.println(melody[current_note]);
    Serial.print("Duration ms "); Serial.println(note_duration);
    Serial.println();

    // Пауза для нормально восприятия нот составляет примерно 30% от их продолжительности
    int pause_btw_notes = note_duration * 1.30;
    delay(pause_btw_notes);

    // Прекращение звучания ноты
    noTone(BEEPER_PIN);
  }
}
