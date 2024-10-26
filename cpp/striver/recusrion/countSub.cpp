#include <bits/stdc++.h>
using namespace std;
// This program will only print one array

int printAll(int ind, int arr[], int s, int sum, int n) {
  if (ind == n) {
    if (s == sum)
      return 1;
    else
      return 0;
  }

  // to pick
  s += arr[ind];
  int l = printAll(ind + 1, arr, s, sum, n);

  s -= arr[ind];
  int r = printAll(ind + 1, arr, s, sum, n);

  return l + r;
}

int main() {
  int sum = 2, arr[] = {-1, 1, 0, 7, 2, 1, -1, 3, 4};
  cout << printAll(0, arr, 0, sum, 9);
  return 0;
}
