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
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) // n
            cin >> a[i];

        sort(a.rbegin(), a.rend()); // nlogn

        for (auto ele : a) // n
            cout << ele << " ";
        cout << endl;
    }
    return 0;
}

// tc = O(nlogn) = O(100*log2(100)) = O(700)
// sc = O(n) = O(100)