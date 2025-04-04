# MadCatz Cyborg Gaming Light Controller for OpenRGB

![OpenRGB](https://img.shields.io/badge/OpenRGB-Compatible-brightgreen)
![License](https://img.shields.io/badge/License-GPL--2.0-blue)
![Status](https://img.shields.io/badge/Status-Working-success)

Driver implementation for controlling MadCatz Cyborg Gaming Light devices with OpenRGB.

<div align="center">
  <img src="https://openrgb.org/img/OpenRGB_Logo.png" alt="OpenRGB Logo" width="200">
</div>

## 📋 Table of Contents

- [Description](#-description)
- [Hardware Support](#-hardware-support)
- [Features](#-features)
- [Installation](#-installation)
- [Usage](#-usage)
- [Implementation Details](#-implementation-details)
- [Protocol Information](#-protocol-information)
- [Contributing](#-contributing)
- [License](#-license)

## 📝 Description

This driver enables full control of the MadCatz Cyborg Gaming Light within the OpenRGB ecosystem. The MadCatz Cyborg Gaming Light is a customizable RGB desk/ambient lighting device that supports advanced positioning and brightness controls.

## 💻 Hardware Support

| Manufacturer | Model | VID/PID | Supported Features |
|--------------|-------|---------|-------------------|
| MadCatz | Cyborg Gaming Light | 0x06A3 / 0x0DC5 | RGB, Position, Intensity |

## ✨ Features

- **RGB Color Control**: Full 24-bit RGB color customization
- **Position Control**: 9 different positioning options:
  - Center, North, Northeast, East, Southeast, South, Southwest, West, Northwest
- **Vertical Position**: 3 height settings (Low, Middle, High)
- **Intensity Control**: Adjustable brightness levels

## 🔧 Installation

This driver is included in the main OpenRGB application. No additional installation is required beyond installing OpenRGB itself.

1. Download and install [OpenRGB](https://openrgb.org/)
2. Plug in your MadCatz Cyborg Gaming Light device
3. Launch OpenRGB
4. The device should be automatically detected and available for control

## 🚀 Usage

1. Launch OpenRGB
2. Select your MadCatz Cyborg Gaming Light from the device list
3. Use the color picker to set your desired RGB color
4. Adjust position and intensity through the device's control panel

## 📚 Implementation Details

This implementation consists of the following files:

| File | Purpose |
|------|---------|
| `MadCatzCyborgController.cpp/.h` | Core implementation of device communication |
| `MadCatzCyborgControllerDetect.cpp` | Device detection logic |
| `RGBController_MadCatzCyborg.cpp/.h` | OpenRGB interface implementation |

## 🔍 Protocol Information

The device uses a HID-based protocol with the following commands:

| Command | Hex Value | Purpose |
|---------|-----------|---------|
| ENABLE | 0xA1 | Enable device control |
| COLOR | 0xA2 | Set RGB color values |
| POSITION | 0xA4 | Set directional position |
| V_POS | 0xA5 | Set vertical position |
| INTENSITY | 0xA6 | Set brightness level |
| RESET | 0xA7 | Reset device |

Position values are encoded in two bytes, with predefined constants for each position (Center, N, NE, E, SE, S, SW, W, NW).

Vertical position values:
- LOW: 0x08
- MIDDLE: 0x04
- HIGH: 0x02
- ANY: 0x00

## 👥 Contributing

Contributions to improve this driver are welcome. Please follow the OpenRGB contribution guidelines.

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request

## 📄 License

This code is licensed under the same license as the main OpenRGB project (GPL-2.0).

---

<div align="center">
  <i>Part of the <a href="https://openrgb.org">OpenRGB</a> project</i>
</div>
