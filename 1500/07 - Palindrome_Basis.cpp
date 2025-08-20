#include <bits/stdc++.h>

using namespace std;

bool check(int n) {
    string s = to_string(n);
    string str = s;
    reverse(s.begin(), s.end());
    return (s == str);
}//5

const int M = 1e9 + 7;
const int N = 4e4 + 5;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    vector<int> a;
    for (int i = 1; i < N; i++) {
        if (check(i)) //5
            a.push_back(i);
    }//5N
    int sz = a.size();

    vector<int> dp(N, 0);
    dp[0] = 1;

    for (int i = 0; i < sz; i++) {
        for (int x = 1; x < N; x++) {
            if (x - a[i] >= 0)
                dp[x] = (dp[x] + dp[x - a[i]]) % M;
        }
    }//sz*N

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }//t

    return 0;
}

//TC : O(sz*N + t) -> O(1e3*4e4) 
 