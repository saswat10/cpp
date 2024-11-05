#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    vector<int> check(V, 0);

    vector<int> safeNodes;
    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        dfsCheck(i, graph, vis, pathVis, check);
      }
    }

    for (int i = 0; i < V; i++) {
      if (check[i] == 1)
        safeNodes.push_back(i);
    }
    return safeNodes;
  }

  bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &vis,
                vector<int> &pathVis, vector<int> &check) {
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;

    // traverse the adjacent nodes
    for (auto it : adj[node]) {
      // when the nodes is not visited
      if (!vis[it]) {
        if (dfsCheck(it, adj, vis, pathVis, check) == true) {
          check[node] = 0;
          return true;
        }
      }

      // if the node has been previously visited
      // but it has to be visited on the same path
      else if (pathVis[it]) {
        check[node] = 0;
        return true;
      }
    }

    check[node] = 1;
    pathVis[node] = 0;
    return false;
  }
};