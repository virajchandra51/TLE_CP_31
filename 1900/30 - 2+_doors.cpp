#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;

    vector<vector<pair<int,int>>> g(n);
    vector<int> forced(n,-1);

    for(int i=0;i<q;i++){
        int u,v,x;
        cin>>u>>v>>x;
        --u;--v;

        if(u==v) forced[u]=x;
        else{
            g[u].push_back({v,x});
            g[v].push_back({u,x});
        }
    }

    vector<int> a(n,0);

    for(int b=0;b<30;b++){
        vector<int> val(n,1);

        for(int i=0;i<n;i++)
            if(forced[i]!=-1)
                val[i]=(forced[i]>>b)&1;

        for(int i=0;i<n;i++)
            for(auto [j,x]:g[i])
                if(((x>>b)&1)==0)
                    val[i]=0;

        for(int i=0;i<n;i++){
            if(val[i]==0 || forced[i]!=-1) continue;

            bool ok=true;
            for(auto [j,x]:g[i]){
                if(((x>>b)&1) && val[j]==0){
                    ok=false;
                    break;
                }
            }

            if(ok) val[i]=0;
        }

        for(int i=0;i<n;i++)
            if(val[i]) a[i]|=(1<<b);
    }

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}

// Time Complexity: O(30 * (n + q))
// Space Complexity: O(n + q)