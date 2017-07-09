# agc
Arduboy Game Changer

Ever wished you could change the game on your Arduboy without going back to your computer? Now you can...

## Requirements
You will need:
* An Arduboy
* Any Raspberry Pi (the $5 Zero is recommended for low power consumption)
* A USB powerbank (for powering the Raspberry Pi)
* A micro-USB to micro-USB cable (or a micro-USB to USB adaptor and a micro-USB to USB cable plugged together)
* Some Arduboy games in .hex format

## How does it work?
The Arduboy Game Changer is a Raspberry Pi Zero with special software on it (_agc.py_) that sends a menu of games (_agc.hex_) to the Arduboy. You select the game on the Arduboy itself, then the Raspberry Pi sends the requested game. Here it is in action:



## Getting started
1. Download the latest Raspbian Jessie Lite image from [here](https://www.raspberrypi.org/downloads/raspbian/) although an existing Jessie image will also work
2. At the command prompt, enter the following commands to install AVRDUDE (used to upload games to the Arduboy)
```
sudo apt-get install avrdude
```
To be completed...
