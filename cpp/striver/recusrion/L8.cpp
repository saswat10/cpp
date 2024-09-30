#include<bits/stdc++.h>
using namespace std;


void findCombination(int targetSum, vector<int> &arr, int size, int index, vector<vector<int>> &ans, vector<int> &ds){
    if(index == size){
        if(targetSum == 0)
            ans.push_back(ds);
        return;
    }

    // pick up the element
    if(arr[index] <= targetSum){
        ds.push_back(arr[index]);
        int newTargetSum = targetSum - arr[index];
        findCombination(newTargetSum, arr, size, index, ans, ds);
        ds.pop_back();
    }

    // not pick the element
    findCombination(targetSum, arr, size, index+1, ans, ds);
}