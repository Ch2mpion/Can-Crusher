# Automated Can Crusher - University Project 🤖♻️

This repository contains the Arduino code for an automated can crushing system developed as part of a university environmental project. This mechanical system leverages rotary motion for efficient can compaction, aiming to streamline recycling processes.

## Table of Contents

* [Project Overview](#project-overview) 💡
* [Features](#features) ✨
* [Mechanical System Details](#mechanical-system-details) ⚙️
* [Electronics & Automation](#electronics-automation) 🔌
* [Code Structure](#code-structure) 📁
* [Setup & Usage](#setup--usage) 🚀
* [Academic Context](#academic-context) 🎓
* [Acknowledgements](#acknowledgements) 🙏
* [License](#license) 📝

## Project Overview 💡

The "Automated Can Crusher" is a hands-on university project designed to demonstrate the principles of mechanical engineering combined with basic automation. The primary goal is to efficiently crush aluminum cans through an automated process, contributing to environmental sustainability by making recycling easier and more space-efficient. This repository specifically houses the Arduino code responsible for the automated detection and control of the crushing mechanism.

## Features ✨

* **Automated Detection:** Utilizes sensors to detect the presence of a can. 👁️‍🗨️
* **Automated Crushing Cycle:** Initiates and completes the crushing process automatically once a can is detected. 🔄
* **Rotary Motion Mechanism:** Employs a robust gear-driven system for effective can compaction. 🌀
* **Environmental Focus:** Aims to reduce the volume of recyclable waste, promoting better recycling habits. 🌎

## Mechanical System Details ⚙️

The core of the can crushing mechanism is driven by a system of **gears**. These gears translate the motor's power into the necessary rotary motion, providing the torque and force required to efficiently crush aluminum cans. The design focuses on durability and effective compaction. 💪

## Electronics & Automation 🔌

The automation of this project is managed by an **Arduino Uno** microcontroller. The Arduino is responsible for:

* Reading input from sensors (e.g., proximity or limit switches) to detect the presence of a can. 📡
* Controlling the motor responsible for the crushing action. ⚡
* Managing the sequence of operations for the automated crushing cycle. 🧠

This repository specifically contains the Arduino sketches (`.ino` files) that implement this automated logic.

* **`CanCrusher.ino`**: This is the primary Arduino sketch that contains all the logic for detecting cans, controlling the motor, and managing the automated crushing cycle. It includes the setup and loop functions, along with any necessary helper functions for sensor readings and motor control. 💻

* **`CanCrusher.ino`**: This is the primary Arduino sketch that contains all the logic for detecting cans, controlling the motor, and managing the automated crushing cycle. It includes the setup and loop functions, along with any necessary helper functions for sensor readings and motor control. 💻

## Setup & Usage 🚀

*(This section will require more specific instructions once the code is finalized and uploaded. Here's a general outline.)*

1.  **Hardware Requirements:** 🛠️
    * Arduino Uno
    * Motor (e.g., DC motor with gearbox)
    * Sensors (e.g., IR proximity sensor, limit switch)
    * Power supply for motor and Arduino
    * Mechanical can crushing assembly with gears.

2.  **Software Requirements:** 🖥️
    * Arduino IDE

3.  **Uploading the Code:** ⬆️
    * Connect your Arduino Uno to your computer. 🔗
    * Open the `CanCrusher.ino` file in the Arduino IDE.
    * Select the correct board (Arduino Uno) and port from the `Tools` menu.
    * Click the "Upload" button to flash the code to your Arduino.

4.  **Operation:** ▶️
    * Ensure all mechanical and electrical connections are secure.
    * Power on the system. 🔋
    * Place a can in the designated detection area. The system should automatically detect the can and initiate the crushing sequence. 🥫➡️🤏

## Academic Context 🎓

This project was developed during the **First Year, 2nd Semester** at **Benha National University, Faculty of Engineering**. It served as a practical application of foundational engineering principles, integrating mechanical design with basic electronics and programming.

**Supervised by:**
Dr. Ahmed El Desouky 👨‍🏫

## Acknowledgements 🙏

A huge thank you to **@M7MEDpro** for their significant participation and invaluable contributions to this project. Their efforts were crucial to its successful completion. 🤝

## License 📝

This project is open-source and available under the MIT License. See the `LICENSE` file for more details.
