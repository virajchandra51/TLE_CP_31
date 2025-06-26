#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        long long n; // Length of the array for the current test case
        cin >> n;
        long long a[n]; // Array to store the elements
        for (int i = 0; i < n; i++) // Input the elements of the array
            cin >> a[i];
        
        // Map to store the frequency of each element in the array
        map<long long, long long> frequency_map;
        for (int i = 0; i < n; i++) // Calculate the frequency of each element
            frequency_map[a[i]]++;
        
        // Check the number of distinct elements in the array
        if (frequency_map.size() >= 3) // If there are 3 or more distinct elements
        {
            cout << "No" << endl; // It's not possible to make the array good
        }
        else
        {
            // Get the frequency of the smallest and largest elements
            long long freq_1 = frequency_map.begin()->second;
            long long freq_2 = frequency_map.rbegin()->second;
            
            // Check if the array can be made good
            if (freq_1 == freq_2) // If both frequencies are equal
                cout << "Yes" << endl; // The array can be made good
            else if (n % 2 == 1 && abs(freq_1 - freq_2) == 1) // If the array length is odd and the frequency difference is 1
                cout << "Yes" << endl; // The array can be made good
            else
                cout << "No" << endl; // Otherwise, it's not possible
        }
    }
    return 0;
}

// Time Complexity (TC): O(nlog2n) = O(100*log2(100)) = O(100*7) = O(700)
// Space Complexity (SC): O(n+n) = O(2n) = O(n) = O(100)
