#include <iostream>
using namespace std;

class LowerTriangleMatrix
{
private:
  int *A;
  int n;

public:
  LowerTriangleMatrix()
  {
    n = 2;
    A = new int[2 * (2 + 1) / 2];
  }
  LowerTriangleMatrix(int n)
  {
    this->n = n;
    A = new int[(n + 1) * n / 2];
  }
  ~LowerTriangleMatrix() { delete[] A; }
  void Set(int i, int j, int x);
  int Get(int i, int j);
  void Display();
  int GetDimension() { return n; }
};
void LowerTriangleMatrix::Set(int i, int j, int x)
{
  if (i >= j)
  {
    int index = ((i * (i - 1)) / 2) + j - 1;
    A[index] = x;
  }
}
int LowerTriangleMatrix::Get(int i, int j)
{
  if (i >= j)
  {
    int index = ((i * (i - 1)) / 2) + j - 1;
    return A[index];
  }
  return 0;
}
void LowerTriangleMatrix::Display()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i >= j)
      {
        int index = ((i * (i - 1)) / 2) + j - 1;
        cout << A[index] << " ";
      }
      else
        cout << "0 ";
    }
    cout << endl;
  }
}

int main()
{
  int d;
  cout << "Enter dimensions \n";
  cin >> d;

  LowerTriangleMatrix lm(d);
  int x;
  cout << "Enter all the elements \n";
  for (int i = 1; i <= d; i++)
  {
    for (int j = 1; j <= d; j++)
    {
      if (i >= j)
        cin >> x;
      lm.Set(i, j, x);
    }
  }

  lm.Display();
  return 0;
}