#include <bits/stdc++.h>
using namespace std;

#define int uint64_t
#define SPEEDY ios::sync_with_stdio(false); cin.tie(nullptr);

int xor_0_n(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

int xor_range(int l, int r) {
    return xor_0_n(r) ^ xor_0_n(l - 1);
}

int32_t main() {
    SPEEDY

    int t;
    cin >> t;

    while (t--) {
        int l, r, i, k;
        cin >> l >> r >> i >> k;

        int pw = 1ULL << i;

        int mL = (l - k + pw - 1) / pw;
        int mR = (r - k) / pw;

        int highBits = 0, lowBits = 0;

        if (mL <= mR) {
            int cnt = mR - mL + 1;
            highBits = xor_range(mL, mR) << i;
            if (cnt & 1) lowBits = k;
        }

        int removed = highBits ^ lowBits;
        int ans = xor_range(l, r) ^ removed;

        cout << ans << "\n";
    }

    return 0;
}

/*
TC: O(1) per test case
SC: O(1)
*/