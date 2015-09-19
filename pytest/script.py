from bbp import *
import time

def readfile(filename, size=8):
    counter = 0
    rlist = []
    outlist = []
    for line in open(filename):
        for char in line:
            outlist.append(hex(ord(char))[2:].upper())
            counter += 1
            if counter >= size:
                counter = 0
                rlist.append("".join(outlist))
                outlist = []
    if len(outlist) > 0:
        rlist.append("".join(outlist))
    return rlist

def pindex(number):
    number = number.upper()
    for line in open("pihex.txt"):
        if number in line:
            return True
        else:
            return False
                    
