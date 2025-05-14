# Thermocol-_-Styrofoam-Cutting-CNC

# 🔥 DIY CNC Hot Wire Cutter for Thermocol (Styrofoam)

## 📌 Overview

The rise of affordable CNC (Computer Numerical Control) technology has opened up new possibilities for hobbyists, model makers, and small-scale manufacturers. Among these innovations, the **CNC hot wire cutter** stands out as an efficient solution for cutting and shaping **Thermocol (Styrofoam)** with precision and ease.

This project showcases the construction and operation of a **DIY CNC hot wire cutter**, built using **low-cost components** such as:

- 🔁 28BYJ-48 stepper motors  
- ⚙️ L293D motor driver shield  
- 🧠 Arduino Uno

The machine employs a **heated wire** to slice through materials, following **precise G-code instructions** to create complex shapes and patterns.

---

## 🛠 Features

- 🔧 Fully DIY and budget-friendly
- 🔥 Hot wire cutting mechanism for Styrofoam
- 🎯 High accuracy and reliability
- 🧱 3D-printed frame for enhanced structural stability
- 📐 Supports intricate designs with minimal material waste
- 🧰 Ideal for:
  - Architectural modeling
  - Custom packaging
  - Artistic foam projects

---

## 🔋 Components Used

| Component                | Quantity |
|--------------------------|----------|
| Arduino Uno              | 1        |
| 28BYJ-48 Stepper Motors  | 2        |
| L293D Motor Driver Shield| 1        |
| Nichrome Wire (Hot Wire) | 1        |
| Power Supply             | 1        |
| 3D Printed Frame Parts   | Varies   |

---

## ⚙️ How It Works

1. **G-code Generation**  
   Design your desired shape in software like Inkscape, convert it to G-code using a plugin or external tool.

2. **Upload to Arduino**  
   Use firmware that interprets G-code and controls the stepper motors.

3. **Heating the Wire**  
   The nichrome wire is powered via a suitable power source to heat up and become capable of cutting foam.

4. **Cutting Operation**  
   The Arduino processes the G-code and moves the hot wire along X and Y axes to perform the cut.

---

## 📦 Installation & Setup

### 1. Assemble the Hardware
- Follow the mechanical diagram and install the 3D-printed frame.
- Mount the stepper motors and wire the drivers to the Arduino.
- Attach the hot wire using heat-resistant connectors.

### 2. Upload Firmware
- Use **Arduino IDE** to upload the CNC control code (e.g., GRBL-compatible or custom firmware).

### 3. Send G-code
- Use a G-code sender like **Universal G-code Sender (UGS)** or **Candle**.

---

## 🔌 Wiring Diagram

> **Note**: Include an image or link to the wiring diagram here for easier reference.

---

## 🖥️ Software Tools Used

- **Arduino IDE**
- **Inkscape** (for vector design)
- **G-code Converter Plugin**
- **Universal G-code Sender** or similar tool

---

## 📚 Documentation Includes

- ✅ Step-by-step assembly guide
- ✅ Electronics setup & wiring
- ✅ Firmware flashing and configuration
- ✅ Calibration procedure
- ✅ Safety precautions
- ✅ Sample G-code files

---

## 🚨 Safety Note

Always take proper safety precautions when working with high-temperature wires and electronic equipment. Never leave the machine unattended while in operation.

---

## 📸 Demo & Images

> Add images or videos of the working machine, cutting examples, or the build process.

---

## 📄 License

This project is open-source and distributed under the [MIT License](LICENSE).

---

## 🙌 Acknowledgments

Thanks to the open-source community and all contributors who inspired the development of this DIY CNC Hot Wire Cutter.

