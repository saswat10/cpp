#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cin >> n>> m;
    
    // graph here
    vector<int> adj[n+1];
    for(int i = 0; i< m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    return 0;
}

/** in case of weighted graph, store pairs */