#include <bits/stdc++.h>
using namespace std;


/**
 * @param N = number of nodes
 * @param M = number of edges
 * @param src = source
 */

class Solution {
public:
  vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src) {
    // code here

    vector<vector<int>> adj(N);
    for(auto edge: edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<int> dis(N, INT_MAX);
    dis[src] = 0;
    queue<int> Q;
    Q.push(src);

    while(!Q.empty()){
        int node =  Q.front();
        Q.pop();

        for(auto it: adj[node]){
            if(dis[node] + 1 < dis[it]){
                dis[it] = dis[node] + 1;
                Q.push(it);
            }
        }
    }

    vector<int> ans(N, -1);
    for(int i = 0; i< N;i++){
        if(dis[i]!= INT_MAX){
            ans[i] = dis[i];
        }
    }

    return ans;
  }
};