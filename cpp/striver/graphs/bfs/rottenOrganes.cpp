#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {

    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> cpGrid = grid;
    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){ 
                q.push({{i, j}, 0});
                cpGrid[i][j] = 2;
            }else{
                cpGrid[i][j] = 0;
            }
        }
    }

    int dr[] = {-1, 0, 1, 0}; 
    int dc[] = {0, 1, 0, -1}; 
    int tm = 0;
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        tm = max(tm, time);
        q.pop();

        for(int i = 0; i < 4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(nrow >= 0 && nrow < n 
                && ncol >=0 && ncol < m
                && !cpGrid[nrow][ncol] != 2
                && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, time+1});
                    cpGrid[nrow][ncol] = 2;
                }
        }

    }

    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            if(cpGrid[i][j] !=2 && grid[i][j] == 1){
                return -1;
            }
        }
    }

    return tm;

        
}