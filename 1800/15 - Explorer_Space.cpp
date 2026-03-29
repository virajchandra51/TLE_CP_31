#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<long long>> right(n, vector<long long>(m - 1));
    vector<vector<long long>> down(n - 1, vector<long long>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m - 1; j++)
            cin >> right[i][j];
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            cin >> down[i][j];

    if (k % 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << -1 << " ";
            cout << "\n";
        }
        return 0;
    }

    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(k / 2 + 1, INF)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dp[i][j][0] = 0;

    for (int step = 1; step <= k / 2; step++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) dp[i][j][step] = min(dp[i][j][step], dp[i - 1][j][step - 1] + down[i - 1][j]);
                if (i < n - 1) dp[i][j][step] = min(dp[i][j][step], dp[i + 1][j][step - 1] + down[i][j]);
                if (j > 0) dp[i][j][step] = min(dp[i][j][step], dp[i][j - 1][step - 1] + right[i][j - 1]);
                if (j < m - 1) dp[i][j][step] = min(dp[i][j][step], dp[i][j + 1][step - 1] + right[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << 2 * dp[i][j][k / 2] << " ";
        cout << "\n";
    }
}
// Time Complexity - O(nmk)
// Space Complexity - O(nmk)