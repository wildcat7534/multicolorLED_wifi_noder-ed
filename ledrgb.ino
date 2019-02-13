#include <analogWrite.h>
#include <WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

WiFiClient wiFiClient;
Adafruit_MQTT_Client mqttClient(&wiFiClient, "192.168.1.109", 1883);
Adafruit_MQTT_Subscribe ledsub(&mqttClient, "/led");
Adafruit_MQTT_Subscribe ledsub2(&mqttClient, "/led2");
Adafruit_MQTT_Subscribe ledsub3(&mqttClient, "/led3");

void ledcallback(double x) {
      Serial.println(x);  
      analogWrite(18, x);
   
 }

void ledcallback2(double x) {
      Serial.println(x);  
      analogWrite(19, x);
   
 }

void ledcallback3(double x) {
      Serial.println(x);  
      analogWrite(21, x);
   
 }
 
void setup() {
  

Serial.begin(115200);
WiFi.begin("createch", "createch");
delay(4000);    

ledsub.setCallback(ledcallback);
mqttClient.subscribe(&ledsub);
ledsub2.setCallback(ledcallback2);
mqttClient.subscribe(&ledsub2);
ledsub3.setCallback(ledcallback3);
mqttClient.subscribe(&ledsub3);

}

void loop() {
if (mqttClient.connected()) {
    mqttClient.processPackets(10000);
    mqttClient.ping();
  } else {
    mqttClient.disconnect();
    mqttClient.connect();
  }
}
