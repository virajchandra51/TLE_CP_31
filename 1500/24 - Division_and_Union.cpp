#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a[i] = {l, r, i};
    } // n

    sort(a.begin(), a.end()); // nlogn

    vector<int> ans(n, 2);
    int mx = a[0][1];
    bool f = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][0] > mx) {
            f = 1;
            break;
        }
        ans[a[i][2]] = 1;
        mx = max(mx, a[i][1]);
    } // n

    if (!f)
        cout << "-1\n";
    else {
        for (auto i : ans)
            cout << i << ' '; // n
        cout << '\n';
    }
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