#include<vector>
#include<iostream>
#include<stdlib.h>

using namespace std;

bool detectCycle(int node, int parent, int vis[], vector<int> adj[]){
    vis[node] = 1;

    for(auto it: adj[node]){
        if(vis[it] == 0){
            if(detectCycle(it, node, vis, adj) == true) return true;
        }else if(it != parent){
            return true;
        }
    }

    return false;
}


bool useDFS(int V, vector<int> adj[]){
    int vis[V] = {0};
    for(int i = 0; i < V; i++){
        if(vis[i] == 0){
            if(detectCycle(i, -1, vis, adj) == true) return true;
        }
    }

    return false;
}