#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 2e3 + 5;
ll mem[MAX][MAX], a[MAX];

ll dp(int l, int r) {
    if(mem[l][r] != -1)
        return mem[l][r];
    if(l == r)
        return 0;
    return mem[l][r] = a[r] - a[l] + min(dp(l + 1, r), dp(l, r - 1));
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    memset(mem, -1, sizeof mem);

    cout << dp(0, n - 1) << '\n';
}
// Time complexity - O(n^2)
// Space complexity - O(n^2)