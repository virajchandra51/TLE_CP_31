#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (n < 4 || n % 2 == 1) // 1
            cout << -1 << '\n';
        else
        {
            // Using a different formula for ceil and floor to avoid floating point operations
            // in C++20 (GCC 13-64) version 
            long long min_buses = (n + 5) / 6; // integer ceil of n/6
            long long max_buses = n / 4;       // integer floor of n/4
            cout << min_buses << " " << max_buses << '\n';
        }
    }
    return 0;
}

// tc - O(1)
// sc - O(1)