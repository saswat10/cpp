#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int col, vector<int> adj[], vector<int> &color) {
  color[node] = col;

  for (auto it : adj[node]) {
    if (color[it] == -1) {
      if (dfs(it, !col, adj, color) == false)
        return false;
    } else if (color[it] == col) {
      return false;
    }
  }
  return true;
}

bool isBipartite(int V, vector<int> adj[]) {
  vector<int> color(V, -1);

  for (int i = 0; i < V; i++) {
    if (color[i] == -1) {
      if (dfs(i, 0, adj, color) == false)
        return false;
    }
  }
  return true;
}
