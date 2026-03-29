#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> depth;
int n;

void dfs(int v, int p, int d){
    depth[v] = d;
    for(int to : g[v]){
        if (to == p) continue;
        dfs(to, v, d+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    g.assign(n+1, {});
    depth.assign(n+1, 0);

    for(int i=0;i<n-1;i++){
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int root = 1;
    for(int i=1;i<=n;i++) if(g[i].size()==1){ root=i; break; }

    dfs(root, 0, 0);

    int mn = 1;
    for(int i=1;i<=n;i++){
        if (g[i].size() == 1 && depth[i] & 1){
            mn = 3; break;
        }
    }

    int mx = n - 1;
    for(int v=1; v<=n; v++){
        int leafChild = 0;
        for(int to : g[v]){
            if (g[to].size() == 1) leafChild++;
        }
        if (leafChild > 1) mx -= (leafChild - 1);
    }

    cout << mn << " " << mx << "\n";
    return 0;
}
// TC: O(n)
// SC: O(n)