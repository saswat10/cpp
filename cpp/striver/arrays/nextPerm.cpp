#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPerm(vector<int> &arr){
    int ind = -1;
    int n = arr.size();


    /* This loop runs to find the break point */
    for(int i = n-2; i >= 0; i--){
        if(arr[i] < arr[i+1]){
            ind = 1;
            break;
        }
    }


    /* If no break point found it means 
    the array is in descending order */
    if(ind == -1){
        reverse(arr.begin(), arr.end());
        return arr;
    }

    /* Break point found hence swap with the 
    next integer which bigger than the index */
    for(int i= n-1; i>ind; i--){
        if(arr[i] > arr[ind]){
            swap(arr[i], arr[ind]);
            break;
        }
    }

    reverse(arr.begin(), arr.end());
    return arr;
}