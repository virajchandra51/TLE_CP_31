#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) // n
            cin >> a[i];
        
        int k = abs(a[0] - 1);
        for (int i = 1; i < n; i++) // n
        {
            k = gcd(k, abs(a[i] - (i + 1))); // log2(10^5)
        }
        cout << k << endl;
    }
    return 0;
}

// tc - O(nlogn) = O(10^5*20) = O(2*10^6)
// sc - O(n) = O(10^5)
