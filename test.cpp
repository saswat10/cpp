#include <bits/stdc++.h>
using namespace std;


int findSquareSum(int num)
{
    int sum = 0;
    while (num != 0)
    {
        int x = num % 10;
        sum = sum + (x * x);
        num = num / 10;
    }
    return sum;
}

bool isHappy(int n)
{
    map<long long, int> mp;
    mp[n]++;
    if (n == 1 || n == 7)
        return true;

    int sum = findSquareSum(n);
    while (true)
    {
        mp[sum]++;
        if (mp[sum] > 1)
            return false;
        if (sum == 1 || sum == 7)
            return true;
        else{
            sum = findSquareSum(sum);
            continue;
        }
    }
}


bool isIsomorphic(string s, string t) {
        unordered_map<int, int> s1;
        unordered_map<int, int> s2;

        for (int i = 0; i < s.size(); i++) {
            s1[s.at(i)] += i;
            s2[t.at(i)] += i;
        }

        if (s1.size() != s2.size())
            return false;
        for (auto it1 = s1.begin(), it2 = s2.begin();
             it1 != s1.end() && it2 != s2.end(); ++it1, ++it2) {
            if (it1->second != it2->second)
                return false;
        }

        return true;
    }


bool canArrange(vector<int>& arr, int k) {
        vector<int> hash(k, 0);
        for(int i = 0; i< arr.size(); i++){
          int hashIndex = ((arr[i] % k) + k) % k;
          hash[hashIndex]++;
        }

        int cnt = 0;
        for(int i = 0 ;i <= (k-1)/2; i++){
          if(i == 0) {
            if(hash[i] >= 2) cnt ++;
          }else{
            if(hash[i] == hash[k-i-1]) cnt = cnt+hash[i];
          }
        }
        cout<< cnt;

        if(cnt == arr.size()/2) return true;
        return false;
    }


vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> a = arr;
    sort(a.begin(), a.end());
        map<int, int> mp;

        int rank = 1;
        for(int i = 0; i< arr.size(); i++){
            if( i == 0);
            else if(a[i] == a[i-1]) ;
            else rank++;
            mp[a[i]] = rank;
        }

        for(auto &x: arr){
          x = mp[x];
        }

        return arr;
}

 int minLength(string s) {
       string k = s;
       while(k.find("AB") != -1 || k.find("CD") != -1){
        if(k.find("AB") != -1)
            k = k.substr(0, k.find("AB")) + k.substr(k.find("AB")+2);
        if(k.find("CD") != -1)
            k = k.substr(0, k.find("CD")) + k.substr(k.find("CD")+2);
       } 

      cout<< k;
       return k.length();
    }

int main(){
    minLength("ABFCACDB");
    cout<<endl;
    return 0;
}