# 🚗 Smart Traffic Light with IR Sensor using Arduino

## 📌 Objective
To build a **smart traffic light system** that changes its behavior based on object detection using an **IR sensor**.

---

## 🔧 Components Used
- Arduino Uno
- Red LED
- Yellow LED
- Green LED
- IR Sensor
- Resistors
- Jumper wires
- Breadboard (optional)

---

## ⚙️ Working Principle
This project combines a **traffic light system** with **object detection** using an IR sensor.

The system works in two modes:

### 🚧 Object Detected
When the IR sensor detects an object:
- The **Red and Yellow LEDs blink alternately**
- This acts like a **siren or alert signal**

### 🚦 No Object Detected
When no object is detected:
- The system runs a **normal traffic signal sequence**
  - 🔴 Red Light → 5 seconds
  - 🟡 Yellow Light → 1 second
  - 🟢 Green Light → 7 seconds
  - 🟡 Yellow Light → 1 second

The cycle then repeats continuously.

---


## 🎥 Output Demonstration

![Project Demo](output.mp4)

---

## 🎯 Learning Outcome
- Combining **sensors with automation systems**
- Reading **IR sensor input**
- Creating **conditional logic in Arduino**
- Designing **smart traffic control systems**
