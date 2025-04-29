#include <bits/stdc++.h>
using namespace std;

/*
  Advantage of Counting Sort:
    - Counting sort generally performs faster than all comparison-based sorting algorithms,
      such as merge sort and quicksort, if the range of input is of the order of the number of input.
    - Counting sort is easy to code
    - Counting sort is a stable algorithm.

  Disadvantage of Counting Sort:
    - Counting sort doesn’t work on decimal values.
    - Counting sort is inefficient if the range of values to be sorted is very large.
    - Counting sort is not an In-place sorting algorithm, It uses extra space for sorting the array elements.
*/

vector<int> countSort(vector<int> &arr){
  int n = arr.size();
  int m = 0;

  // find the maximum element in the array
  for(int i = 0; i < n; i++)
    m = max(arr[i], m);

  vector<int> countArray(m+1, 0);

  for(int i = 0; i < n; i++)
    countArray[arr[i]]++;

  for(int i = 0; i <= n; i++)
    countArray[i] += countArray[i-1];
  
    
  vector<int> res;
  for(int i = n-1; i >= 0; i--){
    res[countArray[arr[i]]-1] = arr[i];
    countArray[arr[i]]--;  
  }
  

  return res;
}