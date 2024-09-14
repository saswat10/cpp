// Element that occurs N/2 times
#include <bits/stdc++.h>
using namespace std;

/*
  Brute Force - Take a element and scan every time
*/

/*
    Better - Hashing
*/
int majorityElement(vector<int> &arr, int n)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second > arr.size() / 2)
            return it.first;
    }
    return -1;
}

/*
    Optimal - Moore's Algorithm
    O(N), O(1)
*/

int mooreAlgo(vector<int> &arr, int n)
{
    int cnt = 0;
    int ele;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            ele = arr[i];
        }
        else if (arr[i] == ele)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    // after this if take ele and run through loop 
    // while couting the number of times
    // after that check whether it is greater than N/2
}