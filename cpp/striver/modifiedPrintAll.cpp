
/*
  This program will only print one array 
*/

#include <bits/stdc++.h>
using namespace std;

bool printAll(int ind, vector<int> &ds, int arr[], int s, int sum, int n)
{
  if (ind == n)
  {
    if (s == sum)
    {
      for (auto it : ds)
        cout << it << " ";
      cout << endl;
      return true;
    }
    else return false;
  }

  // to pick
  ds.push_back(arr[ind]);
  s += arr[ind];
  if(printAll(ind + 1, ds, arr, s, sum, n)== true) return true;

  s -= arr[ind];
  ds.pop_back();
  if(printAll(ind + 1, ds, arr, s, sum, n)== true) return true;

  return false;
}

int main()
{
  int sum= 2, arr[] = {-1, 1, 0, 1, 2, 1 , -1, 3, 4};
  vector<int> ds;
  printAll(0, ds, arr, 0, sum, 9);
  return 0;
}