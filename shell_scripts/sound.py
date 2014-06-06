#!/usr/bin/python

import os
import random
import cgi

form = cgi.FieldStorage()
choice = form.getvalue("choice", 1)
sounds = ['america.mp3','mario.mp3','aol.mp3']


try:
	int(choice)
	option = sounds[choice]
except:
	option = random.choice(sounds)

os.system('amixer cset numid=3 1 &')
os.system('mpg123 %s &' % (option))
print option
