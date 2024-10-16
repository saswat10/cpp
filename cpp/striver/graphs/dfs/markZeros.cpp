#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col){
    visited[row][col] = true;
    int n = board.size();
    int m = board[0].size();

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    for(int  i =0; i< 4; i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow >= 0 && nrow < n
            && ncol >= 0 && ncol < m
            && !visited[nrow][ncol]
            && board[nrow][ncol] == 'O'){
                dfs(board, visited, nrow, ncol);
            } 
    }
}

void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    // for first and last row
    for(int j = 0; j < m; j++){
        if(!visited[0][j] && board[0][j] == 'O')
            dfs(board, visited, 0, j);

        if(!visited[n-1][j] && board[n-1][j] == 'O')
            dfs(board, visited, m-1, j);
    }

    // for first and last column
    for(int i = 0; i < n; i++){
        if(!visited[i][0] && board[i][0] == 'O')
            dfs(board, visited, i, 0);

        if(!visited[i][m-1] && board[i][m-1] == 'O')
            dfs(board, visited, i, n-1);
    }

    for(int i = 0; i< n; i++){
        for(int j= 0; j< m; j++){
            if(!visited[i][j] && board[i][j] == 'O') 
                board[i][j] = 'X';
        }
    }
}