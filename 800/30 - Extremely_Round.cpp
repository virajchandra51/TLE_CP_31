#include <bits/stdc++.h>
using namespace std;

bool check(long long x) // 999999
{
    long long count_of_digits = 0;
    long long count_of_zeroes = 0;
    while (x) // 6
    {
        if (x % 10 == 0)
            count_of_zeroes++;
        count_of_digits++;
        x /= 10;
    }
    return count_of_zeroes == count_of_digits - 1;
} // O(6)

int main()
{
    // precomputing all the round numbers
    vector<long long> round_numbers;
    for (long long i = 1; i <= 999999; i++) // O(999999 * 6)
    {
        if (check(i) == true)
            round_numbers.push_back(i);
    }

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        // input

        long long answer = 0;
        for (int i = 0; i < round_numbers.size(); i++) // 54
        {
            if (round_numbers[i] <= n)
                answer++;
            else
                break;
        }
        cout << answer << endl;
    }
    return 0;
}

// tc per testcase - O(54)
// tc - O(999999 * 6 + 54*10^4) ~ O(10^6)
// sc - O(54)