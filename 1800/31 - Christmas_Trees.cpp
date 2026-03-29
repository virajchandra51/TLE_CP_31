#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> trees(n);
    for (int i = 0; i < n; ++i) cin >> trees[i];

    map<ll, ll> dist;
    queue<ll> q;

    for (ll x : trees) {
        dist[x] = 0;
        q.push(x);
    }

    vector<ll> ans;
    ll total = 0;

    while (!q.empty() && (int)ans.size() < m) {
        ll cur = q.front(); 
        q.pop();

        for (int d = -1; d <= 1; d += 2) {
            ll nx = cur + d;
            if (dist.find(nx) != dist.end()) continue;
            dist[nx] = dist[cur] + 1;
            q.push(nx);
            ans.push_back(nx);
            total += dist[nx];
            if ((int)ans.size() == m) break;
        }
    }

    cout << total << "\n";
    for (int i = 0; i < m; ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << "\n";
}

/*
TC: O(n + m)
SC: O(n + m)
*/