#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 1e9 + 7;

int powm(int x, int n) {
    x %= M;
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;

    int p = powm(x * x, n / 2);
    if (n % 2)
        return p * x % M;
    else
        return p;
}

vector<vector<int>> adj;
vector<int> vis;
int sz;

void dfs(int x) {
    vis[x] = 1;
    sz++;
    for (auto &i : adj[x]) {
        if (!vis[i])
            dfs(i);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    adj.assign(n + 1, vector<int>(0));
    for (int i = 0; i < n - 1; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        if (x == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    } // n
    int ans = 0;
    vis.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            sz = 0;
            dfs(i);
            ans = (ans + powm(sz, k)) % M; // logk
        }
    } // n*logk
    ans = (powm(n, k) - ans + M) % M; // logk
    cout << ans << '\n';

    return 0;
}

// tc : O(n*logk)
// sc : O(n)