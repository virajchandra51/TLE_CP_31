#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    } // n
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } // n

    vector<int> vec;
    int val = 0;
    for (int i = 1; i <= n; i++) {
        val += w[i];
        int sz = adj[i].size();
        for (int j = 0; j < sz - 1; j++) {
            vec.push_back(w[i]); // n-2
        }
    } // n
    sort(vec.rbegin(), vec.rend()); // nlogn

    cout << val << ' ';
    for (auto i : vec) {
        val += i;
        cout << val << ' ';
    } // n
    cout << '\n';
}

// tc : O(nlogn)
// sc : O(n)

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}