#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n,x,y;
    cin >> n >> x >> y;
    long long a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int numOdds = 0;
    for(int i = 0; i < n; i++) { //O(n)
        if(a[i] % 2 == 1) {
            numOdds++;
        }
    }

    int aliceStart, bobStart;
    aliceStart = x % 2;
    bobStart = 1 - aliceStart;

    int aliceEnd, bobEnd;

    if(numOdds % 2 == 0) {
        aliceEnd = aliceStart;
        bobEnd = bobStart;
    }
    else{
        aliceEnd = 1 - aliceStart;
        bobEnd = 1 - bobStart;
    }

    if(y % 2 == aliceEnd) {
        cout << "Alice\n";
    }
    else{
        cout << "Bob\n";
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

// TC: O(n);
// SC: O(1);