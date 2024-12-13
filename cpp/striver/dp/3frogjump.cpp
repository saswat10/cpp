#include <bits/stdc++.h>
using namespace std;

int f(int index, vector<int> &height, vector<int> &dp) {
  if (index == 0)
    return 0;
  if (dp[index] != -1)
    return dp[index];

  int right = INT_MAX;
  int left = f(index - 1, height, dp) + abs(height[index] - height[index - 1]);
  if (index > 1)
    right = f(index - 2, height, dp) + abs(height[index] - height[index - 2]);

  return dp[index] = min(right, left);
}

int frogJump(int n, vector<int> &height) {
  vector<int> dp(n + 1, -1);
  return f(n - 1, height, dp);
}

// tabulation 
int frogJumpTabulation(int n, vector<int> &height) {
  vector<int> dp(n, -1);

  for(int i = 1; i < n; i++){
    int fs = dp[i-1] + abs(height[i]- height[i-1]);
    int ss = INT_MAX;
    if(i > 1)
      ss = dp[i-2] + abs(height[i]- height[i-2]);
    
    dp[i] = min(fs, ss);
  }

  return dp[n-1];
}


// for space optimization take prev and prev2 and change them just before updation of the loop
// follow up question is what if there are k jumps
