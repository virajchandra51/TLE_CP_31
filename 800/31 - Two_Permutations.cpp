#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t; // Read the number of test cases
    while (t--)
    {
        long long n, a, b;
        cin >> n >> a >> b; // Read the values of n, a, and b for each test case
        
        // Check if the sum of a and b plus 2 is less than or equal to n
        // or if both a and b are equal to n
        // If either condition is true, it is possible to form the permutations
        if (a + b + 2 <= n || (a == b && a == n)) // 1
            cout << "Yes" << endl; // Output "Yes" if the permutations can be formed
        else
            cout << "No" << endl; // Output "No" if the permutations cannot be formed
    }
    return 0;
}

// Time Complexity (TC): O(1)
// Space Complexity (SC): O(1)
