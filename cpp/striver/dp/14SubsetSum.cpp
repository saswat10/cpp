#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool f(int ind, int tar, vector<int>& arr, vector<vector<int>> &dp){
        if(tar == 0) return true;
        if(ind == 0) return arr[0]==tar;
        if(dp[ind][tar] != -1) return dp[ind][tar];
        
        bool notTake = f(ind-1, tar, arr, dp);
        bool take = false;
        if(tar >= arr[ind]) 
            take = f(ind-1, tar-arr[ind], arr, dp);
        
        
        
        return dp[ind][tar] = notTake | take;
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        
        vector<vector<int>> dp(arr.size(), vector<int>(target+1, -1));
        return f(arr.size()-1, target, arr, dp);        
    }


    // check again this is wrong
    bool iterative(vector<int>& arr, int target){
      vector<vector<bool>> dp(arr.size(), vector<bool>(target+1, 0));

      for(int i = 0; i < arr.size(); i++) dp[i][0] == true;
      dp[0][arr[0]] == true;

      for(int k = 1; k <= target; k++){
        for(int index = 1; index < arr.size(); index++){
          bool notTake = dp[index][k];
          bool take = false;
          if(arr[index] <=  target)
            take = dp[index][target-arr[index]];
          
          dp[index][target] = notTake | take;
        }
      }

      return dp[arr.size()-1][target]; 
    }
};