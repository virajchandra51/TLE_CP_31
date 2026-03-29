#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)9e18;

ll solve_rec(int i, int j, const vector<int>& t, vector<vector<ll>>& memo){
    if (j == 0) return 0;
    if (i == 0) return INF;
    ll &res = memo[i][j];
    if (res != -1) return res;
    res = solve_rec(i-1, j, t, memo); // skip at minute i
    res = min(res, solve_rec(i-1, j-1, t, memo) + llabs((ll)i - (ll)t[j]));
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; 
    cin >> q;
    while(q--){
        int n; cin >> n;
        vector<int> t(n+1);
        for (int i = 1; i <= n; ++i) cin >> t[i];
        sort(t.begin()+1, t.end());
        vector<vector<ll>> memo(2*n + 1, vector<ll>(n + 1, -1));
        cout << solve_rec(2*n, n, t, memo) << '\n';
    }
    return 0;
}

/*
Time Complexity (per test): O(n * 2n) = O(n^2)
Overall Time Complexity: O(q * n^2)
Space Complexity (per test): O(n * 2n) = O(n^2)  (memo table)
*/