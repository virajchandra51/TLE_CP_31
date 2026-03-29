#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 9e18;

struct Edge {
    ll to, w;
};

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> speed(n + 1);
    for (ll i = 1; i <= n; i++) cin >> speed[i];

    vector<vector<ll>> dist(n + 1, vector<ll>(1001, INF));
    vector<vector<bool>> visited(n + 1, vector<bool>(1001, false));

    set<pair<ll, pair<ll, ll>>> pq; // {time, {node, current_speed}}
    dist[1][speed[1]] = 0;
    pq.insert({0, {1, speed[1]}});

    while (!pq.empty()) {
        auto [time, state] = *pq.begin();
        pq.erase(pq.begin());
        auto [u, spd] = state;

        if (visited[u][spd]) continue;
        visited[u][spd] = true;

        for (auto [v, w] : adj[u]) {
            ll new_spd = min(spd, speed[v]);
            ll new_time = time + w * spd;
            if (new_time < dist[v][new_spd]) {
                dist[v][new_spd] = new_time;
                pq.insert({new_time, {v, new_spd}});
            }
        }
    }

    ll ans = *min_element(dist[n].begin(), dist[n].end());
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
// Time complexity - O(max_slowness * (n + m) * log(n * max_slowness))
// Space complexity - O(max_slowness*n+m)