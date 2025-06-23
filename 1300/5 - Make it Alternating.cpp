#include<bits/stdc++.h>
using namespace std;

long long int mod = 998244353;

int main(){
    int t; cin >>t;
    while(t--){
        string s; cin>> s;
        int n = s.size();
        long long int ans = 1;
        int ansLen = 1;
        int cur = 1;
        for(int i = 1; i < n; i++){ //O(n)
            if(s[i] != s[i-1]){
                ansLen++;
                ans = (ans*cur)%mod;
                cur = 1;
            } else {
                cur++;
            }
        }
        ans = (ans*cur)%mod;
        for(int i = 1; i<= n-ansLen; i++){ //O(n)
            ans = (ans*i)%mod;
        }
        cout<<n-ansLen<<" "<<ans<<endl;
    }
}

// TC = O(n)
// SC = O(n)