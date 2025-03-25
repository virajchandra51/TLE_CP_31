#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) // n
            cin >> a[i];

        long long ans = INT_MAX;
        long long even_count = 0;
        for (long long i = 0; i < n; i++) // n
        {
            if (a[i] % 2 == 0)
                even_count++;
            if (a[i] % k == 0)
                ans = 0;
            ans = min(ans, (k - a[i] % k));
        }

        if (k == 4)
        {
            if (even_count >= 2)
                ans = min(ans, 0LL);
            else if (even_count == 1)
                ans = min(ans, 1LL);
            else if (even_count == 0)
                ans = min(ans, 2LL);
        }
        cout << ans << endl;
    }
    return 0;
}

// tc = O(n) = O(2*10^5)
// sc = O(n) = O(2*10^5)