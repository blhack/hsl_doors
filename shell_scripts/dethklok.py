#!/usr/bin/python

import os
import random

songs = os.listdir("./dethklok")

song = songs[random.randint(0,len(songs)-1)]

os.system('amixer cset numid=3 1 &')
#os.system('mpg321 dethklok/%s &' % (song))
os.system("python ./dethhandler.py")

print "content-type:text/trollery"
print

print "Doors closing"
