# Sorting Stones  
&nbsp;  
Kasun has a bunch of rocks of different weights, placed in a line. 
He wants to sort them in order of **increasing weight**. He just learned the **quicksort algorithm**. 
He wants to try it out. But the problem is that rocks are heavy, 
and in order to sort them he will have to carry them around to swap their positions. 
So he wants to find out **how many swaps** he will need to sort using quicksort, beforehand.

Here is the version of quicksort he wants to try on a given ordered list of rocks. 
Please check the example below to understand better.

1. He stops if there are no rocks or only one rock is present. 
If not, he takes the last (rightmost) rock in the list as the **pivot**. 
And he considers the leftmost rock of the list as the **wall**. 
2. Then he takes the rocks one by one from left to right excluding the **pivot** and does following in **(3)**.
3. If the weight of the rock taken above in **step 2** is less than the weight of the **pivot**, 
then he does the following in the exact given order. That is first do (a), then (b):  
&nbsp;&nbsp;&nbsp;&nbsp;a. He swaps the above rock with the rock in the position **wall** of the list.  
&nbsp;&nbsp;&nbsp;&nbsp;b. And then he moves the position of the **wall** to the rock that is 
at immediate right side of it.
4. Once 2-3 is done he swaps the **pivot** rock with the rock in the position **wall** of the list. 
5. **Repeat** steps 1-5 for following 2 sub-lists:  
&nbsp;&nbsp;&nbsp;&nbsp;a. Sub-list starting from leftmost rock to the rock just before (to the left) the wall. 
i.e. \[leftmost, **wall-1**]  
&nbsp;&nbsp;&nbsp;&nbsp;b. Sub-list starting from the rock just after (to the right) the wall to the rightmost rock. 
i.e \[ **wall+1**, rightmost]  

#### Example Run: 
List of numbers having rock weights: \[5 4 9 1 3 7 2 8 6]  
  
|                                                                      Operation                                                                     	|    Current State &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;     	| Swaps &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;   	|
|:--------------------------------------------------------------------------------------------------------------------------------------------------	|:-------------------:	|:-----:	|
| 1) Considering [5 4 9 1 3 7 2 8 6], 6 is the pivot, wall is at 5’s position                                                                        	| [*5* 4 9 1 3 7 2 8 **6**] 	|       	|
| 2) Looking at [5 4 9 1 3 7 2 8]                                                                                                                    	| [***5* 4 9 1 3 7 2 8** 6] 	|       	|
| 3) 5 is less than 6. Swap 5 with the rock at the wall position. But the wall is at 5’s position, therefore no swaps. Increase wall position by one 	| [**5 *4* 9 1 3 7 2 8** 6] 	|       	|
| 3) 4 is less than 6. Swap 4 with the rock at the wall position. But the wall is at 4’s position, therefore no swaps. Increase wall position by one 	| [**5 4 *9* 1 3 7 2 8** 6] 	|       	|
| 3) 9 is greater than 6. Do nothing                                                                                                                 	| [**5 4 *9* 1 3 7 2 8** 6] 	|       	|
| 3) 1 is less than 6. Swap 1 with the rock at the wall position. Increase wall position by 1                                                        	| [**5 4 1 *9* 3 7 2 8** 6] 	|   1   	|
| 3) 3 is less than 6. Swap 3 with the rock at the wall position. Increase wall position by 1                                                        	| [**5 4 1 3 *9* 7 2 8** 6] 	|   2   	|
| 3) 7 is greater than 6. Do nothing                                                                                                                 	| [**5 4 1 3 *9* 7 2 8** 6] 	|       	|
| 3) 2 is less than 6. Swap 2 with the rock at the wall position. Increase wall position by 1                                                        	| [**5 4 1 3 2 *7* 9 8** 6] 	|   3   	|
| 3) 8 is greater than 6. Do nothing                                                                                                                 	| [**5 4 1 3 2 *7* 9 8** 6] 	|       	|
| 4) swap pivot rock (6) with the rock at wall position                                                                                              	| [**5 4 1 3 2 *6* 9 8** 7] 	|   4   	|
| 5) Repeat steps 1-5 for [5 4 1 3 2] and [9 8 7]                                                                                                    	| [**5 4 1 3 2** 6 **9 8 7**] 	|       	|
| 1) Considering [5 4 1 3 2], 2 is the pivot, wall is at 5’s position                                                                                	| [*5* 4 1 3 **2** 6 9 8 7] 	|       	|
| 2) Looking at [5 4 1 3]                                                                                                                            	| [***5* 4 1 3** 2 6 9 8 7] 	|       	|
| 3) 5 is greater than 2. Do nothing                                                                                                                 	| [***5* 4 1 3** 2 6 9 8 7] 	|       	|
| 3) 4 is greater than 2. Do nothing                                                                                                                 	| [***5* 4 1 3** 2 6 9 8 7] 	|       	|
| 3) 1 is less than 2. Swap 1 with the rock at the wall position. Increase wall position by 1                                                        	| [**1 *4* 5 3** 2 6 9 8 7] 	|   5   	|
| 3) 3 is greater than 2. Do nothing                                                                                                                 	| [**1 *4* 5 3** 2 6 9 8 7] 	|       	|
| 4) swap pivot rock (2) with the rock at wall position                                                                                              	| [**1 *2* 5 3** 4 6 9 8 7] 	|   6   	|
| 5) Repeat steps 1-5 for [1] and [5 3 4]                                                                                                            	| [**1** 2 **5 3 4** 6 9 8 7] 	|       	|
| 1) Considering [1], there’s only one element. Do nothing                                                                                           	| [**1** 2 5 3 4 6 9 8 7] 	|       	|
| 1) Considering [5 3 4], 4 is the pivot, wall is at 5’s position                                                                                    	| [1 2 ***5*** 3 **4** 6 9 8 7] 	|       	|
| 2) Looking at [5 3]                                                                                                                                	| [1 2 ***5* 3** 4 6 9 8 7] 	|       	|
| 3) 5 is greater than 4. Do nothing                                                                                                                 	| [1 2 ***5* 3** 4 6 9 8 7] 	|       	|
| 3) 3 is less than 4. Swap 3 with the rock at the wall position. Increase wall position by 1                                                        	| [1 2 **3 *5** 4 6 9 8 7] 	|   7   	|
| 4) swap pivot rock (4) with the rock at wall position                                                                                              	| [1 2 **3 *4*** 5 6 9 8 7] 	|   8   	|
| 5) Repeat steps 1-5 for [3] and [5]                                                                                                                	| [1 2 **3** 4 **5** 6 9 8 7] 	|       	|
| 1) Considering [3], there’s only one element. Do nothing                                                                                           	| [1 2 **3** 4 5 6 9 8 7] 	|       	|
| 1) Considering [5], there’s only one element. Do nothing                                                                                           	| [1 2 3 4 **5** 6 9 8 7] 	|       	|
| 1) Considering [9 8 7], 7 is the pivot, wall is at 9’s position                                                                                    	| [1 2 3 4 5 6 *9* 8 **7**] 	|       	|
| 2) Looking at [9 8]                                                                                                                                	| [1 2 3 4 5 6 ***9* 8** 7] 	|       	|
| 3) 9 is greater than 7. Do nothing                                                                                                                 	| [1 2 3 4 5 6 ***9* 8** 7] 	|       	|
| 3) 8 is greater than 7. Do nothing                                                                                                                 	| [1 2 3 4 5 6 ***9* 8** 7] 	|       	|
| 4) swap pivot rock (7) with the rock at wall position                                                                                              	| [1 2 3 4 5 6 ***7* 8** 9] 	|   9   	|
| 5) Repeat steps 1-5 for [ ] and [8 9]                                                                                                              	| [1 2 3 4 5 6 7 **8 9**] 	|       	|
| 1) Considering [ ], there are no elements. Do nothing.                                                                                             	| [1 2 3 4 5 6 7 8 9] 	|       	|
| 1) Considering [8 9], 9 is the pivot, wall is at 8’s position                                                                                      	| [1 2 3 4 5 6 7 ***8* 9**] 	|       	|
| 2) Looking at [8]                                                                                                                                  	| [1 2 3 4 5 6 7 ***8*** 9] 	|       	|
| 3) 8 is less than 9. Swap 8 with the rock at the wall position. But the wall is at 8’s position, therefore no swaps. Increase wall position by one 	| [1 2 3 4 5 6 7 **8** *9*] 	|       	|
| 4) swap pivot rock (9) with the rock at wall position. But both are the same, therefore no swaps.                                                  	| [1 2 3 4 5 6 7 **8** *9*] 	|       	|
| 5) Repeat steps 1-5 for [8] and [ ]                                                                                                                	| [1 2 3 4 5 6 7 **8** 9] 	|       	|
| 1) Considering [8], there’s only one element. Do nothing                                                                                           	| [1 2 3 4 5 6 7 **8** 9] 	|       	|
| 1) Considering [ ], there are no elements. Do nothing                                                                                              	| [1 2 3 4 5 6 7 8 9] 	|       	|  

Total **9 swaps**.

### Limits  
Time Limit: 3s  
Time Limit(Java/Java8): 4s  
Memory Limit: 512MB  

## Input Format

The first line of the input has **1** integer **N**, the number of rocks.  
Each of the following **N** lines have a single integer, 
**A<sub>i</sub>** the weight of the rock in the **i<sup>th</sup>** position. 
Each weight is a number between 1 and N and **all weights** are **different**.
  
## Constraints

- **1 &le; N &le; 10<sup>7</sup>**
- **1 &le; A<sub>i</sub> &le; N** 

## Output Format

Output just **one integer** representing your answer, the **total number of swaps**, 
if Kasun tries to sort the rocks based on the quicksort version described above.
  
## Sample Input

```
9
5
4
9
1
3
7
2
8
6
```

## Sample Output

```
9
```
  
## Explanation

Explained Above
