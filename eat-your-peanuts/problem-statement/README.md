# Eat Your Peanuts  
&nbsp;  
You and your friends are at a peanut eating contest. There are **N** plates on the table in order **1 to N.** 
You are given the number of peanuts in each plate (not all equal).

You need to **assign** each of your friends **one or more plates** that are **next to each other.** 
You also need to make sure that **no one eats too much** and hurt themselves. 
It is okay if you **don’t assign** plates to **some** of your friends, 
but **all plates** should be **assigned** to someone. 
Same plate **cannot** be assigned to **more than one** of your friends. 

Write a program to **minimize** the **total number** of peanuts eaten by the friend who eats the **most number** of 
peanuts.

### Limits  
Time Limit: 1s  
Memory Limit: 256MB  

## Input Format

The first line of the input has **2** integers **N** and **F** respectively, separated by a space. 
The number of plates and the number of friends.  
Each of the following **N** lines have a single integer,
**A<sub>i</sub>** the number of peanuts in the **i<sup>th</sup>** plate. There can be empty plates too. 
(0 peanuts in the plate)

## Constraints

- **1 &le; N &le; 10<sup>6</sup>**
- **1 &le; F &le; 10<sup>3</sup>**
- **1 &le; A<sub>i</sub> &le; 10<sup>3</sup>** 

## Output Format

Output just **one integer** representing your answer, 
the **total number of peanuts** eaten by the friend who eats most peanuts.
  
## Sample Input

```
6 3
4
2
3
7
1
9
```

## Sample Output 0

```
9
```
  
## Explanation

We assign first **3** plates to one friend i.e. **4 + 2 + 3 = 9**  
We assign next **2** plates to another friend i.e. **7 + 1 = 8**  
We assign last plate to the remaining friend i.e. **9**  
  
Maximum of **{9, 8, 9}** is **9**. So the number of peanuts eaten by the friend who eats most peanuts is **9**.  
  
On the other hand if we assign all plates to just one friend then that friend eats **26** peanuts which is worse than 
the above solution.  

