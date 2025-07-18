💊 IoT-Based Smart Medicine Box

An offline Arduino UNO-based automatic medicine dispenser that helps users—especially the elderly—take medicines on time. It rings a buzzer and opens a motorized box at a scheduled time using an RTC. An IR sensor detects whether the medicine was picked. This project is simple, effective, and fully operational without internet connectivity.

---

🧰 Components Used

Arduino UNO

RTC Module (DS3231)

IR Sensor

16x2 LCD Display (optional, for time/status display)

Buzzer

L293D Motor Driver IC

DC Motor (e.g., modified CD tray)

Jumper Wires

Power Supply (e.g., 9V/12V adapter)

Custom PCB (optional, for neat setup)


---

🔧 Working Principle

1. The RTC module keeps track of real time.

2. At the preset medicine time, the buzzer rings.

3. The medicine box opens using a motor driven by the L293D driver IC.

4. The IR sensor detects whether the user picks up the medicine.

5. If the medicine is not picked within a set time (e.g., 10 seconds), the tray still closes.

6. The process can repeat daily by setting the time inside the Arduino code.


---

🖼️ Prototype & Circuit Diagram

Circuit Diagram: circuit_diagram.jpg

Working Prototype:

box_opening_and_buzzer_rings.jpg

power_supply.jpg


These images show the complete connection between Arduino UNO, RTC, IR sensor, buzzer, L293D, and the motor mechanism (CD tray or custom box).

---

🚀 How to Use

1. Connect the components as per the provided circuit diagram.

2. Install the required libraries in the Arduino IDE:

RTClib by Adafruit (for RTC module)

3. Upload the code to the Arduino UNO.

4. Set the correct medicine reminder time in the code (default: 9:00 AM).

5. Power the system using USB or adapter.

6. At the set time, the buzzer will ring and the box will open.

7. The IR sensor will check if medicine is picked.

8. The box will close automatically after a few seconds.




---

📂 Folder Structure

IoT-based-smart-medicine-box/
├── main.ino
├── circuit_diagram.jpg
├── power_supply.jpg
├── box_opening_and_buzzer_rings.jpg
└── README.md


---

👩‍💻 Author

Poojitha Reddy
GitHub: @PoojithaReddy99123
