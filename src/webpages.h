const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>ESP32 Homepage</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
  <style>
    html {
     font-family: Arial;
     display: inline-block;
     margin: 0px auto;
     text-align: center;
    }
    h2 {
      font-size: 4.0rem;
      text-align: center;
      padding: 3px;
      color: black;
    }
    p {
      font-size: 3.0rem;
    }
    .dht-labels{
      font-size: 3.0rem;
      vertical-align:middle;
      padding-bottom: 15px;
    }
    .footer {
      font-size: 1.0rem;
      float: right;
      text-align: center;
      padding: 3px;
      background-color: gray;
      color: black;
    }
  </style>
</head>
<body>
  <h2>ESP32 Homepage</h2>
  <p><a href="/">ESP32 Sensor Home/a></p>
</body>

</html>)rawliteral";