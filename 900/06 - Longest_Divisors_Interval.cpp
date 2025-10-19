#include <bits/stdc++.h>
using namespace std;

// that means all the numbers from 1 to i-1 divide N
// I can take LCM of all numbers from 1 to i-1

int main()
{
    // long long a = 1;
    // for (long long i = 2; i <= 50; i++)
    // {
    //     a = lcm(a, i);
    // }
    // cout << a << endl;

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        // taking input

        int i = 1;
        while (n % i == 0) // O(60)
            i++;
        cout << i - 1 << endl;
    }
    return 0;
}

// tc - O(60) ~ O(log2(n))
// sc - O(1)