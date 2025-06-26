#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (c % 2 == 1) // odd
        {
            if (b > a) // 1
                cout << "Second" << endl;
            else
                cout << "First" << endl;
        }
        else // even
        {
            if (a > b) // 1
                cout << "First" << endl;
            else
                cout << "Second" << endl;
        }
    }
    return 0;
}

// tc - O(1)
// sc - O(1)