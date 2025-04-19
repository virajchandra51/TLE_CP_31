#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        char c;
        cin >> n >> c;

        string s;
        cin >> s;

        //! 0 operations
        bool check0 = true;

        for (int i = 0; i < n; i++)
        {
            if (s[i] != c)
            {
                check0 = false;
                break;
            }
        } //? O(n)

        if (check0)
        {
            cout << "0\n";
            continue;
        }

        //! 1 operations
        int val1 = -1;
        for (long long i = 2; i <= n; i++)
        {
            bool isPoss = true;
            for (long long j = i; j <= n; j += i)
            {
                if (s[j - 1] != c)
                {
                    isPoss = false;
                    break;
                }
            }

            if (isPoss)
            {
                val1 = i;
                break;
            }
        } //? O(n log n)

        if (val1 != -1)
        {
            cout << "1\n";
            cout << val1 << "\n";
            continue;
        }

        cout << "2\n";
        cout << n - 1 << " " << n << "\n";
    }

    return 0;
}

//! Total time complexity : O(n log n)
//! Total space complexity : O(n)