#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// Memory Complexity: O(n)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		string s; cin >> s;
		int n = s.size();
		int ans = 0;
		for(int d = 1; d <= n/2; d++){
			int cnt = 0;
			for(int i = 0; i < d; i++) {
				if(s[i] == '?' || s[i+d] == '?' || s[i] == s[i+d]) cnt++;
			}
			if(cnt == d) ans = max(ans, d);
			for(int j = 0; j < n - 2*d; j++) {
				if(s[j] == '?' || s[j+d] == '?' || s[j] == s[j+d]) cnt--;
				if(s[j+d] == '?' || s[j+2*d] == '?' || s[j+d] == s[j+2*d]) cnt++;
				if(cnt == d) ans = max(ans, d);
			}
		}

		cout << 2*ans << "\n";
	}

	return 0;
}