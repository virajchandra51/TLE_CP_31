#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
const ll ninf = -1e15;
 
vector<int> nextGreater(vector<ll>& arr, int n) {
	stack<int> s;	
        vector<int> result(n, n);
	for (int i = 0; i < n; i++) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			result[s.top()] = i;	
			s.pop();
		}
		s.push(i);
	}
        return result;
}
 
vector<int> prevGreater(vector<ll>& arr, int n) {
	stack<int> s;	
        vector<int> result(n, -1);
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			result[s.top()] = i;	
			s.pop();
		}
		s.push(i);
	}
        return result;
}
 
ll query(vector<ll> &tree, int node, int ns, int ne, int qs, int qe) {
    if (qe < ns || qs > ne) return ninf;
    if (qs <= ns && ne <= qe) return tree[node];
 
    int mid = ns + (ne - ns) / 2;
    ll leftQuery = query(tree, 2 * node, ns, mid, qs, qe);
    ll rightQuery = query(tree, 2 * node + 1, mid + 1, ne, qs, qe);
    return max(leftQuery, rightQuery);
}
 
int main() {
   int t; 
   cin >> t;
   while (t--) {
        int n, _n;
        cin >> n;
        vector<ll> arr(n, 0);
        for (auto& a : arr)
            cin >> a;
        
        // Round off n to next power of 2
        _n = n;
        while (__builtin_popcount(_n) != 1) _n++;
 
 
        // Prefix sums
        vector<ll> prefixSum(n, 0), suffixSum(n, 0);
        prefixSum[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }
        suffixSum[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + arr[i];
        }
        
        // Two max-segtress, one on the prefix sums, one on the suffix sums
        vector<ll> prefixTree(2 * _n, ninf), suffixTree(2 * _n, ninf);
 
        for (int i = 0; i < n; i++) {
            prefixTree[_n + i] = prefixSum[i];
            suffixTree[_n + i] = suffixSum[i];
        }
 
        for (int i = _n - 1; i >= 1; i--) {
            prefixTree[i] = max(prefixTree[2 * i], prefixTree[2 * i + 1]);
            suffixTree[i] = max(suffixTree[2 * i], suffixTree[2 * i + 1]);
        }        
        vector<int> ng = nextGreater(arr, n); 
        vector<int> pg = prevGreater(arr, n); 
        bool flag = true;
 
        for (int i = 0; i < n; i++) {
            ll rightMax = query(prefixTree, 1, 0, _n - 1, i + 1, ng[i] - 1) - prefixSum[i];
            ll leftMax = query(suffixTree, 1, 0, _n - 1, pg[i] + 1, i - 1) - suffixSum[i];
            if (max(leftMax, rightMax) > 0) {
                flag = false;
                break;
            }
        }
        if (flag) 
            cout << "YES\n";
        else 
            cout << "NO\n";
   }
}