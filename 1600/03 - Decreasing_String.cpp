#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		string s;
		cin >> s;
		ll n = s.size(), pos;
		cin >> pos;

		string stk;
		for(char &c : s) {
			while(!stk.empty() && stk.back() > c && pos > n) {
				stk.pop_back();
				pos -= n; n--;
			}
			stk.push_back(c);
		}

		while(pos > n) {
			stk.pop_back(); pos -= n; n--;
		}

		cout << stk[pos-1];
	}

	return 0;
}