#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int count = 0;
    for (int y = B; y <= C; y++)
    {
        int l,r;
        // Case - 1 Skipping as count will be 0
        // Case - 2
        l = max(A, C - y);
        r = min(B, D - y);
        if (l <= r)
            count += (r - l + 1) * (y - C) + (r * (r + 1) / 2 - l * (l - 1) / 2);

        // Case - 3
        l = max(A, D - y + 1);
        r = B;
        if (l <= r)
            count += (r - l + 1) * (D - C + 1);
    }
    cout << count << endl;
    return 0;
}

/*
TC: O(C - B)
SC: O(1).
*/