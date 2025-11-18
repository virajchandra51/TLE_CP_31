#include <bits/stdc++.h>
using namespace std;

// Partitioning the Array
// TC : O( n + sqrt(n) + (n + log(n)) * n^(1/3) )
// MC : O( n + n^(1/3) )

vector<int> divisors(int n) {
	vector<int> div;
	for(int i = 1; i <= sqrt(n); i++) {
		if(n % i) continue;
		div.push_back(i);
		if(n/i != i) div.push_back(n/i);
	}
	return div;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		vector<int> a(n);
		for(auto &x : a) cin >> x;
		
		auto div = divisors(n);
		int ans = 0;
		for(auto &k : div) {
			int m = 0;
			for(int i = k; i < n; i++) {
				m = gcd(m, abs(a[i] - a[i-k]));
			}
			if(m != 1) ans++;
		}

		cout << ans << "\n";
	}

	return 0;
}