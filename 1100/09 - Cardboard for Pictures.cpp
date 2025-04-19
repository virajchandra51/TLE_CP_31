#include <bits/stdc++.h>
using namespace std;

#define ll long long 

void solve(){
    ll n, c; 
    cin >> n >> c;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {//n
        cin >> a[i];
    }
    ll l = 1, r = 1e9,ans=-1;
    while(l <= r) {//log(1e9)*n
        ll mid = l + (r - l) / 2;
        ll sum_all = 0;
        for(int i = 0; i < n; ++i) {
            sum_all += (a[i] + 2 * mid) * (a[i] + 2 * mid);
            if(sum_all > c) break;
        }
        if(sum_all <= c) {
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    // T.C :- O(n*log1e9)
    // S.C :- O(n)
}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
}