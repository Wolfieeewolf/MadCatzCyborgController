# MadCatz Cyborg Gaming Light Controller for OpenRGB
This repository contains a driver for the MadCatz Cyborg Gaming Light for use with [OpenRGB](https://openrgb.org).

## Overview
The MadCatz Cyborg Gaming Light is a customizable RGB lighting device that offers:
- Adjustable RGB lighting
- Position control with 9 different positions
- Vertical height adjustment
- Intensity control

This driver allows OpenRGB to control these lights, providing a modern interface for controlling this hardware on current systems.

## Features
- Supports full RGB color control
- Enables positioning control (Center, North, Northeast, East, Southeast, South, Southwest, West, Northwest)
- Supports vertical position adjustment (Low, Middle, High)
- Allows intensity/brightness adjustment
- Uses standard HID drivers for communication

## Implementation Details
- Device is identified using VID: 0x06A3, PID: 0x0DC5
- Communicates via simple HID commands for all lighting functions
- Compatible with the identification used in pycyborg library

## Usage
To use this driver with OpenRGB:
1. Make sure your MadCatz Cyborg Gaming Light is connected via USB
2. Place these files in the `Controllers/MadCatzCyborgController` directory of your OpenRGB installation
3. Compile OpenRGB
4. Launch OpenRGB to detect and control your Cyborg Gaming Light

## Troubleshooting
If OpenRGB fails to detect your MadCatz Cyborg device:
- Ensure the device is properly connected
- Verify that no other software is currently using the device
- Check that you have the correct permissions to access HID devices

## License
This project is licensed under GPL-2.0 as part of the OpenRGB project.
