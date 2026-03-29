#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll>a(n);
        ll s = 0, mx = 0;
        for(ll &x : a){ cin >> x; s += x; mx = max(mx, x); }
        if(mx > s - mx || (s & 1)) cout << "T\n";
        else cout << "HL\n";
    }
    return 0;
}

/*
Time Complexity:  O(t * n)
Space Complexity: O(n)
*/