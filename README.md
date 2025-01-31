# Weather Station Project

This project is a weather station designed to monitor environmental parameters such as temperature, humidity, and air quality. It uses an Arduino Uno board, various sensors (DHT22 for temperature and humidity, MQ135 for air quality), and NRF24L01 radio modules for wireless data transmission.

## Features
- **Temperature and Humidity Measurement**: Using the DHT22 sensor.
- **Air Quality Monitoring**: Using the MQ135 gas sensor.
- **Wireless Data Transmission**: Using NRF24L01 and NRF24L01+PA+LNA modules.
- **Receiver to Serial Monitor**: Data is sent to a computer via a receiver and displayed on the serial monitor for further analysis.

## Installation
1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/weather-station.git
2. Install the necessary libraries in Arduino IDE from libraries.zip:
  DHT sensor library (for DHT22 sensor)
  MQ135 sensor library (for MQ135 sensor)
  RF24 library (for NRF24L01 radio module)
3. Connect the components: Follow the wiring diagram to connect the Arduino Uno board, DHT22 sensor, MQ135 sensor, and NRF24L01 radio modules. You can use breadboard to connect VCCs and GNDs.
4. Download receiver's and transmitter's codes (RX.ino and TX.ino respectively)
5. Use the Arduino IDE to upload the transmitter and receiver codes to the respective Arduino boards.
## Usage
1. After uploading the code to the Arduino, open the serial monitor in the Arduino IDE.
2. The serial monitor will display data sent from the transmitter, including:
    -Temperature (°C)
    -Humidity (%)
    -Air Quality (PPM)
## Circuit Diagram
Please note: The NRF24L01 radio module should be connected to the adapter module (NRF24L01 adapter). 
You can see wiring diagramas in Arduino_Weather_Station.pdf
## Contact
For any questions or suggestions, feel free to contact us:
Email 1: kdianav2608@gmail.com
Email 2: anzhelinadzhanysheva@gmail.com
GitHub 1: https://github.com/dianakim2610
GitHub 2: https://github.com/anjellol
## Acknowledgements
- Thanks to the developers of various open-source libraries used in this project, including those for the DHT22, MQ135 sensors, and RF24 radio module.

