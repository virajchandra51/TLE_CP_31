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
        int n;
        cin>>n;
        string s;
        cin>>s;
        map<char,int>freq;
        int count=0;
        vector<int>distinct(n,0);
        for(int i=0;i<n;i++){//nlogn
            freq[s[i]]++;
            if(freq[s[i]]==1){
                count++;
            }
            distinct[i]=count;
        }
        ll ans=0;
        for(int i=0;i<n;i++){//n
            ans+=distinct[i];
        }
        cout<<ans<<endl;
    }
    // TC : - O(nlogn)
    // SC :- O(n)
    
} 