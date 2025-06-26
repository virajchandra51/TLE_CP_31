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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) // n
            cin >> a[i];
        // inputs

        vector<long long> copy_a = a; // n
        sort(copy_a.begin(), copy_a.end()); // nlogn

        if (copy_a == a || k > 1) // n
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// tc - O(nlog2n) - O(100log2(100)) = 100*7 = 700
// sc - O(n)