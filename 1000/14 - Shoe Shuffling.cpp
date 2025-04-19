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
        vector<long long> sizes(n);
        for (int i = 0; i < n; i++) // n
            cin >> sizes[i];

        map<long long, long long> freq;
        for (int i = 0; i < n; i++) // n
            freq[sizes[i]]++;       // logn

        long long flag = 0;
        for (auto i : freq)
        {
            if (i.second == 1)
            {
                flag = 1;
                break;
            }
        }

        if (flag)
        {
            cout << -1 << endl;
            continue;
        }

        vector<long long> students(n);
        for (int i = 0; i < n; i++) // n
            students[i] = i + 1;

        long long l = 0, r = 0;
        while (r < n) // n
        {
            if (sizes[l] == sizes[r])
                r++;
            else
            {
                rotate(students.begin() + l, students.begin() + l + 1, students.begin() + r);
                l = r;
            }
        }
        rotate(students.begin() + l, students.begin() + l + 1, students.begin() + r);

        for (auto i : students)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

// tc = O(nlogn) = O(10^5*log2(10^5)) = O(10^5*17) = O(10^6)
// sc = O(n) = O(10^5)