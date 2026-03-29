#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int INF = 1e9;

void solve(){
	int n;
	scanf("%d", &n);
	vector<int> t(n);
	forn(i, n){
		scanf("%d", &t[i]);
		--t[i];
	}
	sort(t.begin(), t.end());
	vector<vector<int>> dp(n + 1, vector<int>(2 * n, INF));
	dp[0][0] = 0;
	forn(i, n + 1) forn(j, 2 * n - 1) if (dp[i][j] < INF){
		if (i < n) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(t[i] - j));
		dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
	}
	printf("%d\n", dp[n][2 * n - 1]);
}

int main() {
	int q;
	scanf("%d", &q);
	forn(_, q) solve();
}