#include<bits/stdc++.h>
using namespace std;


/*
    This is the optimal solution if the array
    has both negative and positive types of numbers
*/

int longestSubarrayWithSumK(vector<int> a, long long k){
    map<long long, int> preMapSum;
    long long sum = 0;
    int maxLength = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if(sum == k){
            maxLength = max(maxLength, i+1);
        }
        long long rem = sum - k;
        if(preMapSum.find(rem) != preMapSum.end()){
            int len = i -preMapSum[rem];
            maxLength = max(maxLength, len);
        }
        if(preMapSum.find(sum) == preMapSum.end()){
            preMapSum[sum] = i;
        }
    }

    return maxLength;
    
}


/*
    This is the optimal solution if the array
    has only positives and zeroes.

    TC = worst case O(2N)
    SC = O(1)
*/

int longestSubarrayOptimal(vector<int> a, long long k){
    int left = 0, right =0;
    long long sum = 0;
    int maxLen = 0;
    int n = a.size();
    while(right < n){
        while(left <= right && sum > k){
            sum  -= a[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right < n) sum += a[right];
    }
    return maxLen;
}