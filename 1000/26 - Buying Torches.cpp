#include <bits/stdc++.h>
using namespace std;

long long ceil_division(long long a, long long b) { return (a + b - 1) / b; }

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y, k;
        cin >> x >> y >> k;

        long long sticks_gained_per_trade = x - 1; // if we give 1 stick and get x back, we gain x-1 sticks

        // 1 torch = 1 stick + 1 coal
        long long sticks_needed = k * y + k - 1;

        long long trades = 0;
        trades += ceil_division(sticks_needed, sticks_gained_per_trade); // gaining required sticks
        trades += k;                                                     // using required sticks to get k coal

        cout << trades << endl;
    }
}

// tc = O(1)
// sc = O(1)