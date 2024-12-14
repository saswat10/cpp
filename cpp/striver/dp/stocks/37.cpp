#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int f(int index, int buy, int cap, vector<int> &prices, int n,
        vector<vector<vector<int>>> &dp) {

    if (index == n || cap == 0)
      return 0;
    if (dp[index][buy][cap] != -1)
      return dp[index][buy][cap];

    if (buy == 1) {
      return dp[index][buy][cap] =
                 max(-prices[index] + f(index + 1, 0, cap, prices, n, dp),
                     f(index + 1, 1, cap, prices, n, dp));
    }

    return dp[index][buy][cap] =
               max(prices[index] + f(index + 1, 1, cap - 1, prices, n, dp),
                   f(index + 1, 0, cap, prices, n, dp));
  }

public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(2, vector<int>(3, -1)));
    return f(0, 1, 2, prices, n, dp);
  }
};