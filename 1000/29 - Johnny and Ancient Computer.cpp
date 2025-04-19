#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long ra = a;
        long long rb = b;
        while (ra % 2 == 0) // log2(a)
            ra /= 2;
        while (rb % 2 == 0) // log2(b)
            rb /= 2;

        if (ra != rb)
            cout << -1 << endl;
        else
        {
            a /= ra;
            b /= rb;
            a = log2(a); // x
            b = log2(b); // y
            long long ans = ceil(abs(a - b) / 3.0);
            cout << ans << endl;
        }
    }
    return 0;
}

// tc = O(log2(10^18)) = O(60)
// sc = O(1)