#include <bits/stdc++.h>

using namespace std;

long long p2[19];
long long p5[19];

void solve() {
    int n,m;
    cin >> n >> m;

    int c2 = 0, c5 = 0;

    int temp = n;
    while(temp % 2 == 0) {
        c2++;
        temp /= 2;
    }

    temp = n;
    while(temp % 5 == 0) {
        c5++;
        temp /= 5;
    }

    for(int dig = 18; dig >= 0; dig--) {
        int extra2 = max(0, dig - c2);
        int extra5 = max(0, dig - c5);

        if(p2[extra2] * p5[extra5] <= m) {
            int largestK = m - m % (p2[extra2] * p5[extra5]);
            cout << 1LL* largestK * n << '\n';
            return;
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    p2[0] = 1;
    p5[0] = 1;

    for(int i = 1; i <= 18; i++) {
        p2[i] = 2 * p2[i-1];
        p5[i] = 5 * p5[i-1];
    }

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}