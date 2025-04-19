#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        n--;
        long long msb = log2(n); // log2
        vector<long long> ans;
        long long num = pow(2, msb) - 1;
        while (num >= 0) // n
        {
            ans.push_back(num);
            num--;
        }
        num = pow(2, msb);
        while (num <= n) // n
        {
            ans.push_back(num);
            num++;
        }

        for (auto it : ans) // n
            cout << it << " ";
        cout << endl;
    }
}

// tc = O(n) = O(2*10^5)
// sc = O(n) = O(2*10^5)