#include <bits/stdc++.h>
using namespace std;

bool isFair(long long n)
{
    long long num = n;
    while (num != 0)
    {
        int x = num % 10;
        if (x != 0 && n % x != 0)
        {
            return false;
        }
        num /= 10;
    }
    return true;
} // O(18)

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        while (!isFair(n)) // O(2520)
            n += 1;
        cout << n << endl;
    }
}

// Time Complexity: O(2520 * 18) = O(45360) ~ O(10^5)
// Space Complexity: O(1)