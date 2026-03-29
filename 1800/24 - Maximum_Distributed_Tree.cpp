#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

vector<vector<int>> g;
vector<ll> weights;

int dfs(int u, int p, int n){
    int sz = 1;
    for(int v : g[u]) if(v != p){
        int s = dfs(v, u, n);
        weights.push_back(1LL * s * (n - s));
        sz += s;
    }
    return sz;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        g.assign(n+1, {});
        for(int i=0;i<n-1;i++){
            int u,v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        weights.clear();
        dfs(1, -1, n);
        sort(weights.begin(), weights.end());

        int m; cin >> m;
        vector<ll> f;
        // Pad with ones
        while((int)f.size() < n-1-m) f.push_back(1);
        for(int i=0;i < m;i++) {ll x; cin >> x; f.push_back(x);}
        sort(f.begin(), f.end());

        // shrink to size n-1 by merging largest
        while((int)f.size() > n-1){
            ll x = f.back(); f.pop_back();
            f.back() = (f.back() * x) % MOD;
        }

        ll ans = 0;
        for(int i=0;i<n-1;i++){
            ans = (ans + (weights[i] % MOD) * (f[i] % MOD)) % MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}

/*
TC: O(n log n + m log m) per test.
SC: O(n + m).
*/