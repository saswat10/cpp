#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
  vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
  return f(text1.size() - 1, text2.size() - 1, text1, text2, dp);
}


// TLE for 
/*
  text1 = "ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc"

  text 2 = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" 


*/
int f(int i, int j, string text1, string text2, vector<vector<int>> &dp) {
  if (i < 0 || j < 0)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  if (text1[i] == text2[j])
    return dp[i][j] = 1 + f(i - 1, j - 1, text1, text2, dp);

  return dp[i][j] =
             max(f(i - 1, j, text1, text2, dp), f(i, j - 1, text1, text2, dp));
}

// bottom up approach
// shifting the index
int lcs(string text1, string text2){

  int n = text1.size();
  int m = text2.size();

  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

  for(int i = 0; i<= n; i++) dp[i][0] = 0; 
  for(int i = 0; i<= m; i++) dp[0][i] = 0; 

  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
      else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    }
  }

  return dp[n][m];
}


int lcsspace(string text1, string text2){

  int n = text1.size();
  int m = text2.size();

  vector<int> prev(m+1, 0), cur(m+1, 0);

  for(int i = 0; i<= m; i++) prev[i] = 0; 

  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(text1[i-1]==text2[j-1]) cur[j]=1+prev[j-1];
      else cur[j]=max(prev[j], cur[j-1]);
    }
    prev=cur;
  }

  return prev[m];
}
