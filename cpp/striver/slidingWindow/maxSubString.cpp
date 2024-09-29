#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    array<int, 256> arr = {-1};

    for(int i = 0; i < 256; i++) {
        arr[i] = -1;
    }

    if (s.size() == 1 || s.size() == 0)
        return s.size();

    int n = s.size();
    int l = 0, r = 0, maxLen = 0;
    while (r < n)
    {
        if (arr[s[r]] != -1)
        {
            if (arr[s[r]] >= l)
            {
                l = arr[s[r]] + 1;
            }
        }

        int len = r - l + 1;
        maxLen = max(len, maxLen);
        arr[s[r]] = r;
        r++;
    }
    // maxLen = max(r-l+1, maxLen);
    return maxLen;
}

int main(){
    cout << lengthOfLongestSubstring("bc");
    return 0;
}