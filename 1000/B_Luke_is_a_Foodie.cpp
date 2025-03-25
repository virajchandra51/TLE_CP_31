#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, x;
        cin >> n >> x;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) // n
            cin >> a[i];

        vector<pair<long long, long long> > segments(n);
        for (int i = 0; i < n; i++) // n
            segments[i] = {a[i] - x, a[i] + x};
        
        long long ans = 0;
        long long l = segments[0].first;
        long long r = segments[0].second;
        for (int i = 1; i < n; i++) // n
        {
            l = max(l, segments[i].first);
            r = min(r, segments[i].second);
            if (l > r)
            {
                ans++;
                l = segments[i].first;
                r = segments[i].second;
            }
        }
        cout << ans << endl;
    }
}

// tc = O(n) = O(2*10^5)
// sc = O(n) = O(2*10^5)