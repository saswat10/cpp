#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int mini = prices[0];
        for(int i = 0; i<prices.size(); i++){
          int cost = prices[i] - mini;
          maxP = max(cost, maxP);
          mini = min(mini, prices[i]);
        }
        return maxP;
    }
};