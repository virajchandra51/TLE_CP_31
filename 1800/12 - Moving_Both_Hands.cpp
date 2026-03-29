#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

struct Edge {
    int to;
    ll w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // adjacency list for 2*N vertices
    vector<vector<Edge>> adj(2 * N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        // original edge (layer 0)
        adj[u].push_back({v, w});

        // reversed edge (layer 1)
        adj[v + N].push_back({u + N, w});
    }

    // 0-weight edges from (u,0) -> (u,1)
    for (int u = 1; u <= N; u++) {
        adj[u].push_back({u + N, 0});
    }

    // Dijkstra
    vector<ll> dist(2 * N + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    int start = 1; // (1,0)
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto &e : adj[u]) {
            if (dist[e.to] > d + e.w) {
                dist[e.to] = d + e.w;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    // Output min(dist[u], dist[u+N]) for each node
    for (int u = 2; u <= N; u++) {
        ll ans = min(dist[u], dist[u + N]);
        if (ans == INF) ans = -1; // unreachable
        cout << ans << " ";
    }
    cout << "\n";
}

// Time Complexity: O((N + M) log (N))
// Space Complexity: O(N + M)