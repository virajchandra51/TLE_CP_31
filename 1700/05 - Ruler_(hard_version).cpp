#include <bits/stdc++.h>
using namespace std;

int check(int a, int b) {
	if(a > b) swap(a, b);
	cout << "? " << a << " " << b << endl;
	int x; cin >> x;
	if(x == a*b) return 0;
	else if(x == a*(b+1)) return 1;
	else return 2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int l = 1, r = 1000, best = r;
		while(l <= r) {
			int mid1 = l + (r-l)/3, mid2 = r - (r-l)/3;
			int x = check(mid1, mid2);
			if(x == 0) {
				l = mid2 + 1;
			}
			else if(x == 1) {
				best = min(best, mid2);
				l = mid1 + 1;
				r = mid2 - 1;
			}
			else {
				best = min(best, mid1);
				r = mid1 - 1;
			}
		}

		cout << "! " << best << endl;
	}

	return 0;
}