# Paths with Cards  
&nbsp;  
You and your friend Praveen came up with a new game with playing cards. 
Praveen would pick **2** cards from the pack and you have to create a path between the two cards using the rest of the 
cards in the pack of cards. But the problem is that each card has a cost. So, 
the target is to keep the cost as low as possible.  
  
A pack of playing cards has **52** cards. Each card belongs to one of the following suits.  

1. Diamonds (♦) - **D**  
2. Clubs (♣) - **C**  
3. Hearts (♥) - **H**  
4. Spades (♠) - **S**  
  
There will be 13 cards in each suit.  

1. Ace - **A**  
2. 2 - **2**  
3. 3 - **3**  
4. 4 - **4**  
5. 5 - **5**  
6. 6 - **6**  
7. 7 - **7**  
8. 8 - **8**  
9. 9 - **9**  
10. 10 - **10**  
11. Jack - **J**  
12. Queen - **Q**  
13. King - **K**  
  

![image](https://s3.amazonaws.com/hr-assets/0/1560570716-6c5c07ee14-Fotolia_23299310_Subscription_Monthly_M.jpg)  
  
Each card can be identified by the letter of the suit followed by the value of the card.  
  
Ex:  
  
- King of Clubs - “**CK**”  
- Ace of Diamond - “**DA**”  
- 3 of Hearts - “**H3**”  
- 10 of Spades - “**S10**”  
  
In a path, any consecutive pair of cards there can be only 1 change from the following 2 changes.  
  
1. Increase or decrease the value by 1. Ace(A) can be used to go from a King to 2 or vice versa.  
	Example:  
  
	- K-> A -> 2 -> 3  
	- K -> Q -> J -> 10  
      
2. Change the suit to 1 higher it or lower it and go circle (order given above).  
	Example:  
  
	- Clubs -> Hearts -> Spades -> Diamonds  
	- Clubs -> Diamonds -> Spades -> Hearts  

For example, these are possible ways to go from 10 of Diamonds (D10) to 9 of Hearts (H9).  
	  
	- D10 -> C10 -> H10 -> H9
	- D10 -> D9 -> S9 -> H9
	- D10 - DJ -> CJ -> CQ -> HQ -> HJ -> SJ -> S10 -> S9 -> H9  
  
Your task is to write a program to find a path from the **2** given cards, which has the minimum cost.  
If there are multiple paths with the minimum cost, the one with the minimum number of cards should be selected.   
It is guaranteed that there are no multiple paths that have the minimum cost and the same no. of cards.  
    

## Input Format

The first line of the input has **2** strings **S** & **E** separated by a space, the starting card and ending card.  
**4** lines will follow, a line for each suit according to the order given above (D, C, H, S).  
Each of the **4** lines will have **13** integers, 
values of the cards in that suit according to the order given above (A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K). 
  

## Constraints

- **0 &le; cost of a card &le; 10<sup>5</sup>**
- **2 &le; L &le; 52**
- **1 &le; C &le; 10<sup>7</sup>**
  &nbsp;  
   
#### **Limits**
- **Time Limit**: 1s
- **Memory Limit**: 256MB

## Output Format

The program should output **2** lines.  
The first line should contain **2** integers **L** & **C** separated by a space, 
the number of the cards in the path(including the starting and ending cards) and the cost of the path 
(including the costs of the starting and ending cards).  
The second line should contain **L** strings separated by spaces. The path from the starting card to the ending card. 
It should start with the Starting Card & end with the Ending Card.  
  
  
## Sample Input

```
D10 H9
61 74 78 61 34 83 85 66 21 1 2 1 35
56 46 99 22 95 82 58 84 25 53 43 2 38
33 57 87 80 75 37 88 77 2 2 2 3 72
100 39 22 100 67 41 42 41 2 49 2 1 84
```

## Sample Output 0

```
6 11
D10 DJ SJ HJ H10 H9
```
