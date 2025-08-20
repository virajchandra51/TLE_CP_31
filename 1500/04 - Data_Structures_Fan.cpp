#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) //O(n)
            cin >> i;
        //INPUT

        vector<int> dp(n + 1);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1] + 1;
            int j = i + a[i] + 1;
            if (j <= n) {
                dp[i] = min(dp[i], dp[j]);
            }
        }//O(n)
        cout << dp[0] << '\n';
    }

    return 0;
}

//tc -> O(n)
//sc -> O(n)