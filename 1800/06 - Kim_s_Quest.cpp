#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

int n;
vector<int> a, odd, even;
int pairs[200005][2][2], dp[200005][2][2]; 

// pairs_dp[i][p1][p2] = no. of pairs (j,k) with j<k<=i and parity p1,p2
// dp[i][p1][p2] = no. of valid subsequences ending at index <= i, where p1,p2 are parities of last two chosen elements

int solve(int i, int p1, int p2) {
    if (i <= 1) return 0;
    int &res = dp[i][p1][p2];
    if (res != -1) return res;

    res = solve(i - 1, p1, p2); // skip current
    int p = a[i] & 1;
    if (p == p2) {
        int need = (2 - p1 - p2) % 2;
        res = (res + solve(i - 1, need, p1) + pairs[i - 1][need][p1]) % MOD;
    }
    return res;
}

signed main() {
    cin >> n;
    a.resize(n);
    odd.resize(n);
    even.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        odd[i]  = (i ? odd[i - 1] : 0) + (a[i] & 1);
        even[i] = i + 1 - odd[i];
        if(i != 0){
            for (int p1 = 0; p1 < 2; p1++)
                for (int p2 = 0; p2 < 2; p2++)
                    pairs[i][p1][p2] = (pairs[i - 1][p1][p2]) + ( ( (a[i] & 1) == p2) ? (p1 ? odd[i - 1] : even[i - 1]) : 0 );
        }
        
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int p1 = 0; p1 < 2; p1++)
        for (int p2 = 0; p2 < 2; p2++)
            ans = (ans + solve(n - 1, p1, p2)) % MOD;

    cout << ans % MOD;
}

/*
Time Complexity:  O(n * 2 * 2)
Space Complexity: O(n * 2 * 2)
*/