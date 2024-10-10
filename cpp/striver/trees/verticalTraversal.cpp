#include<bits/stdc++.h>
using namespace std;

struct TN {
    int val;
    TN* left;
    TN* right;
    TN() : val(0), left(nullptr), right(nullptr) {}
    TN(int x): val(x), left(nullptr), right(nullptr) {}
    TN(int x, TN* right, TN* left): val(x), left(left), right(right) {}
};



vector<vector<int>> verticalTraversalFunc(TN* root){
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TN*, pair<int, int>>> todo;
    todo.push({root, {0, 0}});

    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();

        TN* node = p.first;
        int x = p.second.first, y= p.second.second;
        nodes[x][y].insert(node->val);
        if(node->left){
            todo.push({node->left ,{--x, ++y}});
        }
        if(node->right){
            todo.push({node->right ,{++x, ++y}});
        }
    }

    vector<vector<int>> ans;
    for(auto p: nodes){
        vector<int> col;
        for(auto q: p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }

    return ans;

}