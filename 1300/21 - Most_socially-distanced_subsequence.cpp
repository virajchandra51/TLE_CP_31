#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];//O(n)
        vector<int> ans; 
        ans.push_back(a[0]);
        for(int i=1; i<n-1; i++){//O(n)
            if((1ll*a[i]-a[i-1]) * (1ll*a[i+1]-a[i]) < 0) {
                ans.push_back(a[i]);
            }
        }
        ans.push_back(a[n-1]);
        cout<<ans.size()<<endl; //O(n)
        for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}

// TC = O(n)
// SC = O(n)