#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        string s;
        cin>>s;

        int count0 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') count0++;
        } //? O(N)

        if((count0 % 2 == 0) or (count0 == 1)) {
            cout<<"BOB\n";
        }
        else {
            cout<<"ALICE\n";
        }   
    }

    return 0;
}
//! Total time complexity : O(t * N)
//! Total space complexity : O(t * N)