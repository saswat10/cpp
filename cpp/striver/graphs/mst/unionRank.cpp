#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
  private:
  vector<int> rank, parent;

  public:
  DisjointSet(int n){
    rank.resize(n+1, 0);
    parent.resize(n+1);
    for(int i =0; i <= n; i++){
      parent[i] = i;
    }
  }

  int findUParent(int node){
    if(node == parent[node]) return node;
    return parent[node] = findUParent(parent[node]);
  }

  void unionByRank(int u, int v){
    int ulp_u = findUParent(u);
    int ulp_v = findUParent(v);

    if(rank[ulp_u] == rank[ulp_v]){
      return;
    }else if(rank[ulp_u] > rank[ulp_v]){
      parent[ulp_v] = ulp_u;
    }else if(rank[ulp_u] < rank[ulp_v]){
      parent[ulp_u] = ulp_v;
    }else{
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }

};