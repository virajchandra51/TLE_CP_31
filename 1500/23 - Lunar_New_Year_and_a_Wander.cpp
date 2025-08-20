#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } // m
    // INPUT

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> vis(n + 1);
    vector<int> ans;

    pq.push(1);
    vis[1] = 1;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans.push_back(u);
        for (auto v : adj[u]) {
            if (!vis[v]) {
                pq.push(v); // logn
                vis[v] = 1;
            }
        }
    } // nlogn + m

    for (auto i : ans)
        cout << i << ' '; // n

    return 0;
}

// tc : O(nlogn + m)
// sc : O(n+m)