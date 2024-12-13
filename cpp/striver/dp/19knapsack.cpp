#include <bits/stdc++.h>
using namespace std;

int f(int index, int W, vector<int> &wt, vector<int> &val,
      vector<vector<int>> &dp) {
  if (index == 0) {
    if (wt[0] <= W)
      return val[0];
    else
      return 0;
  }
  if (dp[index][W] != -1)
    return dp[index][W];

  int take = INT_MIN;
  int notTake = f(index - 1, W, wt, val, dp);
  if (wt[index] <= W)
    take = val[index] + f(index - 1, W - wt[index], wt, val, dp);

  return dp[index][W] = max(take, notTake);
}

int knapsack(vector<int> &wt, vector<int> &val, int maxWeight, int n) {

  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
  return f(n - 1, maxWeight, wt, val, dp);
}

int knapsackTab(vector<int> &wt, vector<int> &val, int maxWeight, int n) {

  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

  for (int W = 0; W <= maxWeight; W++) {
    dp[0][W] = val[0];
  }

  for (int index = 0; index < n; index++) {
    for (int W = 0; W <= maxWeight; W++) {
      int notTake = 0, take = INT_MIN;

      int notTake = dp[index - 1][W];
      if (wt[index] <= W)
        take = val[index] + dp[index - 1][W - wt[index]];

      dp[index][W] = max(take, notTake);
    }
  }
  return dp[n - 1][maxWeight];
}

int knapsackTabSC1(vector<int> &wt, vector<int> &val, int maxWeight, int n) {

  vector<int> curr(maxWeight + 1, 0), prev(maxWeight + 1, 0);

  for (int W = wt[0]; W <= maxWeight; W++) {
    prev[W] = val[0];
  }

  for (int index = 0; index < n; index++) {
    for (int W = 0; W <= maxWeight; W++) {
      int notTake = 0, take = INT_MIN;

      int notTake = prev[W];
      if (wt[index] <= W)
        take = val[index] + prev[W - wt[index]];

      curr[W] = max(take, notTake);
    }
    prev = curr;
  }
  return prev[maxWeight];
}

int knapsackTabSC2(vector<int> &wt, vector<int> &val, int maxWeight, int n) {

  vector<int> prev(maxWeight + 1, 0);

  for (int W = wt[0]; W <= maxWeight; W++) {
    prev[W] = val[0];
  }

  for (int index = 0; index < n; index++) {
    for (int W = maxWeight; W >= 0; W--) {
      int notTake = 0, take = INT_MIN;

      int notTake = prev[W];
      if (wt[index] <= W)
        take = val[index] + prev[W - wt[index]];

      prev[W] = max(take, notTake);
    }
  }
  return prev[maxWeight];
}