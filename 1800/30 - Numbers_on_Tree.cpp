#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> children;
vector<int> c;
bool ok = true;

vector<int> dfs(int v){
    vector<int> res;
    for (int u : children[v]) {
        vector<int> sub = dfs(u);
        if (!ok) return {};
        res.insert(res.end(), sub.begin(), sub.end());
    }
    if (c[v] > (int)res.size()) { ok = false; return {}; }
    res.insert(res.begin() + c[v], v);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n)) return 0;
    children.assign(n, {});
    c.assign(n, 0);

    int root = -1;
    for (int i = 0; i < n; ++i) {
        int p, ci; cin >> p >> ci;
        c[i] = ci;
        if (p == 0) root = i;
        else children[p - 1].push_back(i);
    }

    vector<int> order = dfs(root);
    if (!ok) {
        cout << "NO\n";
        return 0;
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[order[i]] = i + 1;

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    // TC: O(n^2), SC: O(n^2)
    return 0;
}