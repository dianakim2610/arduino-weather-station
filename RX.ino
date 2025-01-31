#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(9, 10);  // Create module on pins 9 and 10 for Uno
//RF24 radio(9,53); // for Mega

byte address[][6] = {"1Node", "2Node", "3Node", "4Node", "5Node", "6Node"}; // Possible pipe addresses

void setup() {
  Serial.begin(9600);         // Open the port for communication with PC
  radio.begin();              // Activate the module
  radio.setAutoAck(1);        // Enable acknowledgment mode
  radio.setRetries(0, 15);    // Set retry parameters
  radio.enableAckPayload();   // Enable ACK payload
  radio.setPayloadSize(32);   // Set payload size

  radio.openReadingPipe(1, address[0]);   // We want to listen to pipe 0
  radio.setChannel(0x6e);     // Select a channel

  radio.setPALevel(RF24_PA_MAX);   // Set transmitter power level
  radio.setDataRate(RF24_250KBPS); // Set data rate

  radio.powerUp();        // Start working
  radio.startListening(); // Start listening to the air, we are the receiving module
}

void loop() {
  float receivedData[3];  // Array to hold the received data
  while (radio.available()) {    // Listen to the air from all pipes
    Serial.println("Radio available");  // Print if radio is available
    radio.read(&receivedData, sizeof(receivedData));  // Read incoming signal into the array
    Serial.print("Received PPM: ");
    Serial.print(receivedData[0]);
    Serial.print(" Humidity: ");
    Serial.print(receivedData[1]);
    Serial.print(" Temperature: ");
    Serial.println(receivedData[2]);
  }
}
