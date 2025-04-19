#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;

        long long ans = INT_MAX;
        for (int addition = 0; addition < 32; addition++) // log2(a)
        {
            long long operations = addition;
            long long new_b = b + addition;
            if (new_b == 1) // corner
                continue;
            long long copy_a = a;
            while (copy_a > 0) // log2(a)
            {
                copy_a /= new_b;
                operations++;
            }
            ans = min(ans, operations);
        }
        cout << ans << endl;
    }
}

// tc = O(log2(a)^2)
// sc = O(1)