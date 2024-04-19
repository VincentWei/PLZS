#!/usr/bin/python3

import curses
from datetime import datetime
import time
import sys

chattrs = (curses.A_BLINK, curses.A_BOLD, curses.A_DIM, curses.A_REVERSE, curses.A_STANDOUT, curses.A_UNDERLINE)

timestr = ''
def show_time(stdscr, row):
    global timestr
    new_timestr = datetime.now().isoformat(timespec='seconds')

    if timestr != new_timestr:
        global color_pairs
        if row >= 0:
            stdscr.addstr(row, 0, new_timestr,
                    curses.color_pair(row % color_pairs) | chattrs[row % len(chattrs)])
        else:
            stdscr.addstr(new_timestr,
                    curses.color_pair(row % color_pairs) | chattrs[row % len(chattrs)])
        stdscr.refresh()
        timestr = new_timestr
        return True

    return False

def event_loop(stdscr):
    max_row, max_col = stdscr.getmaxyx()
    row = 0
    while True:
        ch = stdscr.getch()
        if ch == ord('q'):      # the user press `q`
            return
        elif ch != -1:          # any other key pressed
            row = 0
            if show_time(stdscr, row):
                row = 1
        else:                   # no input
            if show_time(stdscr, row):
                row += 1
                if row >= max_row:
                    row = 0

def main(stdscr):
    try:
        global color_pairs
        # Initialize the color pairs by using standard colors as
        # foreground and the transparent color (-1) as background.
        color_pairs = 1
        curses.use_default_colors()
        for c in (curses.COLOR_BLUE, curses.COLOR_CYAN, curses.COLOR_GREEN,
                curses.COLOR_MAGENTA, curses.COLOR_RED, curses.COLOR_YELLOW,
                curses.COLOR_BLACK):
            curses.init_pair(color_pairs, c, -1)
            color_pairs += 1

        stdscr.clear()
        stdscr.timeout(100)     # 100ms
        event_loop(stdscr)
    except KeyboardInterrupt:       # If the user pressed ^C
        return

curses.wrapper(main)
