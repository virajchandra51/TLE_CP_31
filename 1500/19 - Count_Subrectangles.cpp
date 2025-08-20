#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto &i : a)
        cin >> i; // n
    for (auto &i : b)
        cin >> i; // m

    vector<int> fa(n + 1, 0), fb(m + 1, 0);
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            c++;
            fa[c]++;
        } else
            c = 0;
    } // n
    c = 0;
    for (int i = 0; i < m; i++) {
        if (b[i] == 1) {
            c++;
            fb[c]++;
        } else
            c = 0;
    } // m

    for (int i = n - 1; i > 0; i--) {
        fa[i] += fa[i + 1];
    } // n
    for (int i = m - 1; i > 0; i--) {
        fb[i] += fb[i + 1];
    } // m

    int ans = 0;
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            int j = k / i;
            if (i <= n && j <= m)
                ans += fa[i] * fb[j];
            if (i != j && j <= n && i <= m)
                ans += fa[j] * fb[i];
        }
    } // sqrt(k)

    cout << ans << '\n';

    return 0;
}

// tc: O(n + m + sqrt(k))
// sc: O(n + m)