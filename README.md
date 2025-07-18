# 💊 IoT-Based Smart Medicine Box (Arduino UNO)

An offline Arduino UNO-based automatic medicine dispenser that helps users—especially the elderly—take medicines on time. It rings a buzzer and opens a motorized box at a scheduled time using an RTC. An IR sensor detects whether the medicine was picked. This project is simple, effective, and fully operational without internet connectivity.
---

## 🧰 Components Used

- Arduino UNO  
- RTC Module (DS3231)  
- IR Sensor  
- 16x2 LCD (optional)  
- Buzzer  
- L293D Motor Driver IC  
- DC Motor (e.g., CD tray mechanism)  
- Jumper Wires  
- Power Supply or 9V Adapter  
- Custom PCB (for compact setup)

---

## 🔧 Working Principle

1. **RTC** keeps track of real time.
2. At preset time (e.g., 9:00 AM), **buzzer rings**.
3. The **motorized tray opens** using L293D.
4. **IR sensor checks** if medicine is picked up.
5. Tray closes after a few seconds, whether picked or not.
6. Entire system is **offline** and works autonomously.

---

## 🖼️ Images

### 🔌 Circuit Diagram  
![Circuit Diagram](circuit_diagram.jpg)

### 🔋 Power Supply Setup  
![Power Supply](power_supply.jpg)

### 📦 Box Opening During Alert  
![Box Opening](box_opening_and_buzzer_rings.jpg)


---

## 🚀 How to Use

1. Wire the circuit as shown above.
2. Install **RTClib** in Arduino IDE (via Library Manager).
3. Upload `main.ino` to Arduino UNO.
4. Set medicine alert time in the code (default: 9:00 AM).
5. Power the circuit; system works automatically.

---

## 📂 Project Structure
IoT-based-smart-medicine-box/
├── main.ino
├── circuit_diagram.jpg
├── power_supply.jpg
├── box_opening_and_buzzer_rings.jpg
└── README.md

---

## 👩‍💻 Author

**Poojitha Reddy**  
GitHub: [@PoojithaReddy99123](https://github.com/PoojithaReddy99123)

---

## 🔧 Optional Improvements

- Add LCD to show time/status
- Add EEPROM for logging
- Add buttons to manually override tray
- Upgrade to NodeMCU for internet-based alerts

---

## 📄 License

Open source for educational use. Credit appreciated.