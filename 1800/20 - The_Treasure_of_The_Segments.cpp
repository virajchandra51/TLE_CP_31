#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    vector<int> L;
    vector<int> R;
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &[l, r] : v) {
        cin >> l >> r;
        L.push_back(l);
        R.push_back(r);
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    int ans = n - 1;
    for (auto [l, r] : v) {
        int left = lower_bound(R.begin(), R.end(), l) - R.begin();
        int right = max(0, n - (int)(upper_bound(L.begin(), L.end(), r) - L.begin()));
        ans = min(ans, left + right);
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}