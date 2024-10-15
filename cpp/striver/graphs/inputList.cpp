#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    /** @param n represents the number of nodes present in the graph */
    /** @param m represents the number of edges present in the graph */
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

/**             
                 0__1__2__3__4__5
        5      0|
       / \     1|      1  1     
      2---4    2|   1        1  1
      |   |    3|   1        1
      1---3    4|      1  1     1
               5|      1     1

    @li - store as adjancency list
    
    1 - [2, 3]
    2 - [1, 4, 5]
    3 - [1, 4]
    4 - [2, 3, 5]
    5 - [2, 4] 
*/