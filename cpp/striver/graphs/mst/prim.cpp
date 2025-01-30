#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here

        // we need min heap i.e., priority queue
        // (edgeWeight, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int sum = 0;
        vector<int> visited(V, 0);;

        // we can start from any node
        // here we start from the first node i.e, 0
        pq.push({0, 0});
        while(!pq.empty()){
          auto it = pq.top();
          pq.pop();

          int node = it.second;
          int edWeight = it.first;
          
          if(visited[node] == 1) continue;
          visited[node] =1;
          sum += edWeight;
          for(auto iterator: adj[node]){
            int adjNode = iterator[0];
            int edWt = iterator[1];

            pq.push({edWt, adjNode});
          }

        }

        return sum;
        
    }
};