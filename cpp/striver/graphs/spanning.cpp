#include <bits/stdc++.h>
using namespace std;

class Solution {

  // Function to find the sum of the weights of the minimum spanning trees
  int spanningTree(int V, vector<vector<int>> adj[]) {

    // SC = O(E)
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    vector<int> vis(V, 0);
    int sum = 0;

    // {wt, node}
    pq.push({0, 0});

    // E
    while (!pq.empty()) {
      // log E
      auto it = pq.top();
      pq.pop();

      int node = it.second;
      int wt = it.first;

      if (vis[node] == 1)
        continue;

      // add it to the mst
      vis[node] = 1;
      sum += wt;

      // E log E
      for (auto itr : adj[node]) {
        int adjNode = itr[0];
        int edW = itr[1];
        if (!vis[adjNode]) {
          pq.push({edW, adjNode});
        }
      }
    }

    // E log E  + E log E
    // E log E
    return sum;
  }
};