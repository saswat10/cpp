#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]) {
  vis[node] = 1;
  for (auto it : adj[node]) {
    if (!vis[it])
      dfs(it, vis, st, adj);
  }

  st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) {
  int vis[V] = {0};
  stack<int> st;

  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      dfs(i, vis, st, adj);
    }
  }

  vector<int> list;
  while (!st.empty()) {
    list.push_back(st.top());
    st.pop();
  }
  return list;
}