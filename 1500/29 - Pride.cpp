#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i; // n
    // INPUT

    int g = a[0];
    int cnt = 0;
    for (auto i : a) {
        g = __gcd(g, i); // log(ai)
        if (i == 1)
            cnt++;
    } // nlog(ai)
    if (g > 1) {
        cout << "-1\n";
        return 0;
    }

    if (cnt) {
        cout << n - cnt << '\n';
        return 0;
    }

    int ans = 2 * n;
    for (int i = 0; i < n; i++) {
        int gc = a[i];
        for (int j = i + 1; j < n; j++) {
            gc = __gcd(gc, a[j]); // log(ai)
            if (gc == 1) {
                ans = min(ans, n - 1 + j - i);
                break;
            }
        }
    } // n*nlog(ai)

    cout << ans << '\n';

    return 0;
}

// tc : O(n^2*log(ai))
// sc : O(n)