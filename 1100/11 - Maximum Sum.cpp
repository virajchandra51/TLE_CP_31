#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    int t = 1;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll>v(n);//N
        for (auto &it : v)cin >> it;//n
        sort(v.begin(), v.end());//nlogn
        vector<ll>pre(n);//N
        pre[0] = v[0];
        for (int i = 1; i < n; i++) {//n
            pre[i] = v[i] + pre[i - 1];
        }
        ll ans = 0;
        for (int first = 0; first <= k; first++) {//k
            int second=k-first;
            int left=2*first;
            int right=n-second-1;
            ll sum=pre[right]-(left==0 ? 0 : pre[left-1]);
            ans=max(ans,sum);
        }
        cout<<ans<<endl;
        // T.C :- O(nlogn)
        // S.C :- O(n)
    }
}