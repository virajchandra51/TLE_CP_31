#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> x(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> x[i];

        vector<int> suf(n + 2, 0);
        suf[n] = x[n];
        for (int i = n - 1; i >= 1; i--) {
            suf[i] = suf[i + 1] + x[i];
        } //n

        int ans = INT64_MAX;
        for (int i = 0; i <= n; i++) {
            int c = x[i] * (a + b) + (suf[i + 1] - (n - i) * x[i]) * b;
            ans = min(ans, c);
        } //n

        cout << ans << '\n';
    }

    return 0;
}

//tc -> O(n)
//sc -> O(n)