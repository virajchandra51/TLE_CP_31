#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> factors[n + 1];
    for (int i = 1; i <= n; i++) // O(n)
    {
        for (int j = 1; j * j <= i; j++) // O(sqrt(n))
        {
            if (i % j == 0)
            {
                factors[i].push_back(j);
                if (i / j != j)
                {
                    factors[i].push_back(i / j);
                }
            }
        }
    }

    int dp[k + 1][n + 1]; // dp[i][j] = number of good arrays of length i ending in j

    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= k; i++) // O(k)
    {
        for (int j = 1; j <= n; j++) // O(n)
        {
            dp[i][j] = 0;
            for (auto x : factors[j]) // O(n ^ 1/3)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][x]) % MOD;
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        ans = (ans + dp[k][i]) % MOD;
    }

    cout << ans << endl;
}