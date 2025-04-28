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
        long long count_of_3 = 0;
        long long count_of_2 = 0;

        while (n > 0 && n % 3 == 0) // log3(n)
        {
            count_of_3++;
            n /= 3;
        }

        while (n > 0 && n % 2 == 0) // log2(n)
        {
            count_of_2++;
            n /= 2;
        }

        if (n > 1 || count_of_2 > count_of_3)
            cout << -1 << endl;
        else
            cout << count_of_3 + (count_of_3 - count_of_2) << endl;
    }
    return 0;
}

// tc - O(log2(n)) = O(30)
// sc - O(1)