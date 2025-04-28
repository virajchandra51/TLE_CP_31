#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) // n
            cin >> a[i];
        // inputs
        if (n % 2 == 0) // even
        {
            cout << 2 << endl;
            cout << 1 << " " << n << endl;
            cout << 1 << " " << n << endl;
        }
        else // odd
        {
            cout << 4 << endl;
            cout << 1 << " " << n - 1 << endl;
            cout << 1 << " " << n - 1 << endl;
            cout << n - 1 << " " << n << endl;
            cout << n - 1 << " " << n << endl;
        }
    }
    return 0;
}

// tc - O(n) = O(100)
// sc - O(n) = O(100)
