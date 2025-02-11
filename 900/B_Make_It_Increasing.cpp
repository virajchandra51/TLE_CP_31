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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) // n
            cin >> a[i];

        long long ans = 0;
        for (int i = n - 2; i >= 0; i--) // n
        {
            while (a[i] >= a[i + 1]) // 31
            {
                ans++;
                a[i] /= 2;
                if (a[i] == 0)
                    break;
            }
            if (a[i] == 0 && a[i + 1] == 0)
            {
                ans = -1;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

// tc - O(nlog2(2*10^9)) = O(30*31) = O(930) ~ 10^3 
// sc - O(n) = O(30)