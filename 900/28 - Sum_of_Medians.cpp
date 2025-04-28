#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n * k);
        for (int i = 0; i < n * k; i++) // n*k
            cin >> v[i];

        long long pointer = n * k;

        long long sum = 0;
        while (k--) // k
        {
            pointer -= (n / 2 + 1);
            sum += v[pointer];
        }
        cout << sum << endl;
    }
    return 0;
}

// tc - O(n*k) = O(2*10^5)
// sc - O(n*k) = O(2*10^5)