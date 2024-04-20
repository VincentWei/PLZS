#!/usr/bin/python3

import time

def my_seed(seed):
    global holdrand
    holdrand = seed

def my_rand():
    global holdrand
    holdrand = (holdrand * 214013 + 2531011) >> 16 & 0x7fff
    return holdrand

my_seed(time.time_ns())
n = 0
while n < 100:
    print(my_rand(), end = ', ')
    n += 1
print()
