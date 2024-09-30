#include<bits/stdc++.h>
using namespace std;

void printS(int index, vector<int> &ds, int s, int targetSum, int arr[], int size){
    if(index == size){
        if(s == targetSum){
            for(auto it: ds) cout<< it<< " ";
        }
        return;
    }

    ds.push_back(arr[index]);
    s = s + arr[index];

    // pick
    printS(index+1, ds, s, targetSum, arr, size);

    s = s - arr[index];
    ds.pop_back();

    // not pick
    printS(index+1, ds, s, targetSum, arr, size);
}


bool printAny(int index, vector<int> &ds, int s, int targetSum, int arr[], int size){
    if(index == size){
        if(s == targetSum){
            for(auto it: ds) cout<< it<< " ";
            cout<< endl;
            return true;
        }
        return false;
    }

    ds.push_back(arr[index]);
    s = s + arr[index];

    // pick
    if(printAny(index+1, ds, s, targetSum, arr, size) == true) return true;

    s = s - arr[index];
    ds.pop_back();

    // not pick
    if(printAny(index+1, ds, s, targetSum, arr, size)== true) return true; 
    return false; 
}

int CountSubsequences(int index, vector<int> &ds, int s, int targetSum, int arr[], int size){

    // condition not satisfied
    // strictly done if the array contains only the positives
    if(s > targetSum) return 0;

    if(index == size){
        // condition satisfied
       if(s == targetSum) return 1;
    //    not satisfied
       else return 0;
    }

    ds.push_back(arr[index]);
    s = s + arr[index];

    // pick
    int l=  CountSubsequences(index+1, ds, s, targetSum, arr, size);

    s = s - arr[index];
    ds.pop_back();

    // not pick
    int r = CountSubsequences(index+1, ds, s, targetSum, arr, size);

    return l+r;
}

