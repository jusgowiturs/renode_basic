# STM32 Bare-Metal Projects (F767ZI)

## 📚 Documentation

* 📘 Board Manual:
  https://www.st.com/resource/en/user_manual/um1974-stm32-nucleo144-boards-mb1137-stmicroelectronics.pdf

* 📗 Reference Manual:
  https://www.st.com/resource/en/reference_manual/rm0410-stm32f76xxx-and-stm32f77xxx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf

> **Note:** On STM32 Nucleo F767ZI, **LD2 (User LED) is connected to PB7**

---

## 📌 Overview

This repository demonstrates **bare-metal embedded programming** on STM32 without using HAL libraries.

### Key Focus Areas

* Direct **register-level programming**
* Understanding of **ARM Cortex-M architecture**
* Basic **peripheral control (GPIO)**

---

## 🧩 Project Structure

```
.
├── Without_HAL_Baremetal/
│   └── baremetal_led_blinking/
│
├── stm32-UART/
│
├── stm32-renode/
│
└── stm32-renode_Interrput/
```

---

## 🚀 Project: Bare-metal LED Control (No HAL)

This project demonstrates how to control an LED using **direct register access**, without relying on STM32 HAL.

### 🔧 Features

* Manual **RCC clock enable**
* Direct **GPIO mode configuration**
* Writing to **output data register (ODR)**

### 🎯 Target

* **Board:** STM32 Nucleo F767ZI
* **LED:** LD2
* **Pin:** PB7

---

## 🛠️ How it Works

1. Enable clock for **GPIOB** via RCC
2. Configure **PB7** as output
3. Set PB7 HIGH → LED turns ON

---

## 📈 Learning Outcome

* Hands-on understanding of **hardware registers**
* Ability to work **without abstraction layers (HAL)**
* Strong foundation for **embedded systems development**

---

## 🔜 Next Improvements

* LED blinking with delay
* Button input handling
* UART communication
* Interrupt-based design

---

## 👤 Author

**Prabhu Ram Nagarajan**
