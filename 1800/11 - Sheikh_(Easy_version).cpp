// 2025-07-12 16:58:40
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<ll> a(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        // prefix sums and prefix xors
        vector<ll> ps(n+1, 0), px(n+1, 0);
        for (int i = 1; i <= n; i++) {
            ps[i] = ps[i-1] + a[i];
            px[i] = px[i-1] ^ a[i];
        }

        // Since q = 1 and it's guaranteed L = 1, R = n
        int L = 1, R = n;
        // We still read the query but we know it's the whole array
        int tmpL, tmpR;
        cin >> tmpL >> tmpR;
        // Best answer trackers
        ll bestF = -1;
        int bestLen = n+1;
        int ansL = L, ansR = L;

        // We'll search over all possible l in [L..R]
        // For each l compute f(l, R) = sum(l,R) - xor(l,R)
        // Then binary search minimal r in [l..R] such that f(l,r) == f(l,R)
        for (int l = L; l <= R; l++) {
            // f(l, R)
            ll sumLR = ps[R] - ps[l-1];
            ll xorLR = px[R] ^ px[l-1];
            ll fLR = sumLR - xorLR;
            // If this cannot improve best, skip
            if (fLR < bestF) continue;

            // Binary search for minimal r in [l..R] with f(l,r) == fLR
            int low = l, high = R;
            while (low < high) {
                int mid = (low + high) >> 1;
                ll sumLM = ps[mid] - ps[l-1];
                ll xorLM = px[mid] ^ px[l-1];
                ll fLM = sumLM - xorLM;
                if (fLM < fLR) {
                    // need to extend right
                    low = mid + 1;
                } else {
                    // fLM >= fLR, but since fLM <= fLR always, fLM == fLR
                    high = mid;
                }
            }
            int r = low;
            int len = r - l + 1;
            // Update answer if better F, or same F but shorter length
            if (fLR > bestF || (fLR == bestF && len < bestLen)) {
                bestF = fLR;
                bestLen = len;
                ansL = l;
                ansR = r;
            }
        }

        // Output the found segment
        cout << ansL << " " << ansR << "\n";
    }

    return 0;
}