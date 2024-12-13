#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int cutRod(vector<int> &price) {
        vector<vector<int>> dp(price.size(), vector<int>(price.size()+1, -1));
        return f(price.size()-1, price, price.size()+1, dp);
    }

    int f(int index, vector<int> &price, int N, vector<vector<int>> &dp){
      if(index == 0) return N * price[0];

      int notTake = 0 + f(index-1, price, N, dp);
      int take = INT_MIN;

      int rodLength = index+1; 
      if(rodLength <= N) take = f(index, price, N-rodLength, dp) + price[index];

      return dp[index][rodLength] = max(take, notTake);
    }
};