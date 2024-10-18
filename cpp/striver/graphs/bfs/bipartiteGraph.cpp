#include <bits/stdc++.h>
using namespace std;

bool check(int start, int V, vector<int> adj[], vector<int> &color) {

  queue<int> Q;
  Q.push(start);
  color[start] = 0;

  while (!Q.empty()) {
    int node = Q.front();
    Q.pop();

    for (auto it : adj[node]) {
      // if the adjacency is not colored yet
      // then we have to give the color to the node
      if (color[it] == -1) {
        color[it] = !color[node];
        Q.push(it);
      }
      // is the adjacent node having the same color as the node
      // someone did color it before
      else if (color[it] == color[node])
        return false;
    }
  }
  return true;
}

bool isBipartite(int V, vector<int> adj[]) {
  vector<int> color(V, -1);
  for (int i = 0; i < V; i++) {
    if (color[i] == -1) {
      if (check(i, V, adj, color) == false) {
        return false;
      }
    }
  }
  return true;
}
