#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // function to find the shortest distance of all the vertices
  // from the source vertex S
  vector<int> djikstra(int V, vector<vector<int>> adj[], int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    vector<int> dist(V);
    for (int i = 0; i < V; i++)
      dist[i] = 1e9;

    dist[S] = 0;
    q.push({0, S});

    while (!q.empty()) {
      int dis = q.top().first;
      int node = q.top().second;
      q.pop();

      for (auto it : adj[node]) {
        int edgeWeight = it[1];
        int adjNode = it[0];

        if (dis + edgeWeight < dist[adjNode]) {
          dist[adjNode] = dis + edgeWeight;
          q.push({dist[adjNode], adjNode});
        }
      }
    }
    return dist;
  }
};