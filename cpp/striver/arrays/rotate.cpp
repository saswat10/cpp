#include<bits/stdc++.h>
using namespace std;

// brute force approach
// takes O(d) space complexity
void leftRotate(vector<int> &arr, int n , int d){
    d = d%n;
    int temp[d];
    for(int i=0; i< d; i++){
        temp[i] = arr[i];
    }

    for(int i = d; i< n; i++){
        arr[i-d] = arr[i];
    }
    for (int i = n-d; i < n; i++)
    {
        arr[i] = temp[i-(n-d)];
    }
    

}

void Reverse(vector<int> &arr, int start, int end){
    while(start <= end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


void leftRotateOptimal(vector<int> &arr, int n, int d){
    Reverse(arr, 0, d);
    Reverse(arr, d, n);
    Reverse(arr, 0, n);
}