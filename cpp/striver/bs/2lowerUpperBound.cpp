#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int n, int x){
    int low = 0, high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (low+high)/2;
        // maybe an answer
        if(arr[mid] >= x){
            ans = mid;
            // look for small index on left
            high = mid -1;
        }
        else {
            low = mid +1; // look for right
        }
    }
    return ans;
}

//upper bound - smallest index such that arr[ind] > x



int main(){
    vector<int> arr = {1, 2, 5, 8, 10, 12, 15};
    cout<< lowerBound(arr, 7, 7);
    auto it = lower_bound(arr.begin(), arr.end(), 7);
    cout<< *it;
    return 0;
}