#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        k--; //! important

        if (n % 2 == 0) //? no collisions
        {
            int ans = k % n;
            cout << (k % n) + 1 << "\n";
        }
        else
        {
            int val = n / 2; //! 1 extra step for every n/2 steps

            cout << ((k + (k / val)) % n) + 1 << "\n";
        }
    }

    return 0;
}

//! Total time complexity : O(t)
//! Total space complexity : O(t)