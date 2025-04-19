#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n;
    cin>>n;
    vector<ll>v(n);//n
    for(int i=0;i<n;i++){//n
        cin>>v[i];
    }
    ll ans=0;
    ll total_sum=accumulate(v.begin(),v.end(),0LL);//n
    ll sum=0;
    for(int i=0;i<n-1;i++){//n*log(1e14)
        sum+=v[i];
        ans=max(ans,__gcd(total_sum-sum,sum));
    }
    cout<<ans<<endl;
    // T.C :- O(n*log(1e14));
    // S.C :- O(n)
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt","w",stderr);
#endif
    
    
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
} 