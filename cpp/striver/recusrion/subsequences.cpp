#include <bits/stdc++.h>
using namespace std;

void printF(int ind, vector<int> &ds, int arr[], int n)
{
  if (ind == n)
  {
    for (auto it : ds)
    {
      cout << it << " ";
    }
    if (ds.size() == 0)
      cout << "{}";
    cout << endl;
    return;
  }

  // take or pick the particular index into the subsequence
  ds.push_back(arr[ind]);
  printF(ind + 1, ds, arr, n);
  ds.pop_back();

  // not pick, or not take the condition, this element is not
  // added to your subsequence
  printF(ind + 1, ds, arr, n);
}

int main()
{
  int arr[] = {3, 1, 2};
  vector<int> ds;
  int n = 3;
  printF(0, ds, arr, n);

  return 0;
}