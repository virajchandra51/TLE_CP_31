#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<string> g(n), w(n);
        for(int i = 0; i < n; i++)
            cin >> g[i] >> w[i];

        vector<vector<int>> adj(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i != j && (g[i] == g[j] || w[i] == w[j]))
                    adj[i][j] = 1;

        int N = 1 << n;
        vector<vector<int>> dp(N, vector<int>(n, 0));

        for(int mask = 1; mask < N; mask++){
            for(int last = 0; last < n; last++){
                if(!(mask & (1 << last))) continue;

                if(mask == (1 << last)){
                    dp[mask][last] = 1;
                    continue;
                }

                int prev_mask = mask ^ (1 << last);
                for(int prev = 0; prev < n; prev++){
                    if((prev_mask & (1 << prev)) && dp[prev_mask][prev] && adj[prev][last]){
                        dp[mask][last] = 1;
                        break;
                    }
                }
            }
        }

        int best = 0;
        for(int mask = 0; mask < N; mask++)
            for(int last = 0; last < n; last++)
                if(dp[mask][last])
                    best = max(best, __builtin_popcount(mask));

        cout << n - best << "\n";
    }
}
// Time: O(t * 2^n * n^2)
// Space: O(2^n * n)