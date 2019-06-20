# A Mouse in a Maze  
&nbsp;  
There is a mouse stuck inside a maze. You have to write a program to help the mouse to exit the maze given the maze, 
starting position of the mouse and exit locations.

At the start, the mouse is in the starting cell. Mouse spends **a minute** in a cell before moving. 
At the end of every minute the mouse can decide to either **stay** in the current cell or **move** to a neighboring 
(**up**, **right**, **down**, **left**) cell. The motion happens instantly, and it’ll stay the next minute in the next 
cell. The mouse can not step outside the maze and also mouse cannot step into a blocked cell.

But unlike the previous maze, this maze have cells with **bombs** in them!  
The mouse **can’t stay** in a cell that has a **bomb** when the bomb is **ON**, 
but the mouse **can stay** in a cell with a bomb when the bomb is **OFF**. 
The bombs that are **ON** will be **turned off** in the **next step** by the bomb squad. 
But the problem is that terrorists will **turn all the switched off bombs ON** in **every step** as well. 
So they just keep **turning ON and OFF, every minute;** the change happens at the end of the **minute instantly**.

A maze is a two-dimensional grid having **R** rows and **C** columns, having **RxC** cells inside it. 
Each cell can either be a **free cell,** a **blocked cell** or a **cell with a bomb** that can be in either 
**ON state** or **OFF state.** The mouse cannot go into a blocked cell or a cell that has a bomb in the ON state. 
Starting cell and exit cells will always be free cells without any bombs, so that the mouse can go.

Find the **shortest time** for the mouse to move into one of the exit cells.

### Limits  
Time Limit: 1s  
Memory Limit: 256MB  

## Input Format

The first line of the input has **2** integers **R** and **C** respectively, separated by a space. 
**R** is the number of rows in the maze and **C** is the number of columns in the maze.  
Next **R** lines have **C** characters each representing the **RxC gird**. Each character represents a cell. 
Each character can be one of the following representing:

- **“.”** (dot/full stop) - An empty cell
- **“#”** - A blocked cell
- **“S”** (capital s) - The starting cell
- **“E”** (capital e) - An exit cell
- **“N”** (capital n) - A Bomb that is ON
- **“F”** (capital f) - A Bomb that is OFF

## Constraints

 - **1 &le; R, C &le; 20**

## Output Format

Output just **one integer** representing your answer, 
the **shortest time in minutes** for the mouse to reach from starting cell to one of the exit cells.  
If the mouse can’t reach an exit then output **-1**.
  
## Sample Input 0

```
6 10
....S#E...
...###....
F..#E.....
#N###..###
.......#..
.......#..
```

## Sample Output 0

```
15
```

## Explanation 0

The position of the mouse in each step is indicated by **'M'**  
  
  
**Step 1**  

``...MS#E...``  
``...###....``  
``N..#E.....``  
``#F###..###``  
``.......#..``  
``.......#..``  


**Step 2**  
``..M.S#E...``  
``...###....``  
``F..#E.....``  
``#N###..###``  
``.......#..``  
``.......#..``  

**Step 3**  
``.M..S#E...``  
``...###....``  
``N..#E.....``  
``#F###..###``  
``.......#..``  
``.......#..``  

**Step 4**  
``....S#E...``  
``.M.###....``  
``F..#E.....``  
``#N###..###``  
``.......#..``  
``.......#..``  

**Step 5**  
``....S#E...``  
``...###....``  
``NM.#E.....``  
``#F###..###``  
``.......#..``  
``.......#..``  

**Step 6**  
``....S#E...``  
``...###....``  
``FM.#E.....``  
``#N###..###``  
``.......#..``  
``.......#..``  

**Step 7**  
``....S#E...``  
``...###....``  
``N..#E.....``  
``#M###..###``  
``.......#..``  
``.......#..``  

**Step 8**  
``....S#E...``  
``...###....``  
``F..#E.....``  
``#N###..###``  
``.M.....#..``  
``.......#..``  

**Step 9**  
``....S#E...``  
``...###....``  
``N..#E.....``  
``#F###..###``  
``..M....#..``  
``.......#..``  

**Step 10**  
``....S#E...``  
``...###....``  
``F..#E.....``  
``#N###..###``  
``...M...#..``  
``.......#..``  

**Step 11**  
``....S#E...``  
``...###....``  
``N..#E.....``  
``#F###..###``  
``....M..#..``  
``.......#..``  

**Step 12**  
``....S#E...``  
``...###....``  
``F..#E.....``  
``#N###..###``  
``.....M.#..``  
``.......#..``  

**Step 13**  
``....S#E...``  
``...###....``  
``N..#E.....``  
``#F###M.###``  
``.......#..``  
``.......#..``  

**Step 14**  
``....S#E...``  
``...###....``  
``F..#EM....``  
``#N###..###``  
``.......#..``  
``.......#..``  

**Step 15**  
``....S#E...``  
``...###....``  
``N..#M.....``  
``#F###..###``  
``.......#..``  
``.......#..``  
  
## Sample Input 1

```
6 10
.NN.S#....
.NN###....
.NN#E#....
#.####.###
.......#..
.........E
```

## Sample Output 1

```
-1
```

## Explanation 1

The mouse can't move out of the place because the opening is covered by bombs.