#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<float>& bucket){
  for(int i = 0; i < bucket.size(); i++){
    float key = bucket[i];
    int j = i - 1;
    while(j >= 0 && bucket[j] > key){
      bucket[j+1] = bucket[j];
      j--;
    }

    bucket[j+1] = key;
  }
}

void bucketSort(float arr[], int n){
  vector<float> b[n];

  // insert into buckets
  for(int i = 0; i < n; i++){
    int bi = n * arr[i];
    b[bi].push_back(arr[i]);
  }

  // sort inidividual buckets using insertion sort
  for(int i = 0; i < n; i++){
    insertionSort(b[i]);
  }

  // concat the buckets
  int index = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < b[i].size(); j++){
      arr[index++] = b[i][j];
    }
  }

}