#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_VAL = 1e8;
class Solution {

public:
  /*
    Function to implement the Bellman Ford Algorithm
    edges: vector of vectors which represents the graph
    S: source vertex to start traversing graph with
    V: number of vertices
  */

  vector<int> BellmanFord(int V, int S, vector<vector<int>> &edges) {
    vector<int> dist(V, MAX_VAL);
    dist[S] = 0;

    // time complexity is V x E
    for (int i = 0; i < V - 1; i++) {
      for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (dist[u] + wt < dist[v] && dist[u] != MAX_VAL) {
          dist[v] = dist[u] + wt;
        }
      }
    }

    // Nth iteration to check negative cycle
    for (auto it : edges) {
      int u = it[0];
      int v = it[1];
      int wt = it[2];

      if(dist[u]+ wt < dist[v] && dist[u]!=MAX_VAL){
        return {-1};
      }
    }

    return dist;
  }
};