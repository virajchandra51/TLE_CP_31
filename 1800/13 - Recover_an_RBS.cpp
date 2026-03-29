#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int opens = n / 2;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            opens--;
    }
    int last_open = -1, first_close = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?' && opens > 0)
        {
            last_open = i;
            s[i] = '(';
            opens--;
        }
        else if (s[i] == '?')
        {
            s[i] = ')';
            first_close = (first_close != -1) ? first_close : i;
        }
    }
    if (last_open == -1 || first_close == -1)
    {
        cout << "YES\n";
        return;
    }
    swap(s[last_open], s[first_close]);
    int balance = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            balance++;
        else
            balance--;
        if (balance < 0)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)