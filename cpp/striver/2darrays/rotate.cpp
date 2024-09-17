#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateBrute(vector<vector<int>> & matrix, int n){

    vector<vector<int>> ans;

    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++){
            ans[j][n-1-i] = matrix[i][j];
        }
    }

    return ans;
}

vector<vector<int>> in_place_rotate(vector<vector<int>> &matrix, int n){

    // transpose the matrix
    for(int i = 0; i< n-1; i++){
        for(int j = i+1; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reverse the rows
    for(int i = 0; i< n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }

    return matrix;
} 