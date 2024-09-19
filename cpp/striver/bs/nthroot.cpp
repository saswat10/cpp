// return 1 if == m
// return 0 if < m
// return 2 if > m

int func(int mid, int n, int m){
    long long ans = 1;
    for(int i = 1; i<= n; i++){
        ans = ans*mid;
        if(ans>m) return 2;
    }
    if(ans == m) return 1;
    return 0;
}


int nth_root(int N, int M){
    int low = 1, high = M;
    while(low<=high){
        int mid = (low+high)/2;
        int midN = func(mid, N, M);
        if(midN == 1 ) return mid;
        else if(midN == 2) high = mid-1;
        else low = mid+1;
    } 
    return -1;
}
