#include <bits/stdc++.h>

using namespace std;

int n, m;
long long dis[100][100];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    memset(dis, 0x3f, sizeof dis);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w, u--, v--;
        dis[u][v] = dis[v][u] = w;
    }
    for (int i = 0; i < n; i++) dis[i][i] = 0;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    if (dis[0][n - 1] > 1e18)
        cout << "inf", exit(0);
    int ord[100];
    iota(ord, ord + n, 0);
    sort(ord + 1, ord + n, [](int a, int b) {
        return dis[0][a] < dis[0][b];
    });
    string s(n, '0');
    vector<pair<string, int>> ans;
    for (int i = 0; i < n - 1; i++) {
        int u = ord[i], v = ord[i + 1];
        s[u] = '1';
        ans.emplace_back(s, dis[0][v] - dis[0][u]);
        if (v == n - 1) break;
    }
    cout << dis[0][n - 1] << ' ' << ans.size() << '\n';
    for (auto [s, t] : ans)
        cout << s << ' ' << t << '\n';
}

// TC : O(n^3)
// SC : O(n^2)