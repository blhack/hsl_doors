#!/usr/bin/python

import os
import time
import random

def fadeOut():
	for i in range(100,0,-5):
		os.system("amixer -c 0 set PCM %s%%" % (i))
		time.sleep(.2)

songs = os.listdir("./dethklok")

song = songs[random.randint(0,len(songs)-1)]

os.system("amixer -c 0 set PCM 100%")
os.system('mpg321 dethklok/%s &' % (song))

time.sleep(30)

print "Killing stuff"
fadeOut()
os.system("killall mpg321")
os.system("amixer -c 0 set PCM 100%")
