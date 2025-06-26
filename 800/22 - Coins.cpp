#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Declare an integer t to store the number of test cases
    cin >> t; // Read the number of test cases from standard input
    while (t--) // Loop through each test case
    {
        long long n, k; // Declare two long long integers n and k to store the values for each test case
        cin >> n >> k; // Read the values of n and k from standard input
        // Check if n is even or if (n - k) is even
        // If either condition is true, it is possible to represent n using the coins
        if (n % 2 == 0 || (n - k) % 2 == 0) // we took y = 0 or y = 1
            cout << "YES" << endl; // Output "YES" if it is possible to represent n
        else
            cout << "NO" << endl; // Output "NO" if it is not possible to represent n
    }
    return 0; // Return 0 to indicate successful execution
}

// Time Complexity (TC): O(1)
// Space Complexity (SC): O(1)
