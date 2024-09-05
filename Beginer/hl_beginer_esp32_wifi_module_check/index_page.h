#pragma once

const char index_html[] PROGMEM = R"=====(
<!DOCTYPE HTML>
<html lang="ru">
<head>
  <title>Hobots-L-Beginer-WiFi-Module-Test</title>
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
        background-color: #e2dcfc;
        color: #e2dcfc;
      }
      h1 {
        color: #da5dba;
        font-size: 2.2rem;
        text-shadow: #e298d0 1px 0 3px;
      }
      .buttonLED {
        margin-bottom: 20px;
        padding: 15px 25px;
        font-size: 20px;
        text-align: center;
        outline: none;
        color: #fff;
        background-color: #f05933;
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
      .buttonLED:hover {
        background-color: #f16947;
      }
      .buttonLED:active {
        background-color: #233c63;
        transform: translateY(1px);
      }
    </style>
  </head>
<body>
  <h1>Тест HL WiFi</h1>
  <button class="buttonLED" onclick="sendHTTP('led2on');">LED_2 ON</button>
  <br>
  <button class="buttonLED" onclick="sendHTTP('led2off');">LED_2 OFF</button>
  <br>
  <br>
  <br>
  <button class="buttonLED" onclick="sendHTTP('led3on');">LED_3 ON</button>
  <br>
  <button class="buttonLED" onclick="sendHTTP('led3off');">LED_3 OFF</button>
  <script>
    function sendHTTP(x) {
      var xhr = new XMLHttpRequest();
      xhr.open("GET", "/" + x, true);
      xhr.send();
    }
  </script>
</body>
</html>
)=====";
