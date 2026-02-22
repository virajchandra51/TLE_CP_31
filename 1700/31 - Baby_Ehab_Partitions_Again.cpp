#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Time Complexity: O(N^2 * A_i)
// Memory Complexity: O(N * A_i)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v) cin >> x;

	int sum = accumulate(v.begin(), v.end(), 0);
	if(sum % 2) {
		cout << 0;
		return 0;
	} 
	vector<bool> dp(sum/2 + 1, false); dp[0] = true;
	for(auto &x : v) {
		for(int i = sum/2; i >= x; i--) {
			dp[i] = dp[i] | dp[i - x];
		}
	}
	if(!dp[sum/2]) {
		cout << 0;
		return 0;
	}

	cout << "1\n";
	int div = 1;
	while(true) {
		for(int i = 0; i < n; i++) {
			if((v[i] / div) % 2) {
				cout << i + 1;
				return 0;
			}
		}
		div *= 2;
	}

	return 0;
}