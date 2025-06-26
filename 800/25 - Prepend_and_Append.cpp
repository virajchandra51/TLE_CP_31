#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        long long n; // Length of Timur's final string
        cin >> n;
        string s; // Timur's final binary string
        cin >> s;
        // Initialize the answer to the length of the final string
        long long ans = n;
        // Initialize pointers to the start and end of the string
        long long left = 0, right = n - 1;
        // Iterate while the left pointer is less than or equal to the right pointer
        while (left <= right) // Loop runs at most n times
        {
            // If characters at the current pointers are different
            if (s[left] != s[right])
                ans -= 2; // Reduce the answer by 2 as these characters can be removed
            else
                break; // Stop if characters are the same
            left++; // Move the left pointer to the right
            right--; // Move the right pointer to the left
        }
        // Output the shortest possible length of the original string
        cout << ans << endl;
    }
    return 0;
}

// Time Complexity (TC): O(n) = O(2000)
// Space Complexity (SC): O(n) = O(2000)
