#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    //Convert all odd elements to even
    for(int i = 0; i < n; i++) { // O(n)
        if(a[i] % 2 == 1) {
            a[i] += a[i] % 10;
        }
    }
    
    //Check if all have become equal now
    if(count(a,a+n,a[0]) == n) { // O(n)
        cout << "YES\n";
        return;
    }
    
    //If we have any zero, but elements are still unequal then print NO
    for(int i = 0; i < n; i++) { // O(n)
        if(a[i] % 10 == 0) {
            cout << "NO\n";
            return;
        }
    }
    
    //Make all units digit same, and check the numbers modulo 20
    for(int i = 0; i < n; i++) { //O(n)
        while(a[i] % 10 != 2) {
            a[i] += a[i] % 10;
        }
        a[i] %= 20;
    }
    
    if(count(a,a+n,a[0]) == n) { // O(n)
        cout << "YES\n";
        return;
    }
    else{
        cout << "NO\n";
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        solve();
    }
}

// TC: O(n)
// SC: O(1)