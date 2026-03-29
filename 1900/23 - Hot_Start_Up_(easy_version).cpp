#include <bits/stdc++.h>
using namespace std;

const long long INF = 4e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int n,k;
        cin >> n >> k;

        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];

        vector<long long> cold(k+1), hot(k+1);
        for(int i=1;i<=k;i++) cin>>cold[i];
        for(int i=1;i<=k;i++) cin>>hot[i];

        vector<vector<long long>> dp(n+1, vector<long long>(k+1, INF));

        dp[1][0] = cold[a[1]];

        for(int i=2;i<=n;i++){
            int x = a[i];

            for(int j=0;j<=k;j++){
                if(dp[i-1][j]==INF) continue;

                long long cost1 = (a[i]==a[i-1] ? hot[x] : cold[x]);
                dp[i][j] = min(dp[i][j], dp[i-1][j] + cost1);

                long long cost2 = (j==x ? hot[x] : cold[x]);
                dp[i][a[i-1]] = min(dp[i][a[i-1]], dp[i-1][j] + cost2);
            }
        }

        cout << *min_element(dp[n].begin(), dp[n].end()) << "\n";
    }
}

// Time Complexity: O(nk)
// Space Complexity: O(nk)