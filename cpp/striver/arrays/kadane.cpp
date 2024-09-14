#include <bits/stdc++.h>
using namespace std;

long long maxSubarray(int arr[], int n)
{
    long long sum = 0, max = LONG_LONG_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > max)
        {
            max = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
}

// best time to buy and sell stock
void bestTime(int arr[], int n)
{
    int mini = arr[0];
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        int cost = arr[i] - mini;
        maxProfit = max(cost, maxProfit);
        mini = min(mini, arr[i]);
    }
    cout << "Max Profit " << maxProfit;
}