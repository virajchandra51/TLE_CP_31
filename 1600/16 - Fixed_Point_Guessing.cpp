#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N log N)
// Memory Complexity : O(N)

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		int l = 1, r = n;
		while(l < r) {
			int mid = (l+r)/2;
			cout << "? " << l << " " << mid << endl;
			int cnt = 0;
			for(int i = 0; i < (mid-l+1); i++) {
				int x; cin >> x;
				if(l <= x && x <= mid) cnt++;
			}

			if(cnt % 2) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}

		cout << "! " << l << endl; 
	}

	return 0;
}