#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
vector<int> g[N];
int n, m;

bool solve() {
    for (int u = 1; u <= n; u++) {
        if (g[u].size() < 4) continue;

        for (int v : g[u]) {

            vector<int> par(n + 1, -1);
            queue<int> q;

            par[v] = u;
            q.push(v);

            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (int nxt : g[cur]) {
                    if (cur == v && nxt == u) continue;
                    if (par[nxt] != -1) continue;

                    par[nxt] = cur;
                    q.push(nxt);
                }
            }

            if (par[u] == -1) continue;

            vector<pair<int,int>> edges;
            vector<bool> in_cycle(n + 1, false);

            int cur = u;
            while (cur != v) {
                in_cycle[cur] = true;
                edges.push_back({cur, par[cur]});
                cur = par[cur];
            }
            in_cycle[v] = true;
            edges.push_back({u, v});

            vector<int> extra;
            for (int x : g[u])
                if (!in_cycle[x])
                    extra.push_back(x);

            if (extra.size() >= 2) {
                edges.push_back({u, extra[0]});
                edges.push_back({u, extra[1]});

                cout << "YES\n";
                cout << edges.size() << "\n";
                for (auto &e : edges)
                    cout << e.first << " " << e.second << "\n";
                return true;
            }
        }
    }

    cout << "NO\n";
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
            g[i].clear();

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        solve();
    }
}
// Time Complexity: O((n + m)^2) worst case per test
// Space Complexity: O(n + m)