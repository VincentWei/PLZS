#!/usr/bin/python3

from datetime import datetime
import time
import sys

timestr = ''
def show_time():
    global timestr
    new_timestr = datetime.now().isoformat(timespec='seconds')

    if timestr != new_timestr:
        print('\033[1G\x1b[31m', new_timestr, '\x1b[0m', sep='', end='')
        sys.stdout.flush()
        timestr = new_timestr

while True:
    try:
        time.sleep(0.5)
        show_time()
    except KeyboardInterrupt:
        print()
        sys.exit(0)
