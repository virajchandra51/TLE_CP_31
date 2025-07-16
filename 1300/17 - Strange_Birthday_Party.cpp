#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<int> k(n);
        for(int i = 0; i < n; i++) { //O(n)
            cin >> k[i];
        }
        vector<int> c(m);
        for(int i = 0; i < m; i++) { //O(m)
            cin >> c[i];
        }
        sort(k.begin(), k.end()); //O(n log n)
        int ans = 0;
        int p = 0;
        for(int i = n-1; i >= 0; i--) { //O(n)
            if(p<m && c[p]<=c[k[i]-1]){
                ans += c[p];
                p++;
            }
            else{
                ans += c[k[i]-1];
            }   
        }
        cout << ans << endl;
    }
}

// TC = O(nlogn+m)
// SC = O(n+m)