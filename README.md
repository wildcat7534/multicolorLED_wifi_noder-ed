# **multicolorLED_wifi_noder-ed**

  Ce projet permet de réaliser une LED RGB pilotée à distance via une interface web.  
  
## Vidéo 

[![video](https://img.youtube.com/vi/pIA5Q94g/0.jpg)](https://www.youtube.com/watch?v=pIA5Q94g)

## Matériels utilisés  

* [Arduino ESP32](https://www.amazon.fr/SeeKool-ESP-32S-d%C3%A9veloppement-Bluetooth-Ultra-Low/dp/B07DPP3BGZ/ref=sr_1_2_sspa?ie=UTF8&qid=1550052255&sr=8-2-spons&keywords=arduino+esp32&psc=1)

![ESP32](https://images-na.ssl-images-amazon.com/images/I/61H9-mWSrAL._SL1001_.jpg)


* [Del multicolores](https://www.amazon.fr/SODIAL-diode-electroluminescente-tete-ronde/dp/B00F4MGA0I/ref=sr_1_1?ie=UTF8&qid=1550052436&sr=8-1&keywords=led+rgb+arduino)

![Led](https://images-na.ssl-images-amazon.com/images/I/61U853WOASL._SL1000_.jpg)

## Bibliothèques utilisées  


* WiFi
* adafruit-MQTT


## Code

```
`#include <analogWrite.h>
#include <WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"WiFiClient wiFiClient;
Adafruit_MQTT_Client mqttClient(&wiFiClient, "192.168.1.109", 1883);
Adafruit_MQTT_Subscribe ledsub(&mqttClient, "/led");
Adafruit_MQTT_Subscribe ledsub2(&mqttClient, "/led2");
Adafruit_MQTT_Subscribe ledsub3(&mqttClient, "/led3");void ledcallback(double x) {
     Serial.println(x);
     analogWrite(18, x); }void ledcallback2(double x) {
     Serial.println(x);
     analogWrite(19, x); }void ledcallback3(double x) {
     Serial.println(x);
     analogWrite(21, x); }void setup() {Serial.begin(115200);
WiFi.begin("createch", "createch");
delay(4000);ledsub.setCallback(ledcallback);
mqttClient.subscribe(&ledsub);
ledsub2.setCallback(ledcallback2);
mqttClient.subscribe(&ledsub2);
ledsub3.setCallback(ledcallback3);
mqttClient.subscribe(&ledsub3);}void loop() {
if (mqttClient.connected()) {
   mqttClient.processPackets(10000);
   mqttClient.ping();
 } else {
   mqttClient.disconnect();
   mqttClient.connect();
 }
}`
```

## Node-red 

On utilise node-red pour pouvor piloter notre Led RGB à distance 

![Nodered]()




