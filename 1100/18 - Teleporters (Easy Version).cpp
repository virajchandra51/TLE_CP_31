#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n;
    cin>>n;
    ll c;
    cin>>c;
    vector<ll>cost;//N
    for(int i=1;i<=n;i++){//n
        ll x;
        cin>>x;
        cost.push_back(i+x);
    }
    sort(cost.begin(),cost.end());//nlogn
    int i=0;
    int ans=0;
    while(i<n && cost[i]<=c){//n
        c-=cost[i];
        ans++;
        i++;
    }
    cout<<ans<<endl;
    // T.C :- O(nlogn)
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