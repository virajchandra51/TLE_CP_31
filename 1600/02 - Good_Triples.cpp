#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Good Triples
// Note D = 10 (0-9, number of digits in decimal system)
// Time Complexity: O(D^3 + T*(log_10 N)) or about O(T)
// Memory Complexity: O(D) or about O(1)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<int> split(10, 0);
	for(int i = 0; i <= 9; i++) {
		for(int j = 0; j <= 9; j++) {
			for(int k = 0; k <= 9; k++) {
				if(i+j+k < 10) split[i+j+k]++;
			}
		}
	}

	int tc; cin >> tc;
	while(tc--) {
		string s; cin >> s;
		ll ans = 1;
		for(char x : s) {
			ans *= split[x - '0'];
		}
		cout << ans << "\n";
	}

	return 0;
}