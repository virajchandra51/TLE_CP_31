#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i; // n
    // INPUT

    vector<int> diff(n + 1, 0);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        diff[l]++;
        diff[r + 1]--;
    } // q
    for (int i = 1; i <= n; i++)
        diff[i] += diff[i - 1];       // n
    sort(diff.rbegin(), diff.rend()); // nlogn
    sort(a.rbegin(), a.rend());       // nlogn
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i] * diff[i]; // n
    cout << ans << '\n';

    return 0;
}

// tc : O(nlogn + q)
// sc : O(n)