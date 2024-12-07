#include <bits/stdc++.h>
using namespace std;

class Solution {
  /*
  Function to implement the floyd marshall algorithm

  The graph is represented as adjacency matrix, and the matrix
  denotes the weight of the edges(if it exists) else -1

  Do it in place
  */
public:
  void shortest_distance(vector<vector<int>> &matrix) {

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == -1)
          matrix[i][j] = 1e9;
        if (i == j)
          matrix[i][j] = 0;
      }
    }

    for (int k = 0; k < matrix.size(); k++) {
      for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
          matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
        }
      }
    }

    // checking for the negative cycle
    for (int i = 0; i < matrix.size(); i++) {
      if (matrix[i][i] < 0) ;// -> return negative cycle;
    }

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == 1e9)
          matrix[i][j] = -1;
      }
    }
  }
};