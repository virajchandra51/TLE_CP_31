#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1000005;

int nxt[MAXN][26];
int cnt[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> s(n);

    ll total_len = 0;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        total_len += s[i].size();
    }

    ll ans = 2LL * n * total_len;
    int nodes = 1;

    // insert reversed strings
    for (auto &str : s) {
        int node = 0;
        cnt[node]++;

        for (int i = str.size()-1; i >= 0; i--) {
            int c = str[i]-'a';

            if (!nxt[node][c])
                nxt[node][c] = nodes++;

            node = nxt[node][c];
            cnt[node]++;
        }
    }

    // process strings
    for (auto &str : s) {
        int node = 0;

        for (int i = 0; i < str.size(); i++) {
            int c = str[i]-'a';

            if (!nxt[node][c]) {
                break;
            }
            node = nxt[node][c];
            ans -= 2LL * cnt[node];
        }
    }

    cout << ans << "\n";
}
// TC : O(SA) where S is the number of strings and A is the size of the alphabet (26 in this case)
// SC : O(SA) for the trie and count arrays