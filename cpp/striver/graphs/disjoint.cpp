#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
  vector<int> rank, parent;
  public:
    DisjointSet(int n){
      // making it n+1 will work for both 0 and 1 based indices
      rank.resize(n+1, 0); 
      parent.resize(n+1, 0);
      for(int i = 0; i<=n; i++){
        parent[i] = i;
      }
    }

    int findUPar(int node){
      if(node == parent[node])
        return node;
      
      return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
      int ulp_u = findUPar(u);
      int ulp_v = findUPar(v);

      if(ulp_u == ulp_v) return;
      if(rank[ulp_u] == rank[ulp_v]){
        parent[ulp_u] = ulp_v;
      }else if(rank[ulp_v] < rank[ulp_u]){
        parent[ulp_v] = ulp_u;
      }else{
        parent[ulp_v] = ulp_u;
        rank[ulp_u]++;
      }
    }

    void unionBySize(int u, int v){
      
    }

};