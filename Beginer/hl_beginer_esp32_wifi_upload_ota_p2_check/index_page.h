#pragma once

const char index_html[] PROGMEM = R"=====(
<!DOCTYPE HTML>
<html lang="ru">
<head>
  <title>Hobots-L-Beginer-WiFi-Upload-OTA-p2</title>
  <meta http-equiv="Content-type" content="text/html; charset=utf-8">
  <head>
    <meta name="viewport" content="width=device-width,initial-scale=1.0,user-scalable=no">
    <style>
      html {
        display: inline-block;
      }
      body {
        max-width: 600px;
        font-family: Arial;
        text-align: center;
        margin: 0px auto;
        background-color: #ffffff;
        color: #ffffff;
      }
      h1 {
        color: #da5dba;
        font-size: 1.2rem;
        text-shadow: #e298d0 1px 0 3px;
      }
      h3 {
        color: #000;
        font-size: .7rem;
      }
      .buttonUpdate {
        margin-bottom: 20px;
        padding: 15px 25px;
        font-size: 20px;
        text-align: center;
        outline: none;
        color: #fff;
        background-color: #37b662;
        border: none;
        border-radius: 10px;
        cursor: pointer;
        -webkit-touch-callout: none;
        -webkit-user-select: none;
        -khtml-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none;
        -webkit-tap-highlight-color: rgba(0, 0, 0, 0);
      }
      .buttonUpdate:hover {
        background-color: #218040;
      }
      .buttonUpdate:active {
        background-color: #233c63;
        transform: translateY(1px);
      }
    </style>
  </head>
<body>
  <h1>Тест HL WiFi обновления через OTA (ЧАСТЬ2)</h1>
  <h3>Для тестирования необходимо загрузить бинарный файл с любой прошивкой для ESP32 или бинарный файл первой части этого теста.</h3>
  <form action="/update"><button class="buttonUpdate">Обновиться</button></form>
</body>
</html>
)=====";
