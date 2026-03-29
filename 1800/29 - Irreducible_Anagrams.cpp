// Problem: B. Irreducible Anagrams
// Contest: Codeforces - Codeforces Round 616 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1290/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vpll;
typedef map<ll, ll> mll;
typedef map<char, ll> mcl;
typedef unordered_map<ll, ll> umll;
typedef unordered_map<char, ll> umcl;
typedef set<ll> sll;
typedef pair<ll, ll> pll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
typedef tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> pbds;

#define Jay ios_base::sync_with_stdio(false);
#define Shree cin.tie(NULL);
#define Ram cout.tie(NULL);
#define endl '\n'
#define inarr(a,n) for(ll i=0;i<n;i++) cin>>a[i];
#define outarr(a,n) for(ll i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v) (ll)(v.size())
#define fl(i, n) for(ll i=0; i<n; i++)
#define f(i, x, n) for(ll i=x; i<n; i++)
#define rf(i, n) for(ll i=n-1; i>=0; i--)
#define RR return;
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define pf push_front
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define lcm(x, y) (x * y) / __gcd(x, y)
#define setbits(x) __builtin_popcountll(x)

const ll inf=LLONG_MAX;
const ll ninf=LLONG_MIN;
ll is_sqr(ll x){ll sr=sqrt(x); return (sr*sr==x);}
ll fastprime(ll a){if(a != 2 && (a % 2 == 0 || a < 2)) return 0;  for(int i = 3; i * i <= a; i += 2) if(a % i == 0) return 0; return 1;}
ll count_digits(ll n){ if(n==0) return 1; ll digits = 0; while(n){digits++;n/=10;} return digits;}
ll count_bits(ll n){ if(n==0) return 1; ll c=0; while(n){c++; n>>=1;} return c;}
ll digit_sum(ll n){ll sum = 0;while(n){sum += n % 10;n/=10;}return sum;}

// START OF MAIN CODE 

// Credits to HealthyUG for the inspiration.
// Segment Tree with Poll Updates and Range Queries
// Supports multiple Segment Trees with just a change in the Node and Update
// Very few changes required everytime

template<typename Node, typename Update>
class SegTree {
		public:
		vector<Node> tree;
		vector<ll> arr; // type may change
		ll n;
		ll s;
		SegTree(ll a_len, vector<ll> &a) { // change if type updated
				arr = a;
				n = a_len;
				s = 1;
				while(s < 2 * n){
						s = s << 1;
				}
				tree.resize(s); fill(all(tree), Node());
				build(0, n - 1, 1);
		}
		void build(ll start, ll end, ll index)  // Never change this
		{
				if (start == end)        {
						tree[index] = Node(arr[start]);
						return;
				}
				ll mid = (start + end) / 2;
				build(start, mid, 2 * index);
				build(mid + 1, end, 2 * index + 1);
				tree[index].merge(tree[2 * index], tree[2 * index + 1]);
		}
		void update(ll start, ll end, ll index, ll query_index, Update &u)  // Never Change this
		{
				if (start == end) {
						u.apply(tree[index]);
						return;
				}
				ll mid = (start + end) / 2;
				if (mid >= query_index)
						update(start, mid, 2 * index, query_index, u);
				else
						update(mid + 1, end, 2 * index + 1, query_index, u);
				tree[index].merge(tree[2 * index], tree[2 * index + 1]);
		}
		Node query(ll start, ll end, ll index, ll left, ll right) { // Never change this
				if (start > right || end < left)
						return Node();
				if (start >= left && end <= right)
						return tree[index];
				ll mid = (start + end) / 2;
				Node l, r, ans;
				l = query(start, mid, 2 * index, left, right);
				r = query(mid + 1, end, 2 * index + 1, left, right);
				ans.merge(l, r);
				return ans;
		}
		void make_update(ll index, ll val) {  // pass in as many parameters as required
				Update new_update = Update(val); // may change
				update(0, n - 1, 1, index, new_update);
		}
		Node make_query(ll left, ll right) {
				return query(0, n - 1, 1, left, right);
		}
};

class Node1 {
		public:
		vll val; // may change
		ll f;
		Node1() { // Identity element
			val = vll (26,0);  // may change
			f=0;
		}
		Node1(ll p1) {  // Actual Node
			val = vll (26,0); // may change
			val[p1]=1;
			f=1;
		}
		void merge(Node1 &l, Node1 &r) { // Merge two child nodes
			fl(i,26) val[i]=l.val[i]+r.val[i]; // may change
			fl(i,26) if(val[i] != 0) f++; 
		}
};

class Update1 {
		public:
		vll val; // may change
		Update1(ll p1) { // Actual Update
			 // may change
		}
		void apply(Node1 &a) { // apply update to given node
				a.val = val; // may change
		}
};


void solve(){
	string s;
	cin >> s;
	ll q;
	cin >> q;

	ll n=sz(s);
	vll v;
	fl(i,n) v.pb(s[i]-'a');

	SegTree<Node1,Update1> seg(n,v);

	ll l,r;
	fl(i,q){
		cin >>l >>r;
		--l,--r;
		
		if(l==r){yes continue;}
		
		ll f=seg.make_query(l,r).f;
		
		if(f==1) no
		else if(f>2) yes
		else{
			if(s[l]==s[r]) no
			else yes
		}
	}
}

int main(){
	Jay Shree Ram
	int t;
	t=1;
	//cin >> t;
	while(t--) solve();
	return 0;
}