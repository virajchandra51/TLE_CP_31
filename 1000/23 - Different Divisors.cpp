#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long> primes;
    for (long long i = 2; i <= 100000; i++) // O(10^5)
    {
        bool is_prime = true;
        for (long long j = 2; j * j <= i; j++) // O(sqrt(10^5)) = O(10^2)
        {
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            primes.push_back(i);
    }
    // O(10^5 * 10^2) = O(10^7)
    
    int t;
    cin >> t;

    while (t--) // O(3000)
    {
        long long d;
        cin >> d;

        long long p = -1;
        for (long long i = 0; i < primes.size(); i++) // O(9000)
        {
            if (primes[i] >= (1 + d))
            {
                p = primes[i];
                break;
            }
        }
        long long q = -1;
        for (long long i = 0; i < primes.size(); i++) // O(9000)
        {
            if (primes[i] >= (p + d))
            {
                q = primes[i];
                break;
            }
        }

        long long a = min(1LL * p * p * p, 1LL * p * q);
        cout << a << endl;
    }
}

// tc - O(10^7) + O(3000 * 9000) = O(10^7) + O(3 * 10^7) = O(10^7)
// sc - O(10^4) 