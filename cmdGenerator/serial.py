import time
import serial

print("Sending . . . ")
with open("Commands.txt") as commands:
    data2bsend = commands.readlines()
ser = serial.Serial('/dev/ttyWHATEVER',9600)
ser.write('100 a 20 b 90 c')
ser.readline()


#for instruction in data2bsend:
#    print instruction
#    time.sleep(0.5)
print("finished!")
