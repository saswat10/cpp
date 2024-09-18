#include <bits/stdc++.h>
using namespace std;

int findAllSubarraySumK(vector<int> &arr, int k)
{
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;

    // O(N x logN)
    // O(N)
    for (int i = 0; i < arr.size(); i++)
    {
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }

    return cnt;
}