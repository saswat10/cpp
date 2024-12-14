#include<bits/stdc++.h>
using namespace std;

/** 
*  @param s : text
*  @param p : pattern
*/

class Solution0based {

private:
    bool f(int i, int j, string &pattern, string &text, vector<vector<int>> &dp){

      // Base cases
      if(i < 0 && j < 0) return true;
      if(i < 0 && j >= 0) return false;

      if(j < 0 && i >= 0){
        for(int ii = 0 ; ii <= i; ii++){
          if(pattern[ii] != '*') return dp[i][j] = false;
        }
        return dp[i][j] = true;
      }



      // Memoization steps - always call this after the base cases
      if(dp[i][j] != -1) return dp[i][j];

      // All possible ways
      if(pattern[i] == text[j] || pattern[i] == '?') {
        return dp[i][j] = f(i-1, j-1, pattern, text, dp);
      }   

      if(pattern[i] == '*'){
        return dp[i][j] = f(i-1, j, pattern, text, dp) 
                  | f(i, j-1, pattern, text, dp);
      }

      return dp[i][j] = false;
    }
public:
    bool isMatch(string text, string pattern) {
        int n = pattern.size();
        int m = text.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n-1, m-1, pattern, text, dp);
    }
};

class Solution1based {
private:
    bool f(int i, int j, string &pattern, string &text, vector<vector<int>> &dp){

      if(i == 0 && j == 0) return true;
      if(i == 0 && j > 0) return false;

      if(j == 0 && i > 0){
        for(int ii = 1 ; ii <= i; ii++){
          if(pattern[ii-1] != '*') return false;
        }
        return true;
      }
      if(dp[i][j] != -1) return dp[i][j];

      if(pattern[i-1] == text[j-1] || pattern[i] == '?') {
        return dp[i][j] = f(i-1, j-1, pattern, text, dp);
      } 

      if(pattern[i-1] == '*'){
        return dp[i][j] = f(i-1, j, pattern, text, dp) 
                  or f(i, j-1, pattern, text, dp);
      }

      return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return f(n, m, p, s, dp);
    }
};


class SolutionTabulated {
private:
    bool f(int i, int j, string &pattern, string &text, vector<vector<int>> &dp){

      if(i == 0 && j == 0) return true;
      if(i == 0 && j > 0) return false;

      if(j == 0 && i > 0){
        for(int ii = 1 ; ii <= i; ii++){
          if(pattern[ii-1] != '*') return false;
        }
        return true;
      }
      if(dp[i][j] != -1) return dp[i][j];

      if(pattern[i-1] == text[j-1] || pattern[i] == '?') {
        return dp[i][j] = f(i-1, j-1, pattern, text, dp);
      } 

      if(pattern[i-1] == '*'){
        return dp[i][j] = f(i-1, j, pattern, text, dp) 
                  or f(i, j-1, pattern, text, dp);
      }

      return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        dp[0][0] = false;
        for(int j = 0; j <= m; j++){
          dp[0][j] = false;
        }

        for(int i= 1; i <= n; i++){
          bool flag = true;
          for(int ii = 1; ii <= i; ii++){
            if(p[ii-1] != '*'){
              flag = false;
              break;
            }
          }

          dp[i][0] = flag;
        }

        for(int i = 1; i <= n; i++){
          for(int j = 1; j <= m; j++){
            if(p[i-1] == s[j-1] || p[i-1] == '?'){
              dp[i][j] = dp[i-1][j-1];
            }
            else if (p[i-1] == '*'){
              dp[i][j] = dp[i-1][j] or dp[i][j-1];
            }
            else{
              dp[i][j] = false;
            }
          }
        }

        return dp[n][m];
    }
};