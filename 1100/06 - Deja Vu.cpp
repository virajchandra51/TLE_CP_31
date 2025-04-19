#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt","w",stderr);
#endif
    int t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        vector<ll>a(n);
        for(int i=0;i<n;i++){//n
            cin>>a[i];
        }
        vector<ll>x(q);
        for(int i=0;i<q;i++){//q
            cin>>x[i];
        }
        ll prev=31;
        for(int i=0;i<q;i++){//q
            if(x[i]>=prev)continue;
            ll val=pow(2,x[i]);
            for(int j=0;j<n;j++){//n*30
                if(a[j]%val==0){
                    a[j]+=(val/2);
                }
            }
            prev=x[i];
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    // T.C :- O(q+n*30);
    // S.C :- O(q+n)
    
}