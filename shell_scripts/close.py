#!/usr/bin/python

import os

os.system('amixer cset numid=3 1 &')
os.system('mpg321 shut_down.mp3 &')

print "content-type:text/trollery"
print

print "Doors closing"
