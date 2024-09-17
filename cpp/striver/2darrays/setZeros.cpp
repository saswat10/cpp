#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrixOptimal(vector<vector<int>> &matrix, int n, int m)
{

    // int col[m] = matrix[...][0]
    // int row[n] = matrix[0][...]

    int col0 = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark the ith row
                matrix[i][0] = 0;
                // mark the jth col
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                // check for all col and row
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
            matrix[0][j] = 0;
    }

    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
            matrix[i][0] = 0;
    }
}