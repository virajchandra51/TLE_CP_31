#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i < n) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1);
            if (j < m) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - 1);
            if (i < n && j < m && s[i] == t[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
    
    return 0;
}
// Time Complexity - O(nm)
// Space Complexity - O(nm)