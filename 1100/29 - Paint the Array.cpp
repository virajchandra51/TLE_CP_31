#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    int t;
    cin>>t;
    while(t--){//t
        int n;
        cin>>n;
        vector<ll>v(n);
        for(int i=0;i<n;i++){//n
            cin>>v[i];
        }
        ll gcd1=0,gcd2=0;
        for(int i=0;i<n;i++){//nlog1e18
            if(i&1){
                gcd2 = __gcd(gcd2,v[i]);
            }
            else{
                gcd1 = __gcd(gcd1,v[i]);
            }
        }
        bool flag=true;
        for(int i=1;i<n;i+=2){//n
            if(v[i]%gcd1==0){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<gcd1<<endl;
            continue;
        }
        flag=true;
        for(int i=0;i<n;i+=2){//n
            if(v[i]%gcd2==0){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<gcd2<<endl;
        }
        else{
            cout<<0<<endl;
        }

    }
    // T.C :- O(t*nlog1e18)
    // S.C :- O(t*n)
    
}