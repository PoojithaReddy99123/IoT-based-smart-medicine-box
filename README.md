# 💊 IoT Smart Medicine Box

An Arduino-based automatic medicine dispenser that alerts users to take medicine on time using a buzzer and motorized box. It uses an IR sensor to detect if medicine is picked. Designed especially to help elderly or busy individuals maintain their medicine schedule with minimal human intervention.

---

## 🧰 Components Used

- Arduino UNO  
- RTC Module (Real Time Clock - DS3231)  
- IR Sensor  
- LCD Display (16x2) (Optional)  
- Buzzer  
- DC Motor (for CD tray mechanism)  
- Jumper Wires & Custom PCB  
- Power Supply  

---

## 🔧 Working Principle

- The RTC module tracks the real time.
- At the preset time, a buzzer rings to alert the user.
- The medicine box (CD tray) opens automatically using a motor.
- An IR sensor detects if the medicine is picked.
- If not picked, it can log the event or alert via display (if LCD is used).
- The tray closes after a few seconds automatically.
- Works entirely offline, using real-time components.

---

## 🖼️ Circuit Diagram  
![Circuit Diagram](circuit_diagram.jpg)

---

## 📸 Project Prototype Images

### 🧩 Power Supply  
![Power Supply](power_supply.jpg)

### 🔌 Circuit Setup (Connecting to Controller)  
![Circuit Setup](connecting_to_wifi.jpg)

### 📦 Box Opening with Buzzer Ringing  
![Box Opening](box_opening_and_buzzer_rings.jpg)

---

## 🚀 How to Run the Project

1. Assemble the circuit as per the diagram.
2. Install **RTClib** in Arduino IDE via Library Manager.
3. Upload the `main.ino` Arduino sketch to the Arduino UNO board.
4. Edit the code to set your custom alarm times (if needed).
5. Power on the circuit and test real-time alerts, IR detection, and motor operation.

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

## 🚑 About the Project

🚑 Designed to support elderly and busy users in taking medicine on time through IoT automation and real-time feedback.  
---