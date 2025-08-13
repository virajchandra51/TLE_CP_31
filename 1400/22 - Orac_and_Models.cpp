#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n + 1];
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    int dp[n + 1]; // O(n) space
    for(int i = 0; i <= n; i++) { // O(n)
        dp[i] = 1;
    }
    
    for(int i = 2; i <= n; i++) { //O(n)
        for(int j = 1; j * j <= i; j++) { //O(sqrt(n))
            if(i % j != 0) continue;
            if(a[j] < a[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            if(a[i/j] < a[i]) {
                dp[i] = max(dp[i], 1 + dp[i / j]);
            }
        }
    }
    
    cout << *max_element(dp,dp+n+1) << '\n';
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

// TC: O(n * rootn)
// SC: O(n)