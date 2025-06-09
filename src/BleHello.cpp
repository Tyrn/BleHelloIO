/*
    Based on Neil Kolban example for IDF:
   https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleServer.cpp
    Ported to Arduino ESP32 by Evandro Copercini
    updates by chegewara
*/

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>

#define _TASK_SCHEDULING_OPTIONS
// #define _TASK_TIMECRITICAL
// #define _TASK_SLEEP_ON_IDLE_RUN
#include <TaskScheduler.h>

#include <Lcd1602UniPrint.h>

#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif

Lcd1602UniPrint lcd;

int led_pin_1 = 4;
int led_pin_2 = 0;
// int led_pin_3 = 2;     // On some ESP32 pin 2 is an internal LED

void tCountCallback() {
  static int cnt = 1;
  lcd.print_dec_lr(cnt % 2 == 0 ? "То~ " : "Ти~ ", cnt++);
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  digitalWrite(led_pin_1, !digitalRead(led_pin_1));
  digitalWrite(led_pin_2, !digitalRead(led_pin_2));
}

Task tCount(1000, TASK_FOREVER, &tCountCallback);

Scheduler ts;

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/

#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");

  BLEDevice::init("Kitty's Sandbox");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID,
      BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);

  pCharacteristic->setValue("Hello World says Neil");
  pService->start();
  // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is
  // working for backward compatibility
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(
      0x06); // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now you can read it in your phone!");

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led_pin_1, OUTPUT);
  pinMode(led_pin_2, OUTPUT);
  digitalWrite(led_pin_1, HIGH);
  digitalWrite(led_pin_2, HIGH);

  lcd.d.init(); // For ESP32 use LCD_1602_RUS_ALL fork.

  lcd.d.backlight();
  lcd.d.setCursor(0, 0);

  ts.init();
  ts.addTask(tCount);
  tCount.enable();
}

void loop() { ts.execute(); }
