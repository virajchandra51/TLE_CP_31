#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(time(NULL));

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	queue<int> q;
	map<int, int> d;
	for (int i = 0; i < n; ++i) {
		d[x[i]] = 0;
		q.push(x[i]);
	}
	long long ans = 0;
	vector<int> res;
	while (!q.empty()) {
		if (int(res.size()) == m) break;
		int cur = q.front();
		q.pop();
		if (d[cur] != 0) {
			ans += d[cur];
			res.push_back(cur);
		}
		if (!d.count(cur - 1)) {
			d[cur - 1] = d[cur] + 1;
			q.push(cur - 1);
		}
		if (!d.count(cur + 1)) {
			d[cur + 1] = d[cur] + 1;
			q.push(cur + 1);
		}
	}
	cout << ans << endl;
	shuffle(res.begin(), res.end(), rnd);
	for (auto it : res) cout << it << " ";
	cout << endl;
	
	return 0;
}