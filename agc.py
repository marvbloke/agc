# Arduboy Game Changer
# Server v0.1
# by Matthew Begg
# 2017-03-28

import serial
import serial.tools.list_ports
import time
import os

gameName = "evade.hex"
port = "/dev/ttyACM0"



# Upload a hex file to Arduboy

def uploadHex(fileName):
    ser = serial.Serial(port, 1200, timeout=1, dsrdtr=True)
    ser.close()
    ser.open()
    ser.close()
    time.sleep(1)
    os.system("avrdude -v -patmega32u4 -cavr109 -P" + port + " -b57600 -D -Uflash:w:" + fileName + ":i")
    print(fileName + " uploaded.")
      
# Upon startup, send the menu to the Arduboy

uploadHex("agc.hex")
print("agc menu uploaded.")

# Wait for reboot
time.sleep(5)

# Read the name of the game

ser = serial.Serial(port, 9600)
ser.close()
ser.open()
print("Waiting for game name from ArduBoy...")
gameName = str(ser.readline().decode())
gameName = str(gameName.replace('\r\n',''))
print("Game name: " + gameName + ".hex")
ser.close()
time.sleep(2)
# Upload selected game
uploadHex("games/" + gameName + ".hex")

# Main loop
while True:
    pass
