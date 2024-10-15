#include<bits/stdc++.h>
using namespace std;


int main(){
    /** @param n represents the number of nodes present in the graph */
    /** @param m represents the number of edges present in the graph */

    int n, m;
    cin >> n>> m;
    
    // graph here
    int adj[n+1][m+1];
    for(int i = 0; i< m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    return 0;
}

/*              
                 0__1__2__3__4__5
        5      0|
       / \     1|      1  1     
      2---4    2|   1        1  1
      |   |    3|   1        1
      1---3    4|      1  1     1
               5|      1     1
*/