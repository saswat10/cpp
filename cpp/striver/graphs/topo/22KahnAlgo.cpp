#include <queue>
#include <vector>

using namespace std;

vector<int> topoSort(vector<vector<int>> adj) {
  vector<int> indegree(adj.size(), 0);

  for (int i = 0; i < adj.size(); i++) {
    for (auto it : adj[i]) {
      indegree[it]++;
    }
  }

  queue<int> q;
  for(int i = 0; i < adj.size(); i++){
    if(indegree[i] == 0) q.push(i);
  }

  vector<int> temp;

  while(!q.empty()){

    temp.push_back(q.front());
    int node = q.front();
    q.pop();

    for(auto it: adj[node]){
        indegree[it] --;
        if(indegree[it] == 0)q.push(it);
    }
  }

  return temp;
}