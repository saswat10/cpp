#include<bits/stdc++.h>
using namespace std;


void findCombination(int index, int target,  vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds){
    if(target == 0){
        ans.push_back(ds);
        return;
    }

    for(int i = index; i<arr.size(); i++){
        if(i > index && arr[i] == arr[i-1]) continue; // avoid picking up same element twice
        if(arr[i] > target) break; // if exceeds target break out

        ds.push_back(arr[i]); 
        findCombination(i+1, target-arr[i], arr, ans, ds);
        ds.pop_back();
    }

}