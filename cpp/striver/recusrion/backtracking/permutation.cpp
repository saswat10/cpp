#include<bits/stdc++.h>
using namespace std;

void recursivePer1(vector<int>&ds, vector<int> &nums, vector<vector<int>>&ans, int freq[]){
    if(ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i< nums.size(); i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i] = 1;
            recursivePer1(ds, nums, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

void recursivePer2(int index, vector<int> &nums, vector<vector<int>> &ans){
    if(index == nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i = index; i< nums.size(); i++){
        swap(nums[index], nums[i]);
        recursivePer2(index+1, nums, ans);
        swap(nums[index], nums[i]);
    }
}