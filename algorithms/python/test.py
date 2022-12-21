import curses
from random import random


maze = [

    [1, 0, 0, 0],
    [1, 1, 0, 1],
    [0, 1, 0, 0],
    [1, 1, 1, 1]

]

rows = len(maze)
cols = len(maze[0])


def display_maze(stdscr: curses.window, maze: list, rows: int, cols: int):
    stdscr.clear()
    stdscr.move(0, 0)
    for y in range(rows):
        for x in range(cols):
            if maze[x][y] == 0:
                stdscr.addch("#", curses.color_pair(1))
            else:
                stdscr.addch(".", curses.color_pair(1))
        stdscr.addch("\n", curses.color_pair(1))
        stdscr.refresh()


class Player:
    def __init__(self, x: int, y: int, stdscr: curses.window, rows: int, cols: int):
        self.x = x
        self.y = y
        self.stdscr = stdscr
        self.rows = rows
        self.cols = cols

    def move(self, x: int, y: int):
        if self.isSafe(self.x + x, self.y + y):
            self.x += x
            self.y += y
        self.stdscr.addch(self.y, self.x, "X", curses.color_pair(2))

    def isSafe(self, x, y):
        return (x >= 0 and x < self.rows and y >= 0 and y < self.cols and maze[x][y] == 1)

    def draw(self):
        self.stdscr.addch(self.y, self.x, "X", curses.color_pair(2))

    def erase(self):
        self.stdscr.addch(self.y, self.x, " ", curses.color_pair(1))

    def get_pos(self):
        return (self.x, self.y)

    def move_withkey(self, key: int):
        up = (0, -1)
        down = (0, 1)
        left = (-1, 0)
        right = (1, 0)
        if key == curses.KEY_UP:
            self.move(*up)
        elif key == curses.KEY_DOWN:
            self.move(*down)
        elif key == curses.KEY_LEFT:
            self.move(*left)
        elif key == curses.KEY_RIGHT:
            self.move(*right)


def main(stdscr: curses.window):
    start = (0, 0)
    end = (cols - 1, rows - 1)
    player = Player(0, 0, stdscr, rows, cols)
    stdscr.clear()
    display_maze(stdscr, maze, rows, cols)
    player.draw()
    while (player.get_pos() != end):
        key = stdscr.getch()
        player.erase()
        player.move_withkey(key)
        stdscr.refresh()
    stdscr.refresh()
    stdscr.addstr(rows + 1, 0, "You win!")
    stdscr.getkey()


curses.wrapper(main)
