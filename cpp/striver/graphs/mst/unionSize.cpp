#include <bits/stdc++.h>
using namespace std;

class Disjoint {

private:
  vector<int> parent, size;

public:
  Disjoint(int n) {
    size.resize(n + 1, 0);
    parent.resize(n + 1);

    for (int i = 0; i <= n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int findUParent(int node) {
    if (node == parent[node])
      return node;
    return parent[node] = findUParent(parent[node]);
  }

  void unionBySize(int u, int v) {
    int ulp_u = findUParent(u);
    int ulp_v = findUParent(v);
    if (ulp_u == ulp_v)
      return;
    if (size[ulp_u] < size[ulp_v]) {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    } else {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};