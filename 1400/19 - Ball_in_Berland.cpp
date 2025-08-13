#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a,b,k;
	cin >> a >> b >> k;
	
	vector<int> count1(a), count2(b); // O(a + b) space
	
	for(int i = 0; i < k; i++) { // O(k) time
	    int temp;
	    cin >> temp;
	    count1[temp-1]++;
	}
	
	for(int i = 0; i < k; i++) { // O(k) time
	    int temp;
	    cin >> temp;
	    count2[temp-1]++;
	}

	long long ans = 1LL * k * (k-1)/2;
	
	for(long long x : count1) { // O(a) time
		ans -= x * (x-1)/2;
	}

	for(long long x : count2) { // O(b) time
		ans -= x * (x-1)/2;
	}

	cout << ans << '\n';
}

int main() {
    
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}

// TC: O(a + b + k);
// SC: O(a + b)