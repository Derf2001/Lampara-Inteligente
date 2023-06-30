// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "334b492f-b197-4f11-98d3-62abecb57629";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

void onColorLedChange();
void onSensorChange();
void onHumedadChange();
void onTemperaturaChange();
void onButtonChange();

CloudColoredLight colorLed;
CloudSwitch sensor;
int humedad;
int temperatura;
bool button;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(colorLed, READWRITE, ON_CHANGE, onColorLedChange);
  ArduinoCloud.addProperty(sensor, READWRITE, ON_CHANGE, onSensorChange);
  ArduinoCloud.addProperty(humedad, READWRITE, ON_CHANGE, onHumedadChange);
  ArduinoCloud.addProperty(temperatura, READWRITE, ON_CHANGE, onTemperaturaChange);
  ArduinoCloud.addProperty(button, READWRITE, ON_CHANGE, onButtonChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
