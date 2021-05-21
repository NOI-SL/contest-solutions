#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t, n, k, flag;
    cin >> t;
    while (t--)
    {
        flag = 1; //contain the result
        cin >> n >> k;
        int data[n];

        for (int i = 0; i < n; i++) //values of all columns are inserted
            cin >> data[i];

        int minH, maxH;     //store the height of the heighest and lowest possible new bricks of a column of the wall
        minH = data[0] + 1; //lowest possible new brick's height of 0th column
        maxH = data[0] + k; //highest possible new brick's height of 0th column

        for (int i = 1; i < n - 1; i++) //columns from 1 to n-2 are selected in each iteration
        {
            if (data[i] >= maxH || data[i] + k + (k - 1) < minH) //if (height of the old bricks of i th column is greater than or equal to the height of lowest possible new brick of previous (i-1 th) column) or
                                                                 //(height of the highest possible new brick of i th column is lesser than the height of the lowest possible new brick of the previous (i-1 th) column) then 2nd rule is broken
            {
                flag = 0; //no solution
                break;
            }
            maxH = min(data[i] + k + (k - 1), maxH + (k - 1)); //height of the highest possible new brick of i th column, while following rules
            minH = max(data[i] + 1, minH - (k - 1));           //height of the lowest possible new brick of i th column, while following rules
        }

        if (data[n - 1] >= maxH || data[n - 1] + k < minH) 
            flag = 0;                                      //no solution
        if (flag)
            cout << "YES" << endl; //flag = 1 -> "YES"
        else
            cout << "NO" << endl; //flag = 0 -> "NO"
    }

    return 0;
}
