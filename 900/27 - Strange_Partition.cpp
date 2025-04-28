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
        long long min = 0, max = 0;
        for (int i = 0; i < n; i++) // n
            cin >> a[i];
        
        for (int i = 0; i < n; i++) // n
        {
            max += ceil(a[i] * 1.0 / x);
            min += a[i];
        }

        min = ceil(min * 1.0 / x);
        cout << min << " " << max << endl;
    }
    return 0;
}

// tc - O(n) = O(10^5)
// sc - O(n) = O(10^5)