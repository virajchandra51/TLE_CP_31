#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll arr[n][n];
        for(int i=0;i<n;i++){//n*n
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        ll cnt=0;
        for(int i=0;i<n;i++){//n*n
            for(int j=0;j<n;j++){
                if(arr[i][j]!=arr[n-i-1][n-j-1]){
                    cnt++;
                }
            }
        }
        cnt/=2;
        if(cnt>k){
            cout<<"NO"<<endl;
        }
        else{
            ll temp=k-cnt;
            if(temp%2==0)cout<<"YES"<<endl;
            else{
                if(n%2==0)cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }
        }
    // T.C :- O(n*n)
    // S.C :- O(n*n)
    }
}