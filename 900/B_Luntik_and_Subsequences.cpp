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
        for (long long i = 0; i < n; i++) //n
            cin >> a[i];

        long long count_of_ones = 0;
        long long count_of_zeros = 0;
        for (long long i = 0; i < n; i++) //n
        {
            if (a[i] == 1)
                count_of_ones++;
            else if(a[i] == 0)
                count_of_zeros++;
        }

        long long ways = pow(2, count_of_zeros) * count_of_ones;
        // log2(count_of_zeros)
        cout << ways << endl;
    }
    return 0;
}

// tc - O(n) = O(60)
// sc - O(n) = O(60)
