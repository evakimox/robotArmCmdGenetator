#!/usr/bin/python
import time

#send serial commands stored in a file to arduino board
def SendFromFile(speed = 10, filename = "Commands.txt"):
    with open("Commands.txt") as Commands:
        data2bsend = Commands.readlines()

    for instruction in data2bsend:
        print instruction
        time.sleep(1/speed)
    return;

print("Sending. . .")
SendFromFile()
print("Finished!")

