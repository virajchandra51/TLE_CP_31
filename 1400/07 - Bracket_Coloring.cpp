#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int bal[n]; // O(n) space
	if(s[0] == '(') {
		bal[0] = 1;
	}
	else{
		bal[0] = -1;
	}
	
	for(int i = 1; i < n; i++) { // O(n) time
		if(s[i] == ')') {
			bal[i] = bal[i-1] - 1;
		}
		else{
			bal[i] = bal[i-1] + 1;
		}
	}

	if(bal[n-1] != 0) {
		cout << -1 << endl;
		return;
	}

	if(*min_element(bal,bal+n) == 0) { //O(n) time
		cout << 1 << endl;
		for(int i = 0; i < n; i++) {
			cout << 1 << ' ';
		}
		cout << endl;
		return;
	}
	else if(*max_element(bal,bal+n) == 0) { //O(n) time
		cout << 1 << endl;
		for(int i = 0; i < n; i++) {
			cout << 1 << ' ';
		}
		cout << endl;
		return;
	}

	int ans[n];

	for(int i = 0; i < n; i++) { // O(n) time
		if(bal[i] > 0) {
			ans[i] = 1;
		}
		else if(bal[i] < 0) {
			ans[i] = 2;
		}
		else{
			if(bal[i-1] > 0) {
				ans[i] = 1;
			}
			else{
				ans[i] = 2;
			}
		}
	}

	cout << 2 << endl;
	for(int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}

int main () {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		solve();
	}
}

// TC: O(n)
// SC: O(n)