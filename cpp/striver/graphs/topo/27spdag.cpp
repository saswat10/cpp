#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  void topoSort(int node, vector<int> &vis, vector<vector<pair<int, int>>> &adj,
                stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
      int v = it.first;
      if (!vis[v]) {
        topoSort(v, vis, adj, st);
      }
    }
    st.push(node);
  }

public:
  vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
    // code here
    vector<vector<pair<int, int>>> adj(N);

    for (int i = 0; i < M; i++) {
      int u = edges[i][0];  // starting node
      int v = edges[i][1];  // directed node
      int wt = edges[i][2]; // weight of the path

      adj[u].push_back({v, wt});
    }

    // step 1: find the topo sort
    vector<int> vis(N, 0);
    stack<int> st;

    // M - no of edges
    for (int i = 0; i < N; i++) {
      if (!vis[i]) {
        topoSort(i, vis, adj, st);
      }
    }

    // step 2: relax the edges
    vector<int> dist(N, INT_MAX);
    dist[0] = 0;
    while (!st.empty()) {
      int node = st.top();
      st.pop();

      if (dist[node] != INT_MAX) { // why this condition required
        for (auto &it : adj[node]) {
          int v = it.first;   // destination or directed node
          int wt = it.second; // weight of the path

          if (dist[node] + wt < dist[v])
            dist[v] = dist[node] + wt;
        }
      }
    }

    for (auto &d : dist) {
      if (d == INT_MAX)
        d = -1;
    }

    return dist;
  }
};