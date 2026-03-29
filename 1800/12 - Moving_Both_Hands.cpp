#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int weight;
    bool dir;  // true = forward, false = backward
};

class Graph {
public:
    int n;
    vector<vector<Edge>> adj;
    vector<long long> dist;

    Graph(int nodes) : n(nodes) {
        adj.resize(n + 1);
        dist.assign(n + 1, INF);
    }

    void add_edge(int u, int v, int w) {
        adj[u].push_back({v, w, true});
        adj[v].push_back({u, w, false});
    }

    void dijkstra(int root) {
        dist[root] = 0;
        vector<bool> vis(n + 1, false);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, root});

        // Phase 1: only forward edges
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (vis[u]) continue;
            vis[u] = true;

            for (const auto& e : adj[u]) {
                if (e.dir && dist[e.to] > dist[u] + e.weight) {
                    dist[e.to] = dist[u] + e.weight;
                    pq.push({dist[e.to], e.to});
                }
            }
        }

        // Phase 2: allow backward edges
        fill(vis.begin(), vis.end(), false);
        pq = {};
        for (int i = 1; i <= n; ++i) {
            pq.push({dist[i], i});
        }

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (vis[u]) continue;
            vis[u] = true;

            for (const auto& e : adj[u]) {
                if (!e.dir && dist[e.to] > dist[u] + e.weight) {
                    dist[e.to] = dist[u] + e.weight;
                    pq.push({dist[e.to], e.to});
                }
            }
        }

        // Output distances from root to nodes 2...n
        for (int i = 2; i <= n; ++i) {
            if (dist[i] >= INF) cout << "-1 ";
            else cout << dist[i] << " ";
        }
        cout << '\n';
    }

private:
    const long long INF = 1e18;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }

    g.dijkstra(1);

    return 0;
}