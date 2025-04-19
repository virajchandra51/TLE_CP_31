#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long w, h;
        cin >> w >> h;
        long long area = INT_MIN;
        for (int i = 0; i < 4; i++) // 4
        {
            long long k;
            cin >> k;
            long long first, last;

            for (int j = 0; j < k; j++) // k
            {
                long long x;
                cin >> x;
                if (j == 0)
                    first = x;
                if (j == k - 1)
                    last = x;
            }

            long long base = last - first;
            long long height;
            if (i <= 1)
                height = h;
            else
                height = w;
            
            area = max(area, base * height);
        }
        cout << area << endl;
    }
    return 0;
}

// tc = O(k) = O(2*10^5)
// sc = O(1)