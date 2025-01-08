#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, x;
        cin >> n >> k >> x;
        // inputs
        
        if (x != 1)
        {
            cout << "YES" << endl;
            cout << n << endl;
            for (int i = 1; i <= n; i++) // n
                cout << 1 << " ";
            cout << endl;
        }
        else
        {
            if (k == 1 || (k == 2 && n % 2 == 1))
                cout << "NO" << endl;
            else
            {
                cout << "YES" << endl;
                if (n % 2 == 0)
                {
                    cout << n / 2 << endl;
                    for (int i = 1; i <= n / 2; i++) // n
                        cout << 2 << " ";
                    cout << endl;
                }
                else
                {
                    cout << (n - 3) / 2 + 1 << endl;
                    for (int i = 1; i <= (n - 3) / 2; i++) // n
                        cout << 2 << " ";
                    cout << 3 << endl;
                }
            }
        }
    }
    return 0;
}

// tc - O(n) = O(100)
// sc - O(1)