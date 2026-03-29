#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 200005;

vector<int> g[N];
ll a[N], sub[N], dp[N], ans[N];
int n;

void dfs1(int u, int p) {
    sub[u] = 1;
    dp[u] = 0;
    for (int v : g[u]) {
        if (v == p) continue;
        dfs1(v, u);
        sub[u] += sub[v];
        dp[u] += dp[v] + sub[v] * (a[u] ^ a[v]);
    }
}

void dfs2(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;
        ans[v] = ans[u] 
                 - sub[v] * (a[u] ^ a[v]) 
                 + (n - sub[v]) * (a[u] ^ a[v]);
        dfs2(v, u);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g[i].clear();
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1(1, 0);
    ans[1] = dp[1];
    dfs2(1, 0);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}

// Time Complexity: O(n) per test case
// Space Complexity: O(n)
 