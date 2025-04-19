#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A >> B; // 20
        long long n = A.size(), m = B.size();
        long long lcs = 0;

        for (long long len = 1; len <= min(n, m); len++) // 20
        {
            for (long long i = 0; i + len <= n; i++) // 20
            {
                for (long long j = 0; j + len <= m; j++) // 20
                {
                    string extract_A = A.substr(i, len); // 20
                    string extract_B = B.substr(j, len); // 20
                    
                    if (extract_A == extract_B) // 20
                        lcs = max(lcs, len);
                }
            }
        }

        long long operations = n + m - 2 * lcs;
        cout << operations << endl;
    }
    return 0;
}

// tc = O(20^4) = O(160000) ~ O(10^5)
// sc = O(2*20)