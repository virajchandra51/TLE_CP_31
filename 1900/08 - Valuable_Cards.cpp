#include <iostream>
#include <vector>

using namespace std;

const int A = 1e6 + 1;
bool used[A];
bool divs[A];

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	vector<int> vecDivs;
	for (int d = 1; d * d <= x; d++) {
		if (x % d == 0) {
			divs[d] = true;
			vecDivs.push_back(d);
			if (d * d < x) {
			    vecDivs.push_back(x / d);
				divs[x / d] = true;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 1;
	used[1] = true;
	vector<int> cur{ 1 };
	for (int i = 0; i < n; i++) {
		if (!divs[a[i]])
			continue;
		vector<int> ncur;
		bool ok = true;
		for (int d : cur)
			if (1ll * d * a[i] <= x && divs[d * a[i]] && !used[d * a[i]]) {
				ncur.push_back(d * a[i]);
				used[d * a[i]] = true;
				if (d * a[i] == x)
					ok = false;
			}
		for (int d : ncur)
			cur.push_back(d);
		if (!ok) {
			ans++;
			for (int d : cur)
				used[d] = false;
			used[1] = true;
			used[a[i]] = true;
			cur = vector<int>{ 1, a[i] };
		}
	}
	for (int d : vecDivs) {
	    divs[d] = false;
	    used[d] = false;
	}
	cout << ans << '\n';
}

signed main() {
    int T;
    cin >> T;
    while (T--)
	    solve();
	return 0;
}

// Time Complexity : O(n * d(x)) where d(x)is the number of divisors of x
// Space Complexity : O(n + max-X)