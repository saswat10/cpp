#include<bits/stdc++.h>
using namespace std;

int better(vector<int> &arr){
    if(arr.size() == 0) return 0;
    sort(arr.begin(), arr.end());

    int n = arr.size();
    int lastSmaller= INT_MIN;
    int cnt = 0; 
    int longest = 1;

    for(int i = 0; i< n; i++){
        if(arr[i]-1 == lastSmaller){
            cnt ++;
            lastSmaller = arr[i];
        }
        else if(lastSmaller != arr[i]){
            cnt = 1;
            lastSmaller = arr[i];
        }
        longest = max(cnt, longest);
    }

    return longest;
}

int optimal(vector<int> & nums){
    int n = nums.size();
    if(n == 0) return 0;
    int longest = 1;
    unordered_set<int> us;

    for(int i = 0; i< n; i++){
        us.insert(nums[i]);
    }

    for(auto it: us){
        if(us.find(it -1) == us.end()){
            int cnt = 1;
            int x = it;
            while(us.find(x+1) != us.end()){
                x = x+1;
                cnt = cnt+1;
            }
            longest = max(longest, cnt);
        }
    }

    return longest;
}