#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<vector<int>> adj(numCourses);
      for(auto it: prerequisites){
        adj[it[0]].push_back(it[1]);
      }

        vector<int> indegree(numCourses, 0);

    for (int i = 0; i < numCourses; i++) {
      for (auto it : adj[i]) {
        indegree[it]++;
      }
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0)
        q.push(i);
    }

    vector<int> temp;
    int cnt = 0;

    while (!q.empty()) {
      int node = q.front();
      temp.push_back(node);
      q.pop();
      cnt ++;

      for (auto it : adj[node]) {
        indegree[it]--;
        if (indegree[it] == 0)
          q.push(it);
      }
    }
    // return temp;

    if(cnt == numCourses) return true;
    else return false;
    }
};  