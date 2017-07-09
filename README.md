# Arduboy Game Changer
by __marvbloke__

Ever wished you could change the game on your Arduboy without going back to your computer? Now you can...
## Requirements
You will need:
* An Arduboy
* Any Raspberry Pi (the $5 Zero is recommended for low power consumption)
* A USB powerbank (for powering the Raspberry Pi when you're in the park)
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
3. Install the Arduboy Game Changer software on the Raspberry Pi
```
git clone --depth 1 git://github.com/marvbloke/agc
```
4. Using SFTP (or SAMBA or your favourite method) copy all your favourite Arduboy games into a folder called ```/home/pi/agc/games``` - they must be in .hex format.
5. You can test it works by connecting your Arduboy to the Raspberry Pi then entering these commands:
```
cd /home/pi/agc
sudo python agc.py
```
6. If you have the same games I've already displayed in the menu (with the exact same filenames) then they will launch fine. However, if you've got different games...
## Customising the list of games
1. On a PC or Mac, use the Arduino IDE to open _agc.ino_
2. Edit the GAMES_LENGTH number to the number of games you have
3. Edit the names of the games to match those in your games folder (without the .hex extension). Note that the names can't contain spaces or special characters.
4. In the Arduino IDE, go to the Sketch menu and choose 'Export compiled Binary'. This will create two .hex files
__IMPORTANT:__ Delete the 'with bootloader' file immediately. Using this file could brick your Arduboy!!!
5. Rename ```agc.ino.leonardo.hex``` to just ```agc.hex``` and copy this onto your Raspberry Pi in the ```/home/pi/agc``` folder.
## Setting agc to run when the Raspberry is turned on
To be completed...
