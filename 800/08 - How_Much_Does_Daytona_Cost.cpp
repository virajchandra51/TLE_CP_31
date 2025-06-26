#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t; // Read the number of test cases
    while (t--)
    {
        long long n, k;
        cin >> n >> k; // Read the size of the array and the integer k
        long long a[n];
        for (int i = 0; i < n; i++) // Loop to read the array elements
            cin >> a[i];
        // Input array elements

        long long number_is_present = 0; // Flag to check if k is present in the array
        for (int i = 0; i < n; i++) // Loop through the array
        {
            if (a[i] == k) // Check if the current element is equal to k
            {
                number_is_present = 1; // Set flag to true if k is found
                break; // Exit the loop as we found k
            }
        }

        if (number_is_present) // If k is present in the array
            cout << "YES" << endl; // Output YES
        else
            cout << "NO" << endl; // Output NO
    }
    return 0;
}

/*
Time Complexity (TC): O(n) = O(100)
Space Complexity (SC): O(n)
*/
