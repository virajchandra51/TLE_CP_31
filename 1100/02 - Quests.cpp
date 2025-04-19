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
        int n,k;
        cin>>n>>k;
        vector<int>a(n),b(n);//n
        for(int i=0;i<n;i++){//n
            cin>>a[i];
        }
        for(int i=0;i<n;i++){//n
            cin>>b[i];
        }
        int maxi=0;
        int sum=0;
        int ans=0;
        for(int i=0;i<min(n,k);i++){//n
            sum+=a[i];
            maxi=max(maxi,b[i]);
            ans=max(ans,sum+(k-(i+1))*maxi);
        }
        cout<<ans<<endl;
    }
    // T.C --> O(n)
    // S.C --> O(n)
    
} 