#include <MQ135.h>
#include "DHT.h"
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#define ANALOGPIN A0  // Define the analog pin for sensor readings
#define DHT22_PIN 3

MQ135 gasSensor = MQ135(ANALOGPIN); // Initialize the MQ135 sensor object
DHT dht22(DHT22_PIN, DHT22);

RF24 radio(9, 10); // Create the module on pins 9 and 10 for Uno
//RF24 radio(9,53); // for Mega

byte address[][6] = {"1Node"}; // Possible pipe addresses

void setup() {
  Serial.begin(9600);         // Open the port for communication with PC

  radio.begin();              // Activate the module
  radio.setAutoAck(1);        // Enable acknowledgment mode
  radio.setRetries(0, 15);    // Set retry parameters
  radio.enableAckPayload();   // Enable ACK payload
  radio.setPayloadSize(32);   // Set payload size

  radio.openWritingPipe(address[0]);  // We are pipe 0, open channel for data transmission
  radio.setChannel(0x6e);             // Select a channel

  radio.setPALevel(RF24_PA_MAX);   // Set transmitter power level
  radio.setDataRate(RF24_250KBPS); // Set data rate

  radio.powerUp();        // Start working
  radio.stopListening();  // We are the transmitter, stop listening

  dht22.begin();
  float rzero = gasSensor.getRZero();
  Serial.print("Calibrated RZero: ");
  Serial.println(rzero);
}

void loop() {
  float ppm = gasSensor.getPPM();
  float humi = dht22.readHumidity();
  float tempC = dht22.readTemperature();
  
  
  
  float dataToSend[3] = {ppm, humi, tempC};
  bool ok = radio.write(&dataToSend, sizeof(dataToSend));
  if (ok) {
    Serial.println("Data sent successfully");
  } else {
    Serial.println("Data send failed");
  }

  delay(1000); // Delay for readability
}
