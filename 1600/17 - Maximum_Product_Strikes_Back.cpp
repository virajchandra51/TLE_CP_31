#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Memory Complexity : O(n)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tt; cin >> tt;
	while(tt--) {
		int n; cin >> n;
		vector<int> a(n);
		for(auto &x : a) cin >> x;
		
		int best = 0, bestl = n, bestr = 0; 
		int l = 0;
		while(l < n) {
			if(a[l] == 0) { l++; continue; }

			// find r-point
			int r = l-1, tc = 0, neg = 1;
			while(r+1 < n && a[r+1] != 0) {
				r++;
				if(abs(a[r]) == 2) tc++;
				if(a[r] < 0) neg *= -1;
			}

			if(neg == 1) { // product is +ve
				if(tc > best) bestl = l, bestr = (n-1)-r, best = tc;
				l = r + 1;
				continue;
			}

			// neg == -1, so try moving left and right pointer
			int ntc = tc, nl = l-1;
			do {
				nl++; ntc -= (abs(a[nl]) == 2);
			} while(a[nl] > 0);

			if(ntc > best) bestl = nl+1, bestr = (n-1)-r, best = ntc;

			// right pointer now
			int nr = r+1; ntc = tc;
			do {
				nr--; ntc -= (abs(a[nr]) == 2);
			} while(a[nr] > 0);

			if(ntc > best) bestl = l, bestr = n-nr, best = ntc;

			l = r + 1;
		}

		cout << bestl << " " << bestr << "\n";
	}

	return 0;
}