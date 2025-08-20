#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s; //n

    int cnt = 0, p = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a')
            cnt++;
        else if (s[i] == 'b') {
            p = p * (cnt + 1) % M;
            cnt = 0;
        }
    }//n
    p = p * (cnt + 1) % M;
    int ans = (p - 1 + M) % M;
    cout << ans << '\n';
    return 0;
}

//tc : O(s.size())
//sc : O(s.size())