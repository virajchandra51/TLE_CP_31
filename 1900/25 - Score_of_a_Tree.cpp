#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

long long modpow(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return r;
}

vector<vector<int>> g;
long long sumd;

long long dfs(int u, int p) {
    long long mx = 1;
    for (int v : g[u]) {
        if (v == p) continue;
        mx = max(mx, 1 + dfs(v, u));
    }
    sumd = (sumd + mx) % MOD;
    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        g.assign(n + 1, {});
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        sumd = 0;
        dfs(1, 0);

        long long ans = modpow(2, n - 1) * sumd % MOD;
        cout << ans << "\n";
    }
    return 0;
}

/*
TC: O(n)
SC: O(n)
*/