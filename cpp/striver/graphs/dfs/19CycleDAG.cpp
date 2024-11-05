#include <bits/stdc++.h>
using namespace std;

class Solution {

private: 
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;

        // traverse the adjacent nodes
        for(auto it: adj[node]){
            // when the nodes is not visited
            if(!vis[it]){
                if(dfsCheck(it, adj, vis, pathVis) == true)
                    return true;
            }

            // if the node has been previously visited
            // but it has to be visited on the same path
            else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

public:
  bool isCyclic(int V, vector<int> adj[]){
    int vis[V] = {0};
    int pathVis[V] = {0};

    for(int i = 0; i< V; i++){
        if(!vis[i]){
            if(dfsCheck(i, adj, vis, pathVis)== true) return true;
        }
    }
    return false;
  }
};