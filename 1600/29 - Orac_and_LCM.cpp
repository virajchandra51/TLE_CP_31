#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Time Complexity: O(A * log(log(A)) + N * pi(sqrt(A)) + pi(A))
// Memory Complexity: O(A + n * log(A))

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	// Fast Seive Template (No issue in using faster seive, just a template)
	const int NMAX = (int)(3*1e5);
	bitset<NMAX/2> bits;
	bits.set();
	int cnt = 1;
	vector<int> primes = {2};
	for (int i = 3; i / 2 < (int)bits.size(); i = 2 * bits._Find_next(i / 2) + 1) {
	    primes.push_back(i);
	    ++cnt;
	    for (auto j = (int64_t) i * i / 2; j < (int)bits.size(); j += i) bits[j] = 0;
	}
	
	int n; cin >> n;
	unordered_map<int, int> cnt_prime;
	unordered_map<int, vector<int>> cnt_pair_prime;
	for(int i = 0; i < n; i++) {
		// factor this num
		int x; cin >> x;
		for(auto p : primes) {
			if(p > sqrt(x)) break;
			if(x % p != 0) continue;
			int cnt = 0;
			while(x % p == 0) {
				cnt++;
				x /= p;
			}
			// this much count of this prime
			cnt_prime[p]++;
			cnt_pair_prime[p].push_back(cnt);
			sort(cnt_pair_prime[p].begin(), cnt_pair_prime[p].end());
			if(cnt_pair_prime[p].size() > 2) cnt_pair_prime[p].pop_back();
		}
		if(x > 1) {
			cnt_prime[x]++;
			cnt_pair_prime[x].push_back(1);
			sort(cnt_pair_prime[x].begin(), cnt_pair_prime[x].end());
			if(cnt_pair_prime[x].size() > 2) cnt_pair_prime[x].pop_back();
		}
	}

	ll ans = 1;
	for(auto p : primes) {
		if(cnt_prime[p] < n - 1) continue;
		int cnt = cnt_pair_prime[p][0];
		if(cnt_prime[p] == n) cnt = cnt_pair_prime[p][1];
		while(cnt--) ans *= p;

	}
	cout << ans << "\n";

	return 0;
}