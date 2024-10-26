#include <bits/stdc++.h>
using namespace std;

void dfs(int startRow, int startCol, vector<vector<int>> &copyImg,
         vector<vector<int>> &image, int iniColor, int newColor) {

  // Fatality - always mark the visited matrix or the array when you enter the
  // call for dfs or bfs
  copyImg[startRow][startCol] = newColor;
  int n = image.size();
  int m = image[0].size();

  int delRow[] = {-1, 0, 1, 0};
  int delCol[] = {0, 1, 0, -1};

  for (int i = 0; i < 4; i++) {
    int nrow = startRow + delRow[i];
    int ncol = startCol + delCol[i];
    if (nrow < n && ncol < m && nrow >= 0 && ncol >= 0 &&
        image[nrow][ncol] == iniColor && copyImg[nrow][ncol] != newColor) {
      dfs(nrow, ncol, copyImg, image, iniColor, newColor);
    }
  }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                              int color) {
  int iniColor = image[sr][sc];
  vector<vector<int>> copyImage = image;

  int n = image.size();
  int m = image[0].size();

  dfs(sr, sc, copyImage, image, iniColor, color);

  return copyImage;
}