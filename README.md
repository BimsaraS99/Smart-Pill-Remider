# Smart Talking Pill Reminder for Blind and Visually Impaired People

## Overview

The Smart Talking Pill Reminder is a device designed to assist blind and visually impaired individuals in managing their medication regimen. It provides audio reminders and information to ensure that medications are taken on time and in the correct dosages. The device consists of a main controlling unit and multiple pill boxes, connected wirelessly through a mobile application.

## Features

- **Pill Reminder System**: The device provides audio reminders to users when it's time to take their medication, along with information about the specific medication, dosage, and instructions (e.g., whether to take before or after meals).
- **Talking Clock**: The device includes a talking clock feature that announces the current time at regular intervals, helping users keep track of their schedule.
- **Mobile App Integration**: A mobile application allows caregivers or sighted individuals to input and update medication information, which is then transmitted to the device via Bluetooth.
- **Non-volatile Memory**: The device stores medication data in non-volatile memory, ensuring that information is retained even when the device is powered off.
- **User-friendly Design**: The device features a single input button for easy control by blind and visually impaired users, with different input modes (e.g., single click, double click, long press) for various functions.
- **Expandable Pill Boxes**: The device can accommodate an unlimited number of pill boxes, allowing users to manage multiple medications simultaneously.

## Hardware Components

- Arduino Uno microcontroller
- TF-16 MP3 module for audio playback
- SD card for storing audio files
- DS 1307 timer IC for keeping track of time
- HC-06 Bluetooth module for communication with mobile app
- Buzzer for audible alerts
- Push buttons for user input

## Mobile Application

The mobile application, compatible with Android devices, allows caregivers or sighted individuals to input and update medication information, including:

- Medication names
- Dosages
- Schedules for taking the medication

This information is then transmitted to the main controlling unit via Bluetooth.

## Usage

1. Install the mobile application on an Android device.
2. Input the medication information, including names, dosages, and schedules, into the mobile app.
3. Transmit the information to the main controlling unit via Bluetooth.
4. The device will store the medication data in its non-volatile memory.
5. At the scheduled times, the device will provide audio reminders and information to the user, guiding them through taking the correct medication and dosage.
6. Use the single input button on the main controlling unit to acknowledge reminders and navigate through the device's functions.

## Contributing

Contributions to this project are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgments

This project was developed as part of a university course at the University of Sri Jayewardenepura, Sri Lanka. Special thanks to the project supervisors, Dr. Malaka and Dr. Akila Wijethunga, for their guidance and support.
