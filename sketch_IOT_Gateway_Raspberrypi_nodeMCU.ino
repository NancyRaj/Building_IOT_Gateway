#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <PubSubClient.h>

WiFiClient esp;
PubSubClient c(esp);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
WiFi.begin("joe6281","qwerty6281");// wifi ssid and password to make nodemcu connect to wifi
while(WiFi.status()!=WL_CONNECTED){
  Serial.println('.');
  delay(100);
}
Serial.println("Connected"); //not necessary part of logic , just for our understanding that wifi is connected
c.setServer("192.168.0.100",1883);
}
void loop() {
  // put your main code here, to run repeatedly:
if(c.connect("Clientid","nancy","123456" )){
  c.publish("iot/local","Hi,I am from NodeMCU");
  delay(10000);
  }
}
