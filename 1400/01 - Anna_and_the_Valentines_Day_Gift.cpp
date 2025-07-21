#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int totalDigits = 0;
    int trailingZeroes[n]{};
    for (int i = 0; i < n; i++) // O(n)
    {
        while (arr[i] % 10 == 0) // O(log(a_i))
        {
            trailingZeroes[i]++;
            arr[i] /= 10;
            totalDigits++;
        }
        while (arr[i] > 0) // O(log(a_i))
        {
            totalDigits++;
            arr[i] /= 10;
        }
    }

    sort(trailingZeroes, trailingZeroes + n, greater<>()); // O(nlogn)

    for (int i = 0; i < n; i += 2) // O(n)
        totalDigits -= trailingZeroes[i];

    if (totalDigits > m)
        cout << "Sasha\n";
    else
        cout << "Anna\n";
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}