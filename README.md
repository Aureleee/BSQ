# Project BSQ

This project is about solving the **Biggest Square Problem (BSQ)**.
The goal is simple: given a board with obstacles, the program finds the largest possible square that can fit inside without touching any obstacles.

---

## How to use

First, you can generate a board using the script:

```bash
./generator_board.sh x y d
```

- **x** → width of the board
- **y** → height of the board
- **d** → density of obstacles :D

Each execution writes the output into a file called **board.txt**.
(You can also edit **board.txt** manually if you want to play with custom boards.)

Then, to run the program:

```bash
./a.out "board.txt"
```

---
lets take this example has studie: 10.ox
........o.
..........
...o.....o
.........o
o....o....
....o.....
..........
..........
..........
.......o..

how the program works,
first we extract the block info and store it in a structucr, .visible, pos_y pos_y. in this exanle the block info are 1:0:8
1:2:3
1:2:9
1:3:9
1:4:0
1:4:5
1:5:4
1:9:7

This code is all about edges > Lets take this edge for examble 5, 2, 2, 2, 0, 0, 0, 0, 0, -1, (include the first 3 bloc)
it shoz the max size and pos of the biggest squre max boxe = 3 , pos_y = 6 , pos_x = 0
## Notes

// This file is not meant to be pushed.
**AURÈLE, DON’T BE DUMB PLEASE.** 