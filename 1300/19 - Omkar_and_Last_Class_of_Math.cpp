#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int f = 0;
        for(int i = 2; i*i <= n; i++) { //O(sqrt(n))
            if(n % i == 0) {
                int k = n / i;
                cout << k << " "<< n-k << endl;
                f = 1;
                break;
            }
        }
        if(f == 0) {
            cout << 1 << " " << n-1 << endl;
        }
    }
}

// TC :O(t*sqrt(n))
// SC :O(1)