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
        vector<long long> v(n);
        for (long long i = 0; i < n; i++) // n
            cin >> v[i];

        long long answer = v[n - 1] - v[0];

        for (int i = 1; i < n; i++) // n
            answer = max(answer, v[i] - v[0]);
        for (int i = 0; i < n - 1; i++) // n
            answer = max(answer, v[n - 1] - v[i]);
        for (int i = 0; i < n - 1; i++) // m
            answer = max(answer, v[i] - v[i + 1]);

        cout << answer << endl;
    }
    return 0;
}

// tc - O(n) = O(2000)
// sc - O(n) = O(2000)
