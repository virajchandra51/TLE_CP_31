#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        long long n; // Length of the array
        cin >> n;
        long long a[n]; // Array to store the elements
        for (int i = 0; i < n; i++) // Loop to input array elements
            cin >> a[i];
        // Inputs are read into the array

        long long total_xor = 0; // Variable to store the XOR of all elements
        for (int i = 0; i < n; i++) // Loop to calculate XOR of all elements
            total_xor ^= a[i]; // XOR operation
        // XOR of all elements in the array is calculated

        if (n % 2 == 1) // Check if the number of elements is odd
        {
            cout << total_xor << endl; // Output the XOR if n is odd
        }
        else // If the number of elements is even
        {
            if (total_xor == 0) // Check if the total XOR is zero
                cout << total_xor << endl; // Output zero if total XOR is zero
            else
                cout << -1 << endl; // Output -1 if total XOR is not zero
        }
    }
    return 0;
}

// Time Complexity (TC): O(n) = O(1000)
// Space Complexity (SC): O(n) = O(1000)
