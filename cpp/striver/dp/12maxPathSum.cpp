#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
  if(j < 0 || j > matrix[0].size()-1) return -1e8;
  if(i == 0) return matrix[0][j];
  if(dp[i][j] != -1) return dp[i][j];

  int u = matrix[i][j] + f(i-1, j, matrix, dp);
  int ld = matrix[i][j] + f(i-1, j-1, matrix, dp);
  int rd = matrix[i][j] + f(i-1, j+1, matrix, dp);

  return dp[i][j] = max(u, max(ld, rd));
}

int getMaxPoints(vector<vector<int>> &matrix){
  int m = matrix.size();
  int n = matrix[0].size();

  vector<vector<int>> dp(m, vector<int>(n, -1));

  int maxi = -1e8;
  for(int j = 0; j < n; j++){
    maxi = max(maxi, f(m-1, j, matrix, dp));
  }

  return maxi;
}

// this is not TLE
class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();

        if (m == 1 || n == 1) return A[0][0];

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, INT_MAX));
        int ans = INT_MAX;

        for (int i = 0; i < A.size(); ++i) {
            ans = std::min(ans, minFallingPathSum(A, 0, i, dp));
        }

        return ans;
    }

    int minFallingPathSum(std::vector<std::vector<int>>& A, int row, int col, std::vector<std::vector<int>>& dp) {
        int m = A.size();
        int n = A[0].size();

        if (dp[row][col] != INT_MAX) return dp[row][col];

        if (row == m - 1)
            return dp[row][col] = A[row][col];

        int left = INT_MAX, right = INT_MAX;

        if (col > 0)
            left = minFallingPathSum(A, row + 1, col - 1, dp);

        int straight = minFallingPathSum(A, row + 1, col, dp);

        if (col < n - 1)
            right = minFallingPathSum(A, row + 1, col + 1, dp);

        dp[row][col] = std::min(left, std::min(straight, right)) + A[row][col];

        return dp[row][col];
    }
};
