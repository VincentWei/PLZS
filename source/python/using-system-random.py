#!/usr/bin/python3

import random

sysrand = random.SystemRandom()

n = 0
while n < 100:
    print(sysrand.random(), end = ', ')
    n += 1
print()
