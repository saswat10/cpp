#include<bits/stdc++.h>
using namespace std;
// brute force would be run loop and check for all 0, 1, 2
// then run another loop and fill another array accordingly




// better approach / optimal
// DUTCH NATIONAL FLAG ALGORITHM
/*
    0 - low -1  = 0
    low - mid-1 = 1
    mid - high-1 = random numbers
    high - n-1 = 2
*/

// TIME COMPLEXITY - O(N) 
// SPACE COMPLEXITY - O(1)

void swap(int a, int b);

void sortArray(vector<int> &arr, int n){
    int low = 0, mid = 0, high = n-1;
    for(int i = 0; i< n; i++){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]== 1){
            mid ++;
        }
        else{
            swap(arr[high], arr[mid]);
            high--;
            // mid ++;
        }
    }
}