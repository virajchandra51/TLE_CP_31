#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);//n
    for(int i=0;i<n;i++){//n
        cin>>v[i];
    }
    map<ll,bool>mp;//n
    for(auto it:v){//nlogn
        mp[it]=true;
    }
    for(int i=0;i<n;i++){//nlogn
        if(mp.find(v[i]-k)!=mp.end()){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    // T.C :- O(nlogn)
    // S.C :- O(n)

}
int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
}