#include <bits/stdc++.h>
using namespace std;

int min_operations(string n, string possible_value)
{
    int operations = 0;
    int checker_index = possible_value.size() - 1; // 1
    for (int i = n.size() - 1; i >= 0; i--) // 20
    {
        if (n[i] == possible_value[checker_index])
        {
            checker_index--;
            if (checker_index < 0)
                break;
        }
        else
            operations++;
    }
    if (checker_index >= 0)
        operations = INT_MAX;
    return operations;
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        string n;
        cin >> n;
        vector<string> possible_values = {"00", "25", "50", "75"};
        int ans = INT_MAX;
        for (auto possible_value : possible_values) // 4
            ans = min(ans, min_operations(n, possible_value));
        cout << ans << endl;
    }
    return 0;
}

// tc - O(4*20) = O(80)
// sc - O(20)