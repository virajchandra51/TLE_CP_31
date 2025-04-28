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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) // n
            cin >> a[i];
        // inputs

        int flag = 0;
        for (int i = 0; i < n; i++) // n
        {
            for (int j = i + 1; j < n; j++) // n
            {
                if (__gcd(a[i], a[j]) <= 2) // log2(min(a[i], a[j]))
                {
                    flag = 1;
                }
            }
        }

        // (10^4 * log2(10^6)) = 10^4 * 20 = 2 * 10^5

        if (flag == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}

// tc - O(n^2 * log2(min(a[i], a[j]))) = O(10^4 * 20) = O(2 * 10^5)
// sc - O(n) = O(100)