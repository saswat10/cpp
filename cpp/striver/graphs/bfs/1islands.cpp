#include <bits/stdc++.h>
using namespace std;

/** @param n = number of rows */
/** @param m = number of cols */


void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid){

    // mark the visited cell
    visited[row][col] = 1;


    queue<pair<int, int>> q;
    q.push({row, col});
    
    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty()){
        int row = q.front().first;
        int cl = q.front().second;
        q.pop();

        for (int delrow = -1; delrow <= 1; delrow++){
            for (int delcol = -1; delcol <= 1; delcol++){
                int nrow = row + delrow;
                int ncol = col + delcol;

                /** pitfall
                 * 
                 *  Check that grid[nrow][ncol] and grid[row][col]
                 *  Check that visited[nrow][ncol] and visited[row][col]
                 * 
                 */
                if(nrow < n && ncol < m &&  nrow >= 0 && ncol >= 0 && grid[nrow][ncol] == '1' && !visited[nrow][ncol]){
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
    }

}

int numIslands(vector<vector<char>> &grid)
{

    int n = grid.size();
    int m = grid[0].size();

    // make a visited matrix
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int cnt = 0;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            if(!visited[row][col] && grid[row][col] == '1'){
                cnt ++;
                bfs(row, col, visited, grid);
            }
        }
    }

    return cnt;
}
    