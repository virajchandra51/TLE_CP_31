#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    vector<vector<pair<int, int>>> g(n + 1);
    vector<int> horse(n + 1);
    for (int i = 0, x; i < h; i++)
    {
        cin >> x;
        horse[x] = 1;
    }
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    auto minimum_time = [&](int s)
    {
        vector<vector<int>> d(n + 1, vector<int>(2, INF));
        d[s][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {s, 0}});
        while (!pq.empty())
        {
            auto [du, st] = pq.top();
            pq.pop();
            auto [u, hb] = st;
            if (du != d[u][hb])
                continue;
            if (!hb && horse[u] && du < d[u][1])
            {
                d[u][1] = du;
                pq.push({du, {u, 1}});
            }
            for (auto [v, w] : g[u])
            {
                int nd = du + (hb ? w / 2 : w);
                if (nd < d[v][hb])
                {
                    d[v][hb] = nd;
                    pq.push({nd, {v, hb}});
                }
            }
        }
        vector<int> res(n + 1);
        for (int i = 1; i <= n; i++)
            res[i] = min(d[i][0], d[i][1]);
        return res;
    };

    auto a = minimum_time(1), b = minimum_time(n);
    int ans = 1e18;
    for (int i = 1; i <= n; i++)
        ans = min(ans, (int)max(a[i], b[i]));
    cout << (ans == 1e18 ? -1 : ans) << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
// Time Complexity - O((n+m)logn)
// Space Complexity - O(n+m)