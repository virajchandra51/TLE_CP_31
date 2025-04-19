#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        string a, b;
        cin>>a>>b;

        vector<bool> canFlip(n);

        int count0 = 0, count1 = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == '0') {
                count0++;
            }
            else {
                count1++;
            }

            if(count0 == count1) canFlip[i] = true;
        } //? O(N)

        bool isFlipped = false;
        bool isPoss = true;

        for(int i = n-1; i >= 0; i--) {
            if(isFlipped == false) {
                if(a[i] != b[i]) {
                    if(canFlip[i]) {
                        isFlipped ^= true;
                    }
                    else {
                        isPoss = false;
                        break;
                    }
                }
            }
            else {
                if(a[i] == b[i]) {
                    if(canFlip[i]) {
                        isFlipped ^= true;
                    }
                    else {
                        isPoss = false;
                        break;
                    }
                }
            }
        } //? O(N)

        if(isPoss) {
            cout<<"YES\n";   
        }
        else {
            cout<<"NO\n";
        }      
    }

    return 0;
}

//! Total time complexity : O(N)
//! Total space complexity : O(N)