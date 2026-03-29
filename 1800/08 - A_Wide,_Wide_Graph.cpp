#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

const int N = 1e5 + 228;

vector<int> G[N];

void dfs(int v, int par, int h, vector<int> &d) {
    d[v] = h;
    for (int i : G[v]) {
        if (i != par) {
            dfs(i, v, h + 1, d);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }

    vector<int> d1(n), d2(n);
    dfs(0, -1, 0, d1);
    int a = max_element(all(d1)) - d1.begin();
    dfs(a, -1, 0, d1);
    int b = max_element(all(d1)) - d1.begin();
    dfs(b, -1, 0, d2);
    for (int i = 0; i < n; ++i) {
        d2[i] = max(d2[i], d1[i]);
    }
    sort(all(d2));
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        while (ans < n && d2[ans] < i) {
            ++ans;
        }
        cout << min(n, ans + 1) << ' ';
    }
    cout << '\n';
}