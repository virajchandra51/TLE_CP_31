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

        while (n % 2 == 0) // Remove powers of 2
            n /= 2;
        // log2(n)
        
        if (n > 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// tc - O(log2(n)) - O(log2(10^14)) = O(50)
// sc - O(1)