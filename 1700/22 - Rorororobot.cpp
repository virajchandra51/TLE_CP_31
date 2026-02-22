#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Time Complexity: O(n log n + q) with sparse table
// Memory Complexity: O(n log n) with sparse table

struct MaxOperation { template<typename T> T operator()(const T &a, const T &b) const { return max(a, b); } };
template <typename T, typename Operation = MaxOperation> class sparse_table {
private:
	vector<vector<T>> v;
	int N, K;
	Operation op;
	int log2_floor(int i) { return __builtin_clz(1) - __builtin_clz(i); }
public:
	sparse_table(vector<T> &a) {
		N = (int)a.size(), K = log2_floor(N);
		v = vector<vector<T>>(K+1);
		for(auto x : a) v[0].push_back(x);
		for(int i = 1; i <= K; i++) {
			for(int j = 0; j + (1 << i) <= N; j++) {
				v[i].push_back(op(v[i - 1][j], v[i - 1][j + (1 << (i - 1))]));
			}
		}
	}
	T get(int x) { return v[0][x]; }
	T query(int L, int R) {
		int i = log2_floor(R - L + 1);
		return op(v[i][L], v[i][R - (1 << i) + 1]);
	}
	void print_full() { for(int i = K; i >= 0; i--) { for(auto x : v[i]) { cout << x << " "; } cout << "\n"; } }
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<int> a(m);
	for(auto &x : a) cin >> x;

	sparse_table<int> sparse(a);

	int q; cin >> q;
	while(q--) {
		int xs, ys, xf, yf, k; cin >> xs >> ys >> xf >> yf >> k;
		bool ans = ((abs(xs-xf)%k == 0) && (abs(ys-yf)%k == 0));
		if(ys > yf) swap(ys, yf);
		int mx_allowed = (n/k)*k + (xs%k);
		if(mx_allowed > n) mx_allowed -= k;
		if(sparse.query(ys-1, yf-1) >= mx_allowed) ans = false;
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}