#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, a, b;
        cin >> n >> a >> b;
        // inputs

        if (a + b + 2 <= n || (a == b && a == n)) // 1
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

// tc - O(1)
// sc - O(1)