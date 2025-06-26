#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        // input
        if (n % 3 == 0) // if n is divisible by 3
            cout << "Second" << endl;
        else
            cout << "First" << endl;
    }
    return 0;
}

// tc - O(1)
// sc - O(1)