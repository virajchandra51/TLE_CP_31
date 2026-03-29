#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long n, x, q, sum=0, maxi=0;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        sum+=x;
        maxi=max(maxi, (sum+i-1)/i);
    }
    cin >> q;
    while (q--) {
        cin >> x;
        if (x<maxi) {
            cout << -1 << "\n";
        } else {
            cout << (sum+x-1)/x << "\n";
        }
    }
    return 0;
}
// TC: O(n + q)
// SC : O(1)