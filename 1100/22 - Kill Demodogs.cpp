#include<bits/stdc++.h>
#define ll long long
const int mod=1e9+7;
using namespace std;
int solve()
{
    ll n;
    cin>>n;
    ll ans=((((n*(n+1))%mod)*(4*n-1))%mod*337)%mod;
    cout<<ans<<endl;
}
int main()
{
   
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
 
 // T.C :- O(t)
 // S.C :- O(1)
}
 