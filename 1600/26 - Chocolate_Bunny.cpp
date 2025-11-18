#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Memory complexity: O(n)

int main() {
	int n; cin >> n;
	vector<int> ans(n);

	stack<int> pos_left;
	unordered_set<int> vals_left;
	for(int i = 0; i < n; i++) {
		pos_left.push(i);
		vals_left.insert(i+1);
	}

	while(pos_left.size() >= 2) {
		int x = pos_left.top(); pos_left.pop();
		int y = pos_left.top(); pos_left.pop();

		cout << "? " << x+1 << " " << y+1 << endl;
		int a1; cin >> a1;
		cout << "? " << y+1 << " " << x+1 << endl;
		int a2; cin >> a2;

		vals_left.erase(max(a1, a2));
		if(a1 > a2) {
			ans[x] = a1;
			pos_left.push(y);
		}
		else {
			ans[y] = a2;
			pos_left.push(x);
		}
	}

	int v = *vals_left.begin();
	ans[pos_left.top()] = v;

	cout << "! ";
	for(auto x : ans) cout << x << " ";
	cout << endl;

	return 0;
}