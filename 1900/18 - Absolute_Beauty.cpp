#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    ll beauty = 0;
    for (int i = 0; i < n; i++)
        beauty += abs(a[i] - b[i]);

    int i1 = 0, i2 = 0;

    for (int i = 1; i < n; i++) {
        if (max(a[i], b[i]) < max(a[i1], b[i1]))
            i1 = i;
        if (min(a[i], b[i]) > min(a[i2], b[i2]))
            i2 = i;
    }

    ll ans = beauty;

    if (i1 != i2) {
        ll cur = beauty;

        cur -= abs(a[i1] - b[i1]);
        cur -= abs(a[i2] - b[i2]);

        cur += abs(a[i1] - b[i2]);
        cur += abs(a[i2] - b[i1]);

        ans = max(ans, cur);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
// Time : O(n)
// Space : O(n)