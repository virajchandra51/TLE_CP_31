#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * m * k)
// Memory Complexity: O(n * m)

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n, m, k; cin >> n >> m >> k;
		int a[n][m];
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];

		int type[n][m];
		ll D = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				char x; cin >> x;
				if(x == '0') type[i][j] = 0, D += a[i][j];
				else type[i][j] = 1, D -= a[i][j];
			}
		}

		D = abs(D);
		if(D == 0) {
			cout << "YES\n"; continue;
		}

		int G = 0;
		// now have sliding windows matrix
		for(int i = 0; i <= n-k; i++) {
			int window = 0;
			for(int x = i; x < i+k; x++) {
				for(int y = 0; y < k; y++) {
					if(type[x][y] == 0) window++;
					else window--;
				}
			}
			G = gcd(G, abs(window));
			for(int y = 1; y <= m - k; y++) {
				for(int x = i; x < i + k; x++) {
					if(type[x][y-1] == 0) window--;
					else window++;
					if(type[x][y+k-1] == 0) window++;
					else window--;
				}
				G = gcd(G, abs(window));
			}
		}

		if(G != 0 && D % G == 0) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}