#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) // n
        cin >> a[i];
    // input

    long long minimum_operations = INT_MAX;
    for (int i = 0; i < n; i++) // n
        minimum_operations = min(minimum_operations, abs(a[i]));
    
    cout << minimum_operations << endl;
    return 0;
}

// tc - O(n)
// sc - O(n)