# Game of Life Simulation  
&nbsp;  
The game of life is in a grid of ***N rows*** and ***N columns***. 
Each cell in the grid is either ***dead*** or ***alive***. In the beginning only a ***single cell*** is alive. 
Then at each steps cells become dead or alive based on the following criteria:

1. ***If 1 or 3 of the neighboring cells (up, down, left or right not in diagonal directions) 
are alive the cell becomes or stays alive.***  
2. ***If 0 or 2 or 4 of the neighboring cells are alive the cell becomes dead or stays dead.***  
  
![image](https://s3.amazonaws.com/hr-assets/0/1557996766-f3371f1a99-4.GameofLife-Map.png)
  
The four cells marked in red are the neighboring cells of the black cell. So, if 1 or 3 of the red cells are alive, 
the black cell will be alive in the next step or dead otherwise.

You are given 

1. ***N*** - size of the grid
2. ***R*** and ***C*** - the row and column of the first cell alive, 
(rows are numbered from 1 to N from top to bottom and columns are numbered from 1 to N from left to right)
3. ***S*** - the number of steps 

You need to find the ***number of cells alive*** after ***S*** steps.

## Input Format

First row will contain ***N***, 
the second row will contain ***R*** and ***C*** separated by a space and the third row will contain ***S***.

## Constraints

- ***1 &le; N &le; 100***
- ***1 &le; R, C &le; N***
- ***0 &le; S &le; 100***

## Output Format

You should output the ***total number of cells*** alive after ***S*** steps.
  
## Sample Input

```
4
2 2
3
```

## Sample Output

```
6
```
  
## Explanation

Cells alive are marked with A and dead cells are marked with .

**Initial state:**

```
....  
.A..  
....  
....  
```


**After step 1:**

```
.A..  
A.A.  
.A..  
....  
```


**After step 2:**

```
....  
...A  
....  
.A..  
```


**After step 3:**

```
...A  
..A.  
.A.A  
A.A.  
```


The answer is ***6***

