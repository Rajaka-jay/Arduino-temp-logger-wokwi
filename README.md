# 🌡️ Arduino Temperature & Humidity Logger with LCD

A professional-grade environment monitoring system built with Arduino. This project measures temperature and humidity using a **DHT22** sensor, displays real-time data on a **16x2 I2C LCD**, and logs the information to a **MicroSD Card** for long-term data analysis.

---

## 🚀 Live Simulation
No hardware? No problem! You can run the full circuit and code simulation in your browser via Wokwi:

[![Wokwi Project](https://img.shields.io/badge/Wokwi-Open_Simulation-blue?style=for-the-badge&logo=arduino)](https://wokwi.com/projects/462383931176104961)

---

## ✨ Features
* **Real-time Monitoring:** High-accuracy readings using the DHT22 sensor.
* **Visual Display:** Clean 16x2 LCD interface using I2C (only 2 data wires).
* **Data Logging:** Saves readings to a `log.txt` file on a MicroSD card in a CSV-ready format.
* **Error Handling:** Built-in checks for sensor connectivity and SD card initialization.

---

## 🛠️ Components & Hardware
* **Microcontroller:** Arduino Uno
* **Sensor:** DHT22 (AM2302) Temperature & Humidity Sensor
* **Display:** 16x2 I2C LCD Display
* **Storage:** MicroSD Card Module + FAT32 Formatted Card
* **Others:** Breadboard, Jumper wires

---

## 🔌 Wiring Diagram

| Component | Arduino Pin | Note |
| :--- | :--- | :--- |
| **DHT22 VCC** | 5V | |
| **DHT22 GND** | GND | |
| **DHT22 Data** | Pin 2 | |
| **LCD SDA** | A4 | I2C Data |
| **LCD SCL** | A5 | I2C Clock |
| **SD VCC** | 5V | |
| **SD GND** | GND | |
| **SD CS** | Pin 4 | Chip Select |
| **SD MOSI** | Pin 11 | SPI |
| **SD MISO** | Pin 12 | SPI |
| **SD SCK** | Pin 13 | SPI |

---

## 💻 Software Setup

### 1. Libraries Required
Install the following libraries via the Arduino Library Manager (`Ctrl+Shift+I`):
* `DHT sensor library` by Adafruit
* `LiquidCrystal I2C` by Frank de Brabander
* `SD` (Built-in)
* `SPI` (Built-in)

### 2. Installation
1. Clone this repository:
   ```bash
   git clone [https://github.com/YOUR_USERNAME/your-repo-name.git](https://github.com/YOUR_USERNAME/your-repo-name.git)