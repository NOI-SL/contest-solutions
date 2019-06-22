# Binary Code  
&nbsp;  
You are given a sequence of bits (a binary string) of length **N**. 
You need to generate a list of binary strings of length **N** starting from the given binary string. 
There can be **no repetitions** in the list, 
and any two consecutive binary strings in the list should differ by **only one bit**. 

For example, assume you are given the binary string 0010. binary strings 0010 and 0110 differ only by one bit; 
0010 and 0111 differ by two bits; 0010 and 0010 are the same; 0200 is not a binary string; 
100 is not a binary string of length 4, while 0100 is a binary string of length 4.

This problem has partial scores. If your list is valid, then your score for that test case is 
![{L\over 2^N}S](https://latex.codecogs.com/svg.latex?%5Cinline%20%7BL%5Cover%202%5EN%7DS), 
where **L** is the number of binary strings in your list and **S** is the allocated score for the test case.
  

## Input Format

The input will contain a non empty string of 0’s and 1’s indicating the initial binary string.

## Constraints

- **1 &le; N &le; 16**
  &nbsp;  
   
#### **Limits**
- **Time Limit**: 1s
- **Memory Limit**: 256MB  
  

## Output Format

First line of the output should contain a single integer **L**, the number of strings in your list.
L lines should follow, the list of values.  
  
  
## Sample Input

```
0010
```

## Sample Output 0

```
6
0010
1010
1000
1100
0100
0000
```
  
## Explanation

This will get a partial score factor of 
![{6\over 2^4} = {6\over 16} = 0.375](https://latex.codecogs.com/svg.latex?%5Cinline%20%7B6%5Cover%202%5E4%7D%20%3D%20%7B6%5Cover%2016%7D%20%3D%200.375), 
out of allocated score for this test case.  
That is, if 10 points were allocated for this test case then you will only get 3.75 points.

