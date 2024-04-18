#!/usr/bin/python3

import colorist
from colorist import Color

print(f"{Color.RED}This text is in RED{Color.OFF}!")
colorist.effect_blink("CYAN and BLINKING!", Color.CYAN)
