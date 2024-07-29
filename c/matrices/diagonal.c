#include <stdio.h>

struct Matrix
{
  int A[10];
  int n; // length of the matrix
};

void Set(struct Matrix *m, int i, int j, int x)
{
  if (i == j)
    m->A[i - 1] = x;
}

int Get(struct Matrix m, int i, int j)
{
  if (i == j)
    return m.A[i - 1];
  else
    return 0;
}

void Display(struct Matrix m)
{
  int i, j;
  for (i = 1; i <= m.n; i++)
  {
    for (j = 1; j <= m.n; j++)
    {
      if (i == j)
        printf("%d ", m.A[i - 1]);
      else
        printf("0 ");
    }
    printf("\n");
  }
}

int main()
{
  struct Matrix m;
  m.n = 4;
  Set(&m, 1, 1, 5);
  Set(&m, 2, 2, 4);
  Set(&m, 3, 3, 6);
  Set(&m, 4, 4, 7);

  Display(m);

  return 0;
}