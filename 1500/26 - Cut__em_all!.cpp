#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> sz;

void dfs(int u, int par) {
    sz[u] = 1;
    for (auto &v : adj[u]) {
        if (v == par)
            continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    adj.assign(n + 1, vector<int>(0));
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } // n
    // INPUT

    if (n % 2) {
        cout << "-1\n";
        return 0;
    }

    sz.assign(n + 1, 0);
    dfs(1, -1); // n

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (sz[i] % 2 == 0)
            ans++;
    } // n
    cout << ans << '\n';

    return 0;
}

// tc : O(n)
// sc : O(n)