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
        for (int i = 0; i < n; i++) // Loop to input the elements of the array
            cin >> a[i];
        // Inputs are read into the array

        long long count_of_odd = 0; // Variable to count the number of odd elements
        for (int i = 0; i < n; i++) // Loop to count odd elements in the array
        {
            if (a[i] % 2 == 1) // Check if the element is odd
                count_of_odd++; // Increment the count if the element is odd
        }
        
        // Check if the count of odd numbers is odd
        if (count_of_odd % 2 == 1)
            cout << "NO" << endl; // If odd, output "NO"
        else
            cout << "YES" << endl; // If even, output "YES"
    }
    return 0;
}

/*
Time Complexity (TC): O(n) = O(50)
Space Complexity (SC): O(n) = O(50)
*/
