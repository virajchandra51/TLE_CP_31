#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r, b;
        cin >> n >> r >> b;
        string s;
        int length_of_red = r / (b + 1);
        int extra_red = r % (b + 1);
        for (int times = 1; times <= b + 1; times++) // b+1
        {
            for (int i = 0; i < length_of_red; i++) // r/b+1
                s += 'R';
            if (extra_red > 0)
            {
                s += 'R';
                extra_red--;
            }
            if (times != b + 1)
                s += 'B';
        }
        cout << s << endl;
    }
    return 0;
}

// tc = O(100)
// sc = O(100)