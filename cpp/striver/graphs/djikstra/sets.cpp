#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> djikstra(int V, vector<vector<int>> adj[], int S) {
    vector<int> dist(V, 1e9);
    set<pair<int, int>> st;

    st.insert({0, S});
    dist[S] = 0;

    while (!st.empty()) {
      auto it = *(st.begin());
      int node = it.second;
      int dis = it.first;

      st.erase(it);

      for (auto t : adj[node]) {
        int adjNode = t[0];
        int edge = t[1];

        if (dis + edge < dist[adjNode]) {
          // erase  if it existed
          if (dist[adjNode] != 1e9)
            st.erase({dist[adjNode], adjNode});
            
          dist[adjNode] = dis + edge;
          st.insert({dist[adjNode], adjNode});
        }
      }
    }

    return dist;
  }
};