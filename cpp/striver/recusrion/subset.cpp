#include<bits/stdc++.h>
using namespace std;


// geeks for geeks
void subSetSum(int index, int sum, int N, vector<int> &arr, vector<int> &ans){
    if(index == N){
        ans.push_back(sum);
        return;
    }

    // take the element
    subSetSum(index+1, sum+ arr[index], N, arr, ans);

    // do not take the element
    subSetSum(index+1, sum, N, arr, ans);
}


// leetcode
// type 2 subset sum problem
// sort the array
void findSubset(int index, vector<int>& nums, vector<int> &ds, vector<vector<int>> &ans){
    ans.push_back(ds);

    for(int i = index; i< nums.size(); i++){
        if(i!=index && nums[i] == nums[i-1]) continue;
        ds.push_back(nums[i]);
        findSubset(i+1, nums, ds, ans);
        ds.pop_back();
    }
}
