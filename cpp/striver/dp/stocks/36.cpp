#include<bits/stdc++.h>
using namespace std;

// Look at the space optimization code in the TUF platform

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();

       vector<vector<int>> dp(n, vector<int>(2, -1));
       return f(0, 1, prices, n, dp);
    }

    int maxProfitTab(vector<int>& prices) {
       int n = prices.size();

       vector<vector<int>> dp(n+1, vector<int>(2, 0));
       dp[n][0] = 0;
       dp[n][1] = 0;

       for(int index = n-1; index>=0; index--){
        for(int buy = 1; buy>= 0 ; buy--){
          int profit = 0;
          if(buy)
            profit = max(-prices[index] + dp[index+1][0], dp[index+1][1]);
          else
             profit = max(prices[index] + dp[index+1][1], dp[index+1][0]);
          
          dp[index][buy] = profit;
          }
       }

       return dp[0][1];
    }

private:
    int f(int index, int buy, vector<int> &prices, int n, vector<vector<int>> &dp){
      if(index == n) return 0;

      if(dp[index][buy] != -1) return dp[index][buy];
      int profit = 0;
      if(buy)
        profit = max(-prices[index] + f(index+1, 0, prices, n, dp),
         f(index+1, 1, prices, n, dp));
      else
        profit = max(prices[index] + f(index+1, 1, prices, n, dp), f(index+1, 0, prices, n, dp));

      return dp[index][buy] = profit;
    }
};