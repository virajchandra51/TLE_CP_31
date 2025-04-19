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
        ll a;
        vector<pair<ll,ll>>v;
        for(int i=0;i<n;i++){//n
            cin>>a;
            v.push_back({a,i});
        }
        vector<ll>pre(n);
        sort(v.begin(),v.end());//nlogn
        pre[0]=v[0].first;
        for(int i=1;i<n;i++){//n
            pre[i]=pre[i-1]+v[i].first;
        }
        vector<ll>ans(n);
        for(int i=0;i<n;i++){//nlogn
            int j=i;
            int found=i;
            while(j<n){
                pair<ll,ll>temp={pre[j]+1,INT_MIN};
                ll idx=lower_bound(v.begin(),v.end(),temp)-v.begin();
                idx--;
                if(idx==j){
                    break;
                }
                found+=idx-j;
                j=idx;
            }
            ans[v[i].second]=found;
        }
        for(int i=0;i<n;i++){//n
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    // T.C :- O(nlogn)
    // S.C :- O(n)
} 