#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s; // n
    // INPUT

    int ans = 0;
    for (int i = 0; i < (k + 1) / 2; i++) {
        vector<int> freq(26, 0);
        for (int j = 0; j < n / k; j++) {
            int idx1 = j * k + i;
            int idx2 = (j + 1) * k - i - 1;
            freq[s[idx1] - 'a']++;
            if (idx1 != idx2)
                freq[s[idx2] - 'a']++;
        } // n/k
        int mx = *max_element(freq.begin(), freq.end());   // 26
        int s = accumulate(freq.begin(), freq.end(), 0LL); // 26
        ans += s - mx;
    } // n + 26*k
    cout << ans << '\n';
}

// tc : O(n)
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