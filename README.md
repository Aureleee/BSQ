# Project BSQ

This project solves the **Biggest Square Problem (BSQ)**.
The goal is simple: given a board with obstacles, the program finds the largest possible square that can fit inside without touching any obstacles.

---

## How to use

First, you can generate a board using the script:

```bash
./generator_board.sh x y d
```

- **x** → width of the board
- **y** → height of the board
- **d** → density of obstacles

Each execution writes the output into a file called **board.txt**.
(You can also edit **board.txt** manually if you want to create custom boards.)

Then, to run the program:

```bash
./a.out board.txt
```

---

## Example

Let’s take this example as a study case: **10.ox**

```
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
```

### Step 1 – Extracting blocks
The program first extracts the block info and stores it in a structure with the fields `.visible`, `pos_x`, `pos_y`.
In this example, the block info is:

```
1:0:8
1:2:3
1:2:9
1:3:9
1:4:0
1:4:5
1:5:4
1:9:7
```

### Step 2 – Edges
This code is all about edges.
Let’s take this edge for example: `5, 2, 2, 2, 0, 0, 0, 0, 0, -1` (including the first 3 blocks).

It shows the max size and position of the biggest square:
- **max box** = 3
- **pos_y** = 6
- **pos_x** = 0

---

## Notes

This file is not meant to be pushed.
**AURÈLE, DON’T BE DUMB PLEASE.** 