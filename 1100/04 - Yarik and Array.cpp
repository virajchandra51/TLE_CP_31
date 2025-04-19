#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt","w",stderr);
#endif
    int t=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>v(n);
        for(int i=0;i<n;i++){//n
            cin>>v[i];
        }
        ll ans=INT_MIN;
        int i=0,j=0;
        ll sum=0;
        while(j<n){//n
            if(sum<0){
                sum=0;
                i=j;
            }
            if(i<j){
                if( (v[j]^v[j-1]) & 1 ){
                    sum+=v[j];
                }
                else{
                    sum=v[j];
                    i=j;
                }
            }
            else{
                sum=v[j];
            }
            ans=max(ans,sum);
            j++;
        }
        cout<<ans<<endl;
    }
    // T.C :- O(n)
    // S.C :- o(n)
} 