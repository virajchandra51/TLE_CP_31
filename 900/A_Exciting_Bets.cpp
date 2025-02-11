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
        if (b > a)
            swap(a, b); // 1

        if (a == b)
            cout << 0 << " " << 0 << endl; // 1
        else
        {
            long long gcd = a - b;
            long long moves = min(b % gcd, gcd - b % gcd); // 1
            cout << gcd << " " << moves << endl;
        }
    }
    return 0;
}

// tc - O(1)
// sc - O(1)
