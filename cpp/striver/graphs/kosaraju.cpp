#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  void dfs(int i, vector<int> &vis, vector<int> adj[], stack<int> &st) {
    vis[i] = 1;
    for (auto adjNode : adj[i]) {
      if (!vis[adjNode]) {
        dfs(adjNode, vis, adj, st);
      }
    }

    st.push(i);
  }
  void dfs3(int i, vector<int> adjT[], vector<int> &vis) {
    vis[i] = 1;
    for (auto adjNode : adjT[i]) {
      if (!vis[adjNode]) {
        dfs3(i, adjT, vis);
      }
    }
  }

public:
  int kosaraju(int V, vector<int> adj[]) {

    // Step 1 - sort all the edges according to the finishing time
    stack<int> st;
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        dfs(i, vis, adj, st);
      }
    }

    // Step 2 - reverse the graph
    vector<int> adjT[V];
    for (int i = 0; i < V; i++) {
      vis[i] = 0;
      for (auto it : adj[i]) {
        // i -> it
        // convert it -> i
        adj[it].push_back(i);
      }
    }

    // Step 3 - do another dfs
    int scc = 0;
    while (!st.empty()) {
      int node = st.top();
      st.pop();
      if (!vis[node]) {
        scc++; // counts the number
        dfs3(node, adjT, vis);
      }
    }

    return scc;
  }
};