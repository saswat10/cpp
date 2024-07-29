#include <stdio.h>
#include <stdlib.h>

int main()
{
  int A[3][4] = {{1, 2, 3, 4}, {3, 4, 5, 6}, {5, 6, 7, 8}};

  int *B[3];
  B[0] = (int *)malloc(4*sizeof(int));
  B[1] = (int *)malloc(4*sizeof(int));
  B[2] = (int *)malloc(4*sizeof(int));

  int **C;
  C = (int **)malloc(3*sizeof(int *));
  C[0] = (int *)malloc(4*sizeof(int));
  C[1] = (int *)malloc(4*sizeof(int));
  C[2] = (int *)malloc(4*sizeof(int));

  return 0;
}