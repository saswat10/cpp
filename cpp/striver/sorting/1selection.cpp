// first search for the minimum of the array
// then replace the minimum at the required index, for ascending order
#include <bits/stdc++.h>
using namespace std;


void selection_sort(int arr[], int size) {
  for (int i = 0; i <= size - 2; i++) {
    int min = i;
    for (int j = i; j <= size - 1; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    int temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  selection_sort(arr, n);
  for (int i = 0; i < n; i++)
    cout << arr[i] << "\n";
  return 0;
}