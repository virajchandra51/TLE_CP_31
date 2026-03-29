#include <bits/stdc++.h>

using namespace std;

#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		vector<vector<int>> cnt(200, vector<int>(n + 1));
		vector<vector<int>> pos(200);
		forn(i, n) {
			forn(j, 200) cnt[j][i + 1] = cnt[j][i];
			++cnt[a[i] - 1][i + 1];
			pos[a[i] - 1].push_back(i);
		}
		int ans = 0;
		forn(i, 200) {
			ans = max(ans, sz(pos[i]));
			forn(p, sz(pos[i]) / 2) {
				int l = pos[i][p] + 1, r = pos[i][sz(pos[i]) - p - 1] - 1;
				forn(el, 200) {
					int sum = cnt[el][r + 1] - cnt[el][l];
					ans = max(ans, (p + 1) * 2 + sum);
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}