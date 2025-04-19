#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i]; //? O(N)

        vector<long long> maxSetBit(31, 0); //! f

        for (int i = 0; i < n; i++)
        {
            for (int bit = 30; bit >= 0; bit--)
            {
                if ((v[i] & (1 << bit))) //! a[i] & 2^j -> non zero only if jth position is set in a[i]
                {
                    maxSetBit[bit]++;
                    break;
                }
            }
        } //? O(N)

        long long ans = 0;
        for (int i = 0; i < 31; i++)
        {
            ans += (maxSetBit[i] * (maxSetBit[i] - 1)) / 2; //! f[i] * (f[i] - 1) / 2
        } //? O(1)

        cout << ans << "\n";
    }

    return 0;
}

//! Total time complexity : O(N)
//! Total space complexity : O(N)