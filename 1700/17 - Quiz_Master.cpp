#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(N * (log(N) + sqrt(max(Ai))))
// Memory Complexity : O(N)

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n, m; cin >> n >> m;
		vector<int> a(n);
		for(int &x : a) cin >> x;
		sort(a.begin(), a.end());

		vector<int> f(m+1, 0);
		int ans = INT_MAX, cnt = 0;
		auto inc = [&](int x) { if(x > m) return; if(!f[x]) cnt++; f[x]++; };
		auto dec = [&](int x) { if(x > m) return; f[x]--; if(!f[x]) cnt--; };

		for(int l = 0, r = -1; l < n; l++) {
			while(cnt < m && r++ < n-1) {
				for(int j = 1; j <= sqrt(a[r]); j++) {
					if(a[r] % j) continue;
					inc(j);
					if(a[r] / j != j) inc(a[r] / j);
				}
			}
			if(r > n-1) break;
			ans = min(ans, a[r]-a[l]);
			for(int j = 1; j <= sqrt(a[l]); j++) {
				if(a[l] % j) continue;
				dec(j);
				if(a[l] / j != j) dec(a[l] / j);
			}
		}

		cout << ((ans != INT_MAX) ? ans : -1) << "\n"; 
	}

	return 0;
}