#include <bits/stdc++.h>
using namespace std;

// 10. Equal Frequencies
// Time Complexity: O(C^2 + N log C), C = 26 ~~~> O(N)
// Memory Complexity: O(N)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		string s; cin >> s;

		// sorting frequency of each character
		vector<pair<int, char>> freq(26);
		for(int i = 0; i < 26; i++) freq[i].second = 'a'+i;
		for(int i = 0; i < n; i++) freq[s[i]-'a'].first++;
		sort(freq.rbegin(), freq.rend()); // maximum frequencies at top

		// k == number of characters used in the answer
		// finding the k which minimizes changes
		int best_k = 1, changes = n;
		for(int k = 1; k <= 26; k++) {
			if(n % k) continue;
			int unchanged = 0;
			for(int i = 0; i < k; i++) unchanged += min(freq[i].first, n/k);
			if(n - unchanged < changes) {
				best_k = k;
				changes = n - unchanged;
			}
		}

		// construct string
		map<char, int> mp; // keep count of how much of each character left to fill
		for(int i = 0; i < best_k; i++) mp[freq[i].second] = n/best_k;

		string ans(n, ' ');
		for(int i = 0; i < n; i++) { // fill the unchanged values
			if(mp[s[i]]) {
				ans[i] = s[i]; mp[s[i]]--;
			}
		}

		for(int i = 0; i < n; i++) { // fill the remaining values
			if(ans[i] != ' ') continue;
			while(!mp.empty() && (*mp.begin()).second == 0) mp.erase(mp.begin());
			auto ch = (*mp.begin()).first;
			ans[i] = ch;
			mp[ch]--;
		}

		cout << changes << "\n" << ans << "\n";
	}

	return 0;
}