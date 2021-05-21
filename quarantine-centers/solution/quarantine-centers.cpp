#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//comparator is used to sort the 2d vector in the non descending order of finishing time
bool flightComp(vector<long long> a, vector<long long> b)
{
    return (a[1] > b[1]);
}

//binary search is used to efficiently find the latest flight(before current flight) that doesn't conflict with the current (i th) flight
// v is already sorted in the non descending order of finishing time
int binarySearch(vector<vector<long long>> &v, int i)
{
    int lo = 0, hi = i - 1;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (v[mid][1] < v[i][0])
        {
            if (v[mid + 1][1] < v[i][0])
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }

    // -1 is returned if there are no non-conflicting prior flights
    return -1;
}

//finds the maximum possible amount of all flights
long long maxM(vector<vector<long long>> &v, int f)
{
    // dynamic array 'data' stores the intermediate amounts
    // data[i] stores the possible amount of money from 0 to i th flight (including i th)
    long long *data = new long long[f];
    data[0] = v[0][2];

    for (int i = 1; i < f; i++)
    {
        long long amnt = v[i][2];   // amount of money from i th flight
        int j = binarySearch(v, i); // takes index (j) of the most latest non conflicting prior flight
        if (j != -1)
            amnt += data[j]; //if there is non conflicting flight then total amount
                             //of money till that (j th) flight (inclusive) is added

        data[i] = max(amnt, data[i - 1]); //store the possible max amount by including or
                                          //excluding the i th flight
    }

    long long result = data[f - 1]; //max possible amount from all flights will be the
                                    //last value of the array
    delete[] data;                  //deleting thr dynamically allocated array

    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, f, p, pI;
        long long m;
        cin >> r >> f >> p;
        long long A[f], Q[f];
        vector<vector<long long>> v; //2d vector is created
        for (int i = 0; i < f; i++)
        {
            cin >> A[i] >> Q[i] >> pI;

            // money from a flight = no of occupying rooms * profit from each room * no of days
            m = min(r, pI) * p * Q[i]; //no of occupying rooms at once will be the minimum of (total capacity, no of passengers of the flight)

            // money that can be raised by each flight is calculated and stored in the 2d vector at the same time
            v.push_back({A[i], A[i] + Q[i] - 1, m}); //2d vector contain (arrival date, leaving date, money) of each flight
        }

        sort(v.rbegin(), v.rend(), flightComp); //sort the 2d vector in the non descending order of finishing time using a comparator

        cout << maxM(v, f) << endl; //max possible amount of money will be calculated by the maxM() function
    }
    return 0;
}
