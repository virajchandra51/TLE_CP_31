#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <utility>
 
using namespace std;
 
using ll = long long;
 
#define int ll
#define all(a) a.begin(), a.end()

using namespace __gnu_pbds;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> order_set;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
const int MOD = 998244353;
// const int MOD = 1e9 + 7;
const int N = 5e5 + 5;
const int P = 107;
const int INF = 1e8;
const int LOG = 60;


void solved() {
    int n, m;
    cin >> n >> m;
    array<string, 2> a;
    for (int i = 0; i < 2; ++i) {
        cin >> a[i];
        a[i] = '!' + a[i];
    }
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i][j], max(dp[i][j - 1], dp[i - 1][j]) - 1);
            int inc = (a[0][i] == a[1][j]) ? 2 : -2;
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + inc);
            dp[i][j] = max(dp[i][j], inc);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // precalc();
    int t = 1;
    while (t--) {
        solved();
    }
    

    return 0;
}