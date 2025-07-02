#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) { //O(n)
		cin >> a[i];
	}
	long long res = 0;
	vector<int> v; // a[i]<i
	for (int i = 0; i < n; i++) { //O(nlogn)
		if (a[i] >= i+1) {continue;}
		res += (long long)(lower_bound(v.begin(), v.end(), a[i]) - v.begin());
		v.push_back(i+1);
	}
	cout << res << '\n';
}
 
int main() {
	int t; cin >> t; 
    for (int i = 1; i <= t; i++) 
    solve();
    return 0;
}

// TC  O(nlogn)
// SC  O(n)