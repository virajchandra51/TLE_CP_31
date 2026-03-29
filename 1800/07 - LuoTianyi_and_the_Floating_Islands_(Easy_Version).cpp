#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
vector<vector<int>> g;
vector<int> parent, subtree_size;
long long total_dist = 0;
vector<int> dist;

const int MOD = 1e9 + 7;

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

long long modFraction(long long p, long long q) {
    return p % MOD * modpow(q % MOD, MOD - 2) % MOD;
}

void dfs(int u, int p, int d = 0) {
    parent[u] = p;
    subtree_size[u] = 1;
    total_dist += d;
    for (int v : g[u])
        if (v != p) {
            dfs(v, u, d + 1);
            subtree_size[u] += subtree_size[v];
        }
}

void calculate_dist(int u, int p) {
    for (int v : g[u])
        if (v != p) {
            dist[v] = dist[u] - subtree_size[v] + (n - subtree_size[v]);
            calculate_dist(v, u);
        }
}

signed main() {
    cin >> n >> k;
    g.assign(n + 1, {});
    parent.resize(n + 1);
    subtree_size.resize(n + 1);
    dist.resize(n + 1);
    for (int i = 0, u, v; i < n - 1; i++)
        cin >> u >> v, g[u].push_back(v), g[v].push_back(u);

    if(k & 1) {
        cout << 1 << "\n";
        return 0;
    }
    dfs(1, 0);
    dist[1] = total_dist;
    calculate_dist(1, 0);
    cout <<( modFraction(accumulate(dist.begin() + 1, dist.end(), 0LL), n * (n - 1)) + 1) % MOD << "\n";
}

// Time complexity: O(n)
// Space complexity: O(n)